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
  //Intake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intakeMotorSetting = 1;
    }

    if (intakeMotorSetting == 1) {
      hatch.retract();
      bottom.move(motorVelocity(100));
      top.move(motorVelocity(100));
    }

  //Outtake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
      hatch.retract();
      bottom.move(motorVelocity(-100));
      top.move(motorVelocity(-100));
    }

  //Stop
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      intakeMotorSetting = 7;
    }

    if (intakeMotorSetting == 7) {
      hatch.retract();
      bottom.brake();
      top.brake();
    }
}


void pneumaticControls() {
  //Thingy
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    thingy.retract();
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    thingy.extend();
  }

  //Lid / Descore
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    lid.toggle();
  }

  //Hatch
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
    hatch.toggle();
  }
}