#include "api.h"
#include "lemlib/api.hpp"

//Controllers
  extern pros::Controller master;

//Drivetrain Motors
  extern pros::MotorGroup Right;
  extern pros::MotorGroup Left;

//Motors
  extern pros::Motor Bottom;
  extern pros::Motor Middle;
  extern pros::Motor Top;

//Pneumatics
  extern pros::adi::Pneumatics PlateArm;
  extern pros::adi::Pneumatics BottomArm;
  extern pros::adi::Pneumatics TopArm;
  extern pros::adi::Pneumatics Outblock;
  extern pros::adi::Pneumatics Downblock;

//Sensors
  extern pros::Imu Imu;

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