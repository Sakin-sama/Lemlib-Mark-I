#include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"

ASSET(redleft_txt);

std::string rightColor;

void halfLeft() {
  //Setup
  plateArms.retract();
  hatch.retract();
  lid.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(-48,14,90);
  //Execution
  Bottom.move(motorVelocity(100));
  Top.move(motorVelocity(-100));
  motorControls();
  chassis.moveToPoint(-22,26, 1500);
  pros::delay(1000);
  plateArms.extend();
  chassis.turnToHeading(133,1000);
  chassis.moveToPoint(-10, 13.5, 4000);
  pros::delay(1000);
  Top.move(motorVelocity(100));
  plateArms.retract();
  hatch.extend();
  pros::delay(3000);
  chassis.moveToPoint(-48, 50, 500, {.forwards = false});
  chassis.turnToHeading(325, 750);
  hatch.retract();
  chassis.moveToPoint(-48, 50, 1000, {}, false);
  plateArms.extend();
  chassis.turnToHeading(-92,750);
  chassis.moveToPoint(-62, 48, 1500);
  chassis.moveToPoint(-18, 48, 5000, {.forwards = false});
  pros::delay(1750);
  lid.retract();
}

void halfRight() {
  //Setup
  plateArms.retract();
  hatch.retract();
  lid.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(-48,-14,90);
  //Execution
  Bottom.move(motorVelocity(100));
  Top.move(motorVelocity(-100));
  motorControls();
  chassis.moveToPoint(-21,-24, 1500);
  pros::delay(750);
  plateArms.extend();
  chassis.turnToHeading(50,1000, {}, false);
  plateArms.retract();
  chassis.moveToPoint(-9, -12.5, 4000);
  pros::delay(1500);
  Bottom.move(motorVelocity(-100));
  pros::delay(2500);
  Bottom.move(motorVelocity(100));
  Top.move(motorVelocity(100));
  chassis.moveToPoint(-48, -50, 500, {.forwards = false});
  chassis.turnToHeading(-136, 750);
  chassis.moveToPoint(-48, -46, 1000, {}, false);
  plateArms.extend();
  chassis.turnToHeading(-86,750);
  chassis.moveToPoint(-60, -47, 1000);
  chassis.moveToPoint(-55, -47, 1000, {.forwards = false});
  chassis.moveToPoint(-60,-47, 1000);
  chassis.moveToPoint(0, -45, 5000, {.forwards = false});
  pros::delay(1750);
  lid.retract();
}

void fullLeft() {
  //Setup
  // PlateArm.retract();
  // Outblock.retract();
  // BottomArm.retract();
  // TopArm.retract();
  // Downblock.extend();

}

void fullRight() {
  //Setup
  // PlateArm.retract();
  // Outblock.retract();
  // BottomArm.retract();
  // TopArm.retract();
  // Downblock.extend();

}

void testingPID() {
  //Setup
  // PlateArm.retract();
  // Outblock.retract();
  // BottomArm.retract();
  // TopArm.retract();
  // Downblock.extend();
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(0,0,0);
  //Execution
    //Angular PID Test
      // chassis.turnToHeading(90, 5000);
      // chassis.turnToHeading(180, 5000);
      // chassis.turnToHeading(270, 5000);
      // chassis.turnToHeading(360, 5000);
    //Lateral PID Test
      //chassis.moveToPoint(0,24,5000);
      //chassis.moveToPoint(0,0, 5000, {.forwards = false});
    //Full PID Test
      // chassis.moveToPoint(24,0,5000);
      // chassis.moveToPoint(24,24,5000);
      // chassis.moveToPoint(0,24,5000);
      // chassis.moveToPoint(0,0,5000);
}