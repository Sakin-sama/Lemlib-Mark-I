 #include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"
<<<<<<< HEAD

std::string rightColor;
=======

std::string rightColor;

void leftRed() {

}

void leftBlue() {
  //Setup
  PlateArm.retract();
  Outblock.retract();
  Downblock.extend();
  chassis.setPose(0,0,0);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST); //Change back
  //Execution

}

void rightRed() {

}

void rightBlue() {
>>>>>>> origin/S-bot-two

void testingPID() {
  //Setup
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(0,0,0);
  //Execution
    //Angular PID Test
      chassis.turnToHeading(90, 5000);
      chassis.turnToHeading(180, 5000);
      chassis.turnToHeading(270, 5000);
      chassis.turnToHeading(360, 5000);
    //Lateral PID Test
      //chassis.moveToPoint(0,24,5000);
      //chassis.moveToPoint(0,0, 5000, {.forwards = false});
    //Full PID Test
      // chassis.moveToPoint(24,0,5000);
      // chassis.moveToPoint(24,24,5000);
      // chassis.moveToPoint(0,24,5000);
      // chassis.moveToPoint(0,0,5000);
}