#include "api.h"
#include "lemlib/api.hpp"

//Controllers
  extern pros::Controller master;

//Drivetrain Motors
  extern pros::MotorGroup left;
  extern pros::MotorGroup right;

//Motors
// Positive = intake, negative = outtake
  extern pros::Motor bottom;
  extern pros::Motor top; 

//Pneumatics
  extern pros::adi::Pneumatics hatch;
  extern pros::adi::Pneumatics lid; //ALSO DESCORE
  extern pros::adi::Pneumatics plateArms;
 
//Sensors
  extern pros::Imu imu;

//Distance Sensors
  // extern pros::Distance left(11);
  // extern pros::Distance right(12);
  // extern pros::Distance front(19);
  // extern pros::Distance back(20);

//Tracking Wheel
  extern pros::Rotation vertical_encoder;
  extern lemlib::TrackingWheel vertical_tracking_wheel;

//Odom
  extern lemlib::OdomSensors Sensors;

//Drivetrain
  extern lemlib::Drivetrain Drivetrain;

//PID
  extern lemlib::ControllerSettings LateralController;
  extern lemlib::ControllerSettings AngularController;

//Input Curves
  extern lemlib::ExpoDriveCurve ThrottleCurve;
  extern lemlib::ExpoDriveCurve SteerCurve;

//Chassis
  extern lemlib::Chassis chassis;