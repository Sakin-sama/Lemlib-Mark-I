 #include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"

void fullRight() {
  //Setup
    bottomPiston.extend();
    topPiston.retract();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(51,10,180);
  //Execution
    //First matchload
      bottomIntake.move(motorVelocity(100));
      topIntake.move(motorVelocity(-100));
      chassis.moveToPose(48, 48, 180, 3000, {.forwards = false});
      chassis.turnToHeading(270, 1000, {}, false);
      bottomPiston.retract();
      chassis.moveToPoint(57,48,2000, {.forwards = false, .maxSpeed = 50});
      chassis.moveToPoint(68, 48, 2000, {.forwards = false});
      chassis.moveToPoint(65,48,1000);
      chassis.moveToPoint(68,48,1000, {.forwards = false});
      chassis.moveToPoint(59, 48, 2000, {.maxSpeed = 50}, false);
      bottomPiston.extend();
    //Score matchload
      chassis.moveToPoint(48, 48, 2500);
      chassis.turnToHeading(90, 2500);
      topPiston.extend();
      chassis.moveToPoint(0, 48, 5000, {.forwards = false, .maxSpeed = 50});
      pros::delay(1000);
      agitator.move(motorVelocity(100));
      flywheel.move(motorVelocity(100));
      splitter.move(motorVelocity(100));
      indexer.move(motorVelocity(50));
      pros::delay(7500);
      chassis.moveToPoint(48,48,2000);
      chassis.turnToHeading(-25,2000);
}

void testingPID() {
  //Setup
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(0,0,0);
  //Execution
    //Angular PID Test
      // chassis.turnToHeading(90, 5000);
      // chassis.turnToHeading(180, 5000);
      // chassis.turnToHeading(270, 5000);
      // chassis.turnToHeading(360, 5000);
    //Lateral PID Test
      // chassis.moveToPoint(0,24,5000);
      // chassis.moveToPoint(0,0, 5000, {.forwards = false});
    //Full PID Test
      // chassis.moveToPoint(0,24,5000);
      // chassis.turnToHeading(90, 3000);
      // chassis.moveToPoint(24,24,5000);
      // chassis.turnToHeading(180,3000);
      // chassis.moveToPoint(24,0,5000);
      // chassis.turnToHeading(270,3000);
      // chassis.moveToPoint(0,0,5000);
}