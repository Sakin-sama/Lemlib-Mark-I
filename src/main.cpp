#include "main.h"


/*

COMMIT TESTING CODE TO DEVELOP BEFORE MASTER


move to a branch:
git checkout [branch name]


Save code to current branch:
git add .
git commit -m "[Commit name]"
git push origin [Current branch]


Send code to another branch:
git checkout [Receiving branch]
git merge [Sending branch]


Create new branch:
git checkout -b [New branch name]
git push origin [Branch name]

*/



/*

Color Sorting only happens on top score. And it happens on the outtake level, not the intake level. Thus, color sorting should be called in topBlockExport, not intake, for the S-Bot.
It works by switching from topExport to midExport when the color sensing recognizes the wrong color.

*/


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
        }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	while (autonSelected == false) {
		if (autonSelector == 1) {
			pros::lcd::print(5, "Left red      ");
		} else if (autonSelector ==2 ) {
			pros::lcd::print(5, "Right red     ");
		} else if (autonSelector == 3) {
			pros::lcd::print(5, "Left blue     ");
		} else if (autonSelector == 4){
			pros::lcd::print(5, "Right blue    ");
		} else {
			pros::lcd::print(5, "不死          ");
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			if (autonSelector > 1) {
				autonSelector -= 1;
			} else {
				autonSelector = 4;
			}
		}
		if (master.get_digital_new_release(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			if (autonSelector < 4) {
				autonSelector += 1;
			} else {
				autonSelector = 1;
			}
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
			autonSelected = true;
		}
		pros::delay(25);
	}
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	if (autonSelector == 1) {
		leftRed();
	} else if (autonSelector == 2) {
		rightRed();
	} else if (autonSelector == 3) {
		leftBlue();
	} else if (autonSelector == 4) {
		rightBlue();
	} else {
		pros::lcd::print(5, "No autonomous found     ");
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	while (true) {
  
		
		// get left y and right y positions
			int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
			int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

			// move the robot
			chassis.arcade(leftY, rightX, false, 0.75);

			intakeControls();
    	mandibleControls();
			
			// delay to save resources
			pros::delay(25);
	} //while true
} //opcontrol  