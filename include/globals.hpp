#pragma once

#include "api.h"
#include "lemlib/api.hpp"
#include "pros/optical.hpp"

//Controller
    extern pros::Controller master;

//Motors
    //Intake/Outake motors
        extern pros::Motor LeftMandible; //5.5, needs limit
        extern pros::Motor RightMandible; //5.5, needs limit
        extern pros::Motor TopBack;
        extern pros::Motor TopOut; //5.5, needs limit
        extern pros::Motor BottomBack; //5.5, needs limit
        extern pros::Motor BottomOut;
    //Drivetrain motors
				extern pros::Motor FrontLeftMotor;
				extern pros::Motor BackLeftMotor;
				extern pros::Motor FrontRightMotor;
				extern pros::Motor BackRightMotor;

//Pneumatics
    //"Mandibles"
        extern pros::adi::Pneumatics LeftMandiblePnuematic;
        extern pros::adi::Pneumatics RightMandiblePnuematic;

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