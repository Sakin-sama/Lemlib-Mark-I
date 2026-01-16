#include "helpers.hpp"

//Variables
int intakeMotorSetting = 0;
int intakeMotorSettingLast = 0;

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
      hatch.retract();
      lid.retract();
      bottom.move(motorVelocity(100));
      top.move(motorVelocity(100));
    }

  //Bottom block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
      hatch.retract();
      lid.retract();
      bottom.move(motorVelocity(-100));
      top.move(motorVelocity(-100));
    }

  //Middle block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intakeMotorSetting = 3;
    }

    if (intakeMotorSetting == 3 ) {
      hatch.extend();
      lid.retract();
      bottom.move(motorVelocity(100));
      top.move(motorVelocity(100));
    }

  //Top block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intakeMotorSetting = 4;
    }

    if (intakeMotorSetting == 4) {
      hatch.retract();
      lid.extend();
      bottom.move(motorVelocity(100));
      top.move(motorVelocity(100));
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

  //Stops all motors
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      intakeMotorSetting = 7;
    }

    if (intakeMotorSetting == 7) {
      hatch.retract();
      lid.retract();
      bottom.brake();
      top.brake();
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

void pneumaticControls() {
  //fork
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    fork.retract();
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    fork.extend();
  }

  //descore
0
}