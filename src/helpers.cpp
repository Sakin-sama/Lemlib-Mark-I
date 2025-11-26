#include "helpers.hpp"
#include "pros/misc.h"

int intakeMotorSetting = 0;
int intakeMotorSettingLast = 0;

//Takes a velocity percentage and outputs in the voltage format
double motorVelocity(int givenVelocity) {
  return (std::min(((givenVelocity * 127) / 100), 100));
}

//Controls the individual intake functions and what they do
void intakeControls() {
    //Intakes blocks
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intakeMotorSetting = 1;
    }

    if (intakeMotorSetting == 1) {
      Outblock.retract();
      Downblock.extend();
      Bottom.move(motorVelocity(75));
      Middle.move(motorVelocity(75));
      Top.brake();
    }

    //Bottom block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intakeMotorSetting = 2;
    }

    if (intakeMotorSetting == 2) {
      Outblock.retract();
      Downblock.extend();
      Bottom.move(motorVelocity(-75));
      Middle.move(motorVelocity(-75));
      Top.move(motorVelocity(-75));
    }

    //Middle block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeMotorSetting = 3;
    }

    if (intakeMotorSetting == 3 ) {
      Outblock.extend();
      Downblock.retract();
      Bottom.move(motorVelocity(75));
      Middle.move(motorVelocity(75));
      Top.move(motorVelocity(-75));
    }

    //Top block export
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intakeMotorSetting = 4;
    }

    if (intakeMotorSetting == 4) {
      Outblock.extend();
      Downblock.retract();
      Bottom.move(motorVelocity(75));
      Middle.move(motorVelocity(75));
      Top.move(motorVelocity(75));
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

    //Stops all intakes
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        intakeMotorSetting = 7;
    }

    if (intakeMotorSetting == 7) {
      Bottom.brake();
      Middle.brake();
      Top.brake();
    }
}

//Controls the color sorting method of the intake
void colorSorting(std::string goodColor) {
    if (goodColor == "Red") {
        //Red = good
        if (BlockColorSensor.get_hue() >= 200 && BlockColorSensor.get_hue() <= 240) {

        }
    } if (goodColor == "Blue") {
        //Blue = good
        if (BlockColorSensor.get_hue() >= 340 && BlockColorSensor.get_hue() <= 360) {

        }
    }
}

//Controls the mandibles and their pneumatics
void plateControls() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        RightPlateArm.retract();
        LeftPlateArm.retract();
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        RightPlateArm.extend();
        LeftPlateArm.extend();
    }
}