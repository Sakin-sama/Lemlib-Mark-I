#include "autonSettings.hpp"

//variables
  int selectedAuton = 2;
  bool autonSelected = false;

//Auton selection/execution
  void autonSelector() {
  selectedAuton = 1;
  autonSelected = false;
  while (autonSelected == false) {
		if (selectedAuton == 1) {
			pros::lcd::print(5, "Half left      ");
		} else if (selectedAuton ==2 ) {
			pros::lcd::print(5, "Half right     ");
		} else if (selectedAuton == 3) {
			pros::lcd::print(5, "Full left      ");
		} else if (selectedAuton == 4){
			pros::lcd::print(5, "Full right     ");
		} else {
			pros::lcd::print(5, "None           ");
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
			if (selectedAuton > 1) {
				selectedAuton = selectedAuton - 1;
			} else {
				selectedAuton = 5;
			}
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
			if (selectedAuton < 5) {
				selectedAuton = selectedAuton + 1;
			} else {
				selectedAuton = 1;
			}
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
			autonSelected = true;
		}
		pros::delay(100);
	}
}

void runSelectedAuton() {
    if (selectedAuton == 1) {
    pros::lcd::print(5, "half left selected! :3      ");
    halfLeft();
  } else if (selectedAuton == 2) {
    pros::lcd::print(5, "half right selected! :3     ");
    halfRight();
  } else if (selectedAuton == 3) {
    pros::lcd::print(5, "full left selected! :3      ");
    fullLeft();
  } else if (selectedAuton == 4) {
    pros::lcd::print(5, "full right selected! :3     ");
    fullRight();
  } else {
    pros::lcd::print(5, "No auton selected :'(       ");
  }
}