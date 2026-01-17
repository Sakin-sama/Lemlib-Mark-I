#include "globals.hpp"

//Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

//Motors
  //Intake/Outake motors
    pros::Motor bottom(7, pros::v5::MotorGears::blue);
    pros::Motor top(6, pros::v5::MotorGears::blue);
  //Drivetrain
    pros::MotorGroup leftDrive({-1,-2,-3}, pros::v5::MotorGears::blue);
    pros::MotorGroup rightDrive({8,9, 10}, pros::v5::MotorGears::blue);

//Pneumatics
  //"Hatch"
        pros::adi::Pneumatics hatch('H', false);
    //"Lid"
        pros::adi::Pneumatics lid('A', false);
    //"Thingy"
        pros::adi::Pneumatics thingy('G', false);


//Sensors
  pros::Imu imu(5);

//Distance Sensors
  // pros::Distance left(11);
  // pros::Distance right(12);
  // pros::Distance front(19);
  // pros::Distance back(20);

//Tracking Wheel
  pros::Rotation vertical_encoder(4);
  lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, -0.5);

// odometry settings
  lemlib::OdomSensors Sensors(
    &vertical_tracking_wheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &imu // inertial sensor
    ); 

//Drivetrain
  lemlib::Drivetrain Drivetrain(
    &leftDrive,
    &rightDrive,
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