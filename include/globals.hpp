#include "api.h"
#include "lemlib/api.hpp"

//Controllers
  extern pros::Controller master;

//Drivetrain Motors
  extern pros::MotorGroup Left;
  extern pros::MotorGroup Right;

//Motors
  extern pros::Motor Bottom;
  extern pros::Motor Top;

//Pneumatics
  extern pros::adi::Pneumatics Hatch;
  extern pros::adi::Pneumatics Lid;
  extern pros::adi::Pneumatics Fork;

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