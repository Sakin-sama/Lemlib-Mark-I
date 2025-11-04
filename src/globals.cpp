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
        pros::Motor LeftMandible(2, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor RightMandible(-9, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor TopBack(3, pros::v5::MotorGears::blue);
        pros::Motor TopOut(8, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor BottomBack(21, pros::v5::MotorGears::green); //5.5, needs limit
        pros::Motor BottomOut(10, pros::v5::MotorGears::blue);
    //Drivetrain motors
				pros::Motor FrontLeftMotor(-11, pros::v5::MotorGears::green);
				pros::Motor BackLeftMotor(-12, pros::v5::MotorGears::green);
				pros::Motor FrontRightMotor(19, pros::v5::MotorGears::green);
				pros::Motor BackRightMotor(20, pros::v5::MotorGears::green);
		
//Pneumatics
    //"Mandibles"
        pros::adi::Pneumatics LeftMandiblePnuematic('A', false);
        pros::adi::Pneumatics RightMandiblePnuematic('B', false);

//Sensors - these are all defaults after the color sensor
    //Color sensors
        pros::Optical BlockColorSensor(1);
    //imu
        pros::Imu Imu(7);
//Odom stuffs
    // horizontal tracking wheel encoder
//        pros::Rotation horizontal_encoder(20);
    // vertical tracking wheel encoder
//        pros::ADIEncoder vertical_encoder('C', 'D', true);
     // horizontal tracking wheel
//        lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
    // vertical tracking wheel
//        lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);
    

// odometry settings
    lemlib::OdomSensors Sensors(nullptr, // vertical tracking wheel 1, set to null
        nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
        nullptr, // horizontal tracking wheel 1
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &Imu
    ); // inertial sensor


//Groups
				pros::MotorGroup LeftMotors({FrontLeftMotor.get_port(), BackLeftMotor.get_port()}); //left drivetrain
				pros::MotorGroup RightMotors({FrontRightMotor.get_port(), BackRightMotor.get_port()}); //right drivetrain
				pros::MotorGroup Mandibles({LeftMandible.get_port(), RightMandible.get_port()}); //Should default to intake

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