#include "globals.hpp"
#include "pros/distance.hpp"

//Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

//Motors
  //Intake/Outake motors
    pros::Motor Bottom(7, pros::v5::MotorGears::blue);
    pros::Motor Top(6, pros::v5::MotorGears::blue);
  //Drivetrain
    pros::MotorGroup Right({8,9,10}, pros::v5::MotorGears::blue);
    pros::MotorGroup Left({-1,-2,-3}, pros::v5::MotorGears::blue);

//Pneumatics
  //"Hatch"
        pros::adi::Pneumatics hatch('H', false);
    //"Lid"
        pros::adi::Pneumatics lid('F', true);
    //"Thingy"
        pros::adi::Pneumatics plateArms('G', false);


//Sensors
  pros::Imu Imu(5);
  pros::Distance left(11);
  pros::Distance right(20);

//Tracking Wheel
  pros::Rotation vertical_encoder(-4);
  lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -0.75);

//Odometry Settings
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
  // angular PID controller
    lemlib::ControllerSettings AngularController(
        2, // proportional gain (kP)
        0, // integral gain (kI)
        10, // derivative gain (kD)
        0, // anti windup
        0, // small error range, in degrees
        0, // small error range timeout, in milliseconds
        0, // large error range, in degrees
        0, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
    );

  // lateral PID controller
    lemlib::ControllerSettings LateralController(
        7, // proportional gain (kP)
        0, // integral gain (kI)
        15, // derivative gain (kD)
        0, // anti windup
        0, // small error range, in inches
        0, // small error range timeout, in milliseconds
        0, // large error range, in inches
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