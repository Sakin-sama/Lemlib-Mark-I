#include "helpers.hpp"
#include "autons.hpp"
//Takes a velocity percentage and outputs in the voltage format
double motorVelocity(int givenVelocity) {
  return (std::max(std::min(((givenVelocity * 127) / 100), 127), -127));
}

//Controls the individual intake functions and what they do
void motorControls() {
  //Intakes blocks
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intakeMotorSetting = 1;
    }

    if (intakeMotorSetting == 1) {
      Outblock.retract();
      Downblock.extend();
      Bottom.move(motorVelocity(100));
      Middle.move(motorVelocity(80));
      Top.brake();
    }

  //Bottom block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
      Outblock.retract();
      Downblock.retract();
      Bottom.move(motorVelocity(-100));
      Middle.move(motorVelocity(-80));
      Top.move(motorVelocity(-65));
    }

  //Middle block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intakeMotorSetting = 3;
    }

    if (intakeMotorSetting == 3 ) {
      Outblock.retract();
      Downblock.retract();
      Bottom.move(motorVelocity(100));
      Middle.move(motorVelocity(80));
      Top.move(motorVelocity(-65));
    }

  //Top block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intakeMotorSetting = 4;
    }

    if (intakeMotorSetting == 4) {
      Outblock.extend();
      Downblock.extend();
      Bottom.move(motorVelocity(100));
      Middle.move(motorVelocity(80));
      Top.move(motorVelocity(65));
    }

  //Reverse
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      intakeMotorSettingLast = intakeMotorSetting;
      intakeMotorSetting = 5;
    }

    if (intakeMotorSetting == 5) {
      pros::delay(400);
      intakeMotorSetting = intakeMotorSettingLast;
    }

  //Stops middle motor
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      intakeMotorSetting = 6;
    }

    if (intakeMotorSetting == 6) {
      Middle.brake();
    }

  //Stops all motors
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      intakeMotorSetting = 7;
    }

    if (intakeMotorSetting == 7) {
      Bottom.brake();
      Middle.brake();
      Top.brake();
    }

    //reversi
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      intakeMotorSetting = 8;
    }

    if (intakeMotorSetting == 8) {
      Bottom.move(motorVelocity(-100));
      Middle.move(motorVelocity(-80));
      Top.move(motorVelocity(-65));
    }
}

//Controls the color sorting method of the intake
// void colorSorting(std::string goodColor) {
//   if (goodColor == "Red") {
//     //Red = good
//       if (BlockColorSensor.get_hue() >= 200 && BlockColorSensor.get_hue() <= 240) {

//       }
//   } 
//   if (goodColor == "Blue") {
//     //Blue = good
//       if (BlockColorSensor.get_hue() >= 340 && BlockColorSensor.get_hue() <= 360) {

//       }
//   }
// }

//Controls the mandibles and their pneumatics
void pneumaticControls() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    PlateArm.retract();
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    PlateArm.extend();
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
    TopArm.extend();
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    TopArm.retract();
  }
}

//Auton selection/execution
  void autonSelector() {
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

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
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
    halfLeft();
  } else if (selectedAuton == 2) {
    halfRight();
  } else if (selectedAuton == 3) {
    fullLeft();
  } else if (selectedAuton == 4) {
    fullRight();
  } else {
    pros::lcd::print(5, "No auton selected :'(        ");
  }
}