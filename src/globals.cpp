#include "globals.hpp"

//chassis and master (controller) are LOWERCASE

//Variables
float TRACK_WIDTH = 12.875; //inches
int DRIVETRAIN_RPM = 400; //4:2 gear ratio, 200rpm gearbox (green)
float HORIZONTAL_DRIFT = 2; //needs tuning
int selectedAuton = 1;
bool autonSelected = false;

//Controller
    pros::Controller master(pros::E_CONTROLLER_MASTER);

//Motors
  //Drivetrain
    // pros::MotorGroup Right({0,0,0}, pros::v5::MotorGears::);
    // pros::MotorGroup Left({0,0,0}, pros::v5::MotorGears::);

//Pneumatics

//Sensors
  pros::Imu Imu(0);
  pros::Distance left(0);
  pros::Distance right(0);

//Tracking Wheel
  pros::Rotation vertical_encoder(0);
  lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, 0);

//Odometry Settings
  lemlib::OdomSensors Sensors(
    nullptr, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    nullptr // inertial sensor
    ); 

//Drivetrain
    lemlib::Drivetrain Drivetrain(
        &LeftMotors,
        &RightMotors,
        TRACK_WIDTH, //measure
        lemlib::Omniwheel::NEW_325, //idk if it's new or old 325
        DRIVETRAIN_RPM, //gear ratio  * gear cartridge (200)
        HORIZONTAL_DRIFT //idk
    );

//PID - these are the default constants, need to be callibrated
    // lateral PID controller
        lemlib::ControllerSettings LateralController(10, // proportional gain (kP)
            0, // integral gain (kI)
            3, // derivative gain (kD)
            3, // anti windup
            1, // small error range, in inches
            100, // small error range timeout, in milliseconds
            3, // large error range, in inches
            500, // large error range timeout, in milliseconds
            20 // maximum acceleration (slew)
        );

    // angular PID controller
        lemlib::ControllerSettings AngularController(2, // proportional gain (kP)
            0, // integral gain (kI)
            10, // derivative gain (kD)
            3, // anti windup
            1, // small error range, in degrees
            100, // small error range timeout, in milliseconds
            3, // large error range, in degrees
            500, // large error range timeout, in milliseconds
            0 // maximum acceleration (slew)
        );

//Input Curves
    // input curve for throttle input during driver control
        lemlib::ExpoDriveCurve ThrottleCurve(3, // joystick deadband out of 127
                                            10, // minimum output where drivetrain will move out of 127
                                            1.019 // expo curve gain
        );
    // input curve for steer input during driver control
        lemlib::ExpoDriveCurve SteerCurve(3, // joystick deadband out of 127
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