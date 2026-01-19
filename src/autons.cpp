#include "autons.hpp"
#include "helpers.hpp"


std::string rightColor;

void halfLeft() {
  //Setup
  plateArms.retract();
  hatch.retract();
  lid.extend();
  chassis.setPose(-48,14,90);
  //Execution
  Bottom.move(motorVelocity(100));
  chassis.moveToPoint(-24,22, 5000);
  pros::delay(1000);
  plateArms.extend();
  chassis.moveToPoint(-8.5, 8.5, 5000);
}

void halfRight() {
  //Setup
  // PlateArm.retract();
  // Outblock.retract();
  // BottomArm.retract();
  // TopArm.retract();
  // Downblock.extend();

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