#include "api.h"
#include "lemlib/api.hpp"

//Controllers
  extern pros::Controller master;

//Drivetrain Motors
  extern pros::MotorGroup Right;
  extern pros::MotorGroup Left;

//Motors
  extern pros::Motor Bottom;
  extern pros::Motor Top;

//Pneumatics
  extern pros::adi::Pneumatics hatch;
  extern pros::adi::Pneumatics lid;
  extern pros::adi::Pneumatics plateArms;

//Sensors
  extern pros::Imu Imu;
  extern pros::Distance left;
  extern pros::Distance right;

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