#include "api.h"
#include "lemlib/api.hpp"
#include <sys/_intsup.h>

//Variables
extern int selectedAuton;
extern bool autonSelected;
extern int intakeMotorSetting;
extern int intakeMotorSettingLast;

//Controller
    extern pros::Controller master;

//Motors
  extern  pros::Motor bottomIntake;
  extern  pros::Motor topIntake;
  extern  pros::Motor flywheel;
  extern  pros::Motor agitator;
  extern  pros::Motor indexer;
  extern  pros::Motor splitter;

//Pneumatics
  extern pros::adi::Pneumatics bottomPiston;
  extern pros::adi::Pneumatics topPiston;
  extern pros::adi::Pneumatics descorerPiston;

//Sensors
    //Color sensors
        extern pros::Optical BlockColorSensor;
    //Imu
        extern pros::Imu Imu;
        extern pros::Rotation vertical_encoder;
        extern lemlib::TrackingWheel vertical_tracking_wheel;

    //Odoms
        extern lemlib::OdomSensors Sensors;

//Groups
    extern pros::MotorGroup LeftMotors; //left drivetrain
    extern pros::MotorGroup RightMotors; //right drivetrain

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
