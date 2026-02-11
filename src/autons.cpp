 #include "autons.hpp"
#include "helpers.hpp"
#include "pros/motors.h"

void fullRight() {
  //Setup
    bottomPiston.extend();
    topPiston.retract();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(51,18,180);
  //Execution
    //First matchload
      bottomIntake.move(motorVelocity(100));
      topIntake.move(motorVelocity(-100));
      chassis.moveToPose(48, 48, 180, 3000, {.forwards = false, .earlyExitRange = 0});
      chassis.turnToHeading(-90, 1500, {}, false);
      bottomPiston.retract();
      chassis.moveToPose(57,48,-90,2000, {.forwards = false, .earlyExitRange = 0});
      chassis.moveToPoint(68, 48, 2000, {.forwards = false, .minSpeed = 90, .earlyExitRange = 0});
      chassis.moveToPoint(65,48,1000);
      chassis.moveToPoint(68,48,1000, {.forwards = false});
      chassis.moveToPoint(59, 48, 2000, {.maxSpeed = 50}, false);
      bottomPiston.extend();
    //Score matchload
      chassis.moveToPoint(48, 48, 2500);
      chassis.turnToHeading(91.5, 2500);
      topPiston.extend();
      chassis.moveToPoint(0, 48, 5000, {.forwards = false, .maxSpeed = 50});
      pros::delay(1000);
      bottomIntake.move(motorVelocity(100));
      topIntake.move(motorVelocity(-100));
      agitator.move(motorVelocity(100));
      flywheel.move(motorVelocity(100));
      splitter.move(motorVelocity(100));
      indexer.move(motorVelocity(50));
      topPiston.extend();
      pros::delay(3000);
      chassis.setPose(34,48, 90);
      pros::delay(4500);
      chassis.moveToPoint(48,48,2000);
      chassis.turnToHeading(-25,2000);
      chassis.moveToPoint(62, 30, 2500, {.forwards = false, .maxSpeed = 60});
      chassis.turnToHeading(0, 1000);
      chassis.moveToPoint(65,-10, 4000, {.forwards = false, .minSpeed = 127});
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
      // chassis.moveToPoint(0,-24,5000, {.forwards = false});
      // chassis.moveToPoint(0,0, 5000);
    //Full PID Test
      // chassis.moveToPoint(0,24,5000);
      // chassis.turnToHeading(90, 3000);
      // chassis.moveToPoint(24,24,5000);
      // chassis.turnToHeading(180,3000);
      // chassis.moveToPoint(24,0,5000);
      // chassis.turnToHeading(270,3000);
      // chassis.moveToPoint(0,0,5000);
}