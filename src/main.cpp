#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
int autonSelector = 1;
bool autonSelected = false;


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {
  while (autonSelected == false) {
		if (autonSelector == 1) {
			pros::lcd::print(5, "Half left      ");
		} else if (autonSelector ==2 ) {
			pros::lcd::print(5, "Half right     ");
		} else if (autonSelector == 3) {
			pros::lcd::print(5, "Full left      ");
		} else if (autonSelector == 4){
			pros::lcd::print(5, "Full right     ");
		} else {
			pros::lcd::print(5, "None           ");
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			if (autonSelector > 1) {
				autonSelector = autonSelector - 1;
			} else {
				autonSelector = 5;
			}
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			if (autonSelector < 5) {
				autonSelector = autonSelector + 1;
			} else {
				autonSelector = 1;
			}
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
			autonSelected = true;
		}
		pros::delay(100);
	}
}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
  if (autonSelector == 1) {
    halfLeft();
  } else if (autonSelector == 2) {
    halfRight();
  } else if (autonSelector == 3) {
    fullLeft();
  } else if (autonSelector == 4) {
    fullRight();
  } else {
    pros::lcd::print(5, "No auton selected :'(        ");
  }
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // controller
    // loop to continuously update motors
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    while (true) {
        // get joystick positions
        int leftY = 0.8 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = 0.8 * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive
        chassis.arcade(leftY, rightX);
        // delay to save resources
        pros::delay(10);
    }
}