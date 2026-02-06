#include "api.h"
#include "lemlib/api.hpp"

//Variables
extern int selectedAuton;
extern bool autonSelected;
//Controller
    extern pros::Controller master;

//Motors
<<<<<<< HEAD


//Pneumatics

=======
    //Intake/Outake motors
        extern pros::Motor Bottom;
        extern pros::Motor Middle;
        extern pros::Motor Top;
    //Drivetrain motors
				extern pros::Motor FrontLeftMotor;
        extern pros::Motor MiddleLeftMotor;
				extern pros::Motor BackLeftMotor;
				extern pros::Motor FrontRightMotor;
        extern pros::Motor MiddleRightMotor;
				extern pros::Motor BackRightMotor;

//Pneumatics
    //"Plate"
        extern pros::adi::Pneumatics PlateArm;
    //"Arm"
        extern pros::adi::Pneumatics BottomArm;
        extern pros::adi::Pneumatics TopArm;
    //"Outblock"
        extern pros::adi::Pneumatics Outblock;
    //"Downblock"
        extern pros::adi::Pneumatics Downblock;
>>>>>>> origin/S-bot-two

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
