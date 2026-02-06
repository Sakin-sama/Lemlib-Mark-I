#include "api.h"
#include "lemlib/api.hpp"

//Variables

//Controller
    extern pros::Controller master;

//Motors


//Pneumatics


//Sensors
    //Color sensors
        extern pros::Optical BlockColorSensor;
    //Imu
        extern pros::Imu Imu;
    //Odoms
        extern lemlib::OdomSensors Sensors;

//Groups
    extern pros::MotorGroup LeftMotors; //left drivetrain
    extern pros::MotorGroup RightMotors; //right drivetrain
    extern pros::MotorGroup Mandibles; //Should default to intake

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