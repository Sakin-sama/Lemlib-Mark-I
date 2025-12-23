#include "globals.hpp"

//Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

//Motors
  //Intake/Outake motors
    pros::Motor Bottom(14);
    pros::Motor Middle(16);
    pros::Motor Top(10);
  //Drivetrain
    pros::MotorGroup Right({18,19,20}, pros::v5::MotorGears::blue);
    pros::MotorGroup Left({-11,-12,-13}, pros::v5::MotorGears::blue);

//Pneumatics
  //"Plate"
        pros::adi::Pneumatics PlateArm('F', false);
    //"Arm"
        pros::adi::Pneumatics BottomArm('E', false);
        pros::adi::Pneumatics TopArm('G', false);
    //"Outblock"
        pros::adi::Pneumatics Outblock('D', false);
    //"Downblock"
        pros::adi::Pneumatics Downblock('H', true);


//Sensors
  pros::Imu Imu(21);

//Tracking Wheel
  pros::Rotation vertical_encoder(17);
  lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -0.5);

// odometry settings
  lemlib::OdomSensors Sensors(
    &vertical_tracking_wheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &Imu // inertial sensor
    ); 

//Drivetrain
  lemlib::Drivetrain Drivetrain(
    &Left,
    &Right,
    12.875, //measure
    lemlib::Omniwheel::NEW_325, //idk if it's new or old 325
    450, //gear ratio  * gear cartridge (200)
    8 //idk
  );

//PID - these are the default constants, need to be callibrated
  // lateral PID controller
    lemlib::ControllerSettings LateralController(
        10.5, // proportional gain (kP)
        0, // integral gain (kI)
        55, // derivative gain (kD)
        0, // anti windup
        0, // small error range, in inches
        0, // small error range timeout, in milliseconds
        0, // large error range, in inches
        0, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
    );

  // angular PID controller
    lemlib::ControllerSettings AngularController(
        8, // proportional gain (kP)
        0, // integral gain (kI)
        58.5, // derivative gain (kD)
        0, // anti windup
        0, // small error range, in degrees
        0, // small error range timeout, in milliseconds
        0, // large error range, in degrees
        0, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
    );

//Input Curves
  // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve ThrottleCurve(
      3, // joystick deadband out of 127
      10, // minimum output where drivetrain will move out of 127
      1.019 // expo curve gain
    );
// input curve for steer input during driver control
    lemlib::ExpoDriveCurve SteerCurve
      (3, // joystick deadband out of 127
      10, // minimum output where drivetrain will move out of 127
      1.019 // expo curve gain
      );

//Chassis
  lemlib::Chassis chassis(
    Drivetrain,
    LateralController,
    AngularController,
    Sensors,
    &ThrottleCurve,
    &SteerCurve
  );


