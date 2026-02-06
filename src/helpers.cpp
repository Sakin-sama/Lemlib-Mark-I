#include "helpers.hpp"
#include "pros/misc.h"

//Variables

//Takes a velocity percentage and outputs in the voltage format
double motorVelocity(int givenVelocity) {
  if (abs((givenVelocity * 127) / 100) < 127) {
    return ((givenVelocity * 127) / 100);
  } else {
    if (givenVelocity > 0) {
      return (127);
    } else {
      return (-127);
    }
  }
}

//Controls the individual motors
void motorControls() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    intakeMotorSetting = 1;
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    intakeMotorSetting = 2;
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intakeMotorSetting = 3;
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intakeMotorSetting = 4;
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    intakeMotorSetting = 5;
  } else {
    intakeMotorSetting = 0;
  }



  if (intakeMotorSetting == 1) {
    //Intake
    bottomIntake.move(motorVelocity(100));
    topIntake.move(motorVelocity(-100));
    agitator.move(motorVelocity(-100));
    flywheel.move(motorVelocity(100));
    splitter.brake();
    indexer.brake();
    topPiston.retract();
  } else if (intakeMotorSetting == 2) {
    //High scoring
    bottomIntake.move(motorVelocity(100));
    topIntake.move(motorVelocity(-100));
    agitator.move(motorVelocity(100));
    flywheel.move(motorVelocity(100));
    splitter.move(motorVelocity(100));
    indexer.move(motorVelocity(50));
    topPiston.extend();
  } else if (intakeMotorSetting == 3) {
    //Middle scoring
    bottomIntake.move(motorVelocity(-100));
    topIntake.brake();
    agitator.move(motorVelocity(100));
    flywheel.brake();
    splitter.move(motorVelocity(100));
    indexer.move(motorVelocity(30));
    topPiston.retract();
  } else if (intakeMotorSetting == 4) {
    //Low scoring
    bottomIntake.move(motorVelocity(-100));
    topIntake.brake();
    agitator.move(motorVelocity(100));
    flywheel.brake();
    splitter.move(motorVelocity(100));
    indexer.move(motorVelocity(30));
    topPiston.retract();
  } else if (intakeMotorSetting == 5) {
    //Reverse
    bottomIntake.move(motorVelocity(-100));
    topIntake.move(motorVelocity(100));
    agitator.brake();
    flywheel.move(motorVelocity(-100));
    splitter.move(motorVelocity(100));
    indexer.move(motorVelocity(-65));
    topPiston.retract();
  }  else {
    bottomIntake.brake();
    topIntake.brake();
    agitator.brake();
    flywheel.brake();
    splitter.brake();
    indexer.brake();
  }
}

//Controls pneumatics
void pneumaticControls() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    bottomPiston.extend();
  }
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
    bottomPiston.retract();
  }
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
    descorerPiston.extend();
  }
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    descorerPiston.retract();
  }
}