#include "api.h"
#include "lemlib/api.hpp"

//Variables
extern int selectedAuton;
extern bool autonSelected;
//Controller
    extern pros::Controller master;

//Motors


//Pneumatics


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
