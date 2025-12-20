#include "globals.hpp"

//chassis and master (controller) are LOWERCASE

float TRACK_WIDTH = 12.875; //inches
int DRIVETRAIN_RPM = 400; //4:2 gear ratio, 200rpm gearbox (green)
float HORIZONTAL_DRIFT = 2; //needs tuning

int autonSelector = 1;
bool autonSelected = false;

//Controller
    pros::Controller master(pros::E_CONTROLLER_MASTER);

//Motors
    //Intake/Outake motors
        pros::Motor Bottom(14);
        pros::Motor Middle(1);
        pros::Motor Top(10);
    //Drivetrain motors
				pros::Motor FrontLeftMotor(-13, pros::v5::MotorGears::blue);
        pros::Motor MiddleLeftMotor(-12, pros::v5::MotorGears::blue);
				pros::Motor BackLeftMotor(-11, pros::v5::MotorGears::blue);
				pros::Motor FrontRightMotor(18, pros::v5::MotorGears::blue);
        pros::Motor MiddleRightMotor(19, pros::v5::MotorGears::blue);
				pros::Motor BackRightMotor(20, pros::v5::MotorGears::blue);
		
//Pneumatics
    //"Plate"
        pros::adi::Pneumatics PlateArm('F', false);
    //"Arm"
        pros::adi::Pneumatics BottomArm('E', false);
        pros::adi::Pneumatics TopArm('G', false);
    //"Outblock"
        pros::adi::Pneumatics Outblock('D', false);
    //"Downblock"
        pros::adi::Pneumatics Downblock('H', true);

//Sensors - these are all defaults after the color sensor
    //Color sensors
        pros::Optical BlockColorSensor(1);
    //imu
        pros::Imu Imu(-21);
//Odom stuffs
    // horizontal tracking wheel encoder
        pros::Rotation vertical_encoder(16);
    // vertical tracking wheel encoder
//        pros::ADIEncoder vertical_encoder('C', 'D', true);
     // horizontal tracking wheel
//        lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
    // vertical tracking wheel
        lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, 0);
    

// odometry settings
    lemlib::OdomSensors Sensors(
        nullptr, // vertical tracking wheel 1, set to null
        nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
        nullptr, // horizontal tracking wheel 1
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &Imu
    ); // inertial sensor


//Groups
				pros::MotorGroup RightMotors({FrontLeftMotor.get_port(), MiddleLeftMotor.get_port(), BackLeftMotor.get_port()}); //left drivetrain
				pros::MotorGroup LeftMotors({FrontRightMotor.get_port(), MiddleRightMotor.get_port(), BackRightMotor.get_port()}); //right drivetrain

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
        lemlib::ControllerSettings LateralController(
            15, // proportional gain (kP)
            0, // integral gain (kI)
            7, // derivative gain (kD)
            0, // anti windup
            0, // small error range, in inches
            0, // small error range timeout, in milliseconds
            0, // large error range, in inches
            0, // large error range timeout, in milliseconds
            65 // maximum acceleration (slew)
        );

    // angular PID controller
        lemlib::ControllerSettings AngularController(
            2, // proportional gain (kP)
            0, // integral gain (kI)
            10, // derivative gain (kD)
            0, // anti windup
            0, // small error range, in degrees
            0, // small error range timeout, in milliseconds
            0, // large error range, in degrees
            0, // large error range timeout, in milliseconds
            20 // maximum acceleration (slew)
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



