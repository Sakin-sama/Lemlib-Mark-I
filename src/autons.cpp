#include "autons.hpp"
#include "helpers.hpp"

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
  chassis.moveToPoint(-21.5,-26, 1500);
  pros::delay(750);
  plateArms.extend();
  chassis.turnToHeading(50,1000, {}, false);
  plateArms.retract();
  chassis.moveToPoint(-9.5, -12.5, 4000);
  pros::delay(1500);
  Bottom.move(motorVelocity(-100));
  pros::delay(2500);
  Bottom.move(motorVelocity(100));
  Top.move(motorVelocity(100));
  chassis.moveToPoint(-48, -50, 500, {.forwards = false});
  chassis.turnToHeading(-136, 750);
  chassis.moveToPoint(-48, -45, 1000, {}, false);
  plateArms.extend();
  chassis.turnToHeading(-86,750);
  chassis.moveToPoint(-60, -46, 1000);
  chassis.moveToPoint(-52.5, -46, 1000, {.forwards = false});
  chassis.moveToPoint(-60,-46, 1000);
  chassis.moveToPoint(-20, -47.5, 5000, {.forwards = false});
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
    plateArms.retract();
    hatch.retract();
    lid.extend();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-49,-14,180);
  //Execution
    //First matchload
      Bottom.move(motorVelocity(100));
      Top.move(motorVelocity(100));
      chassis.moveToPose(-47, -48.5, 180, 2000);
      chassis.turnToHeading(-90, 1000);
      plateArms.extend();
      chassis.moveToPose(-52,-48.5,-90,2000);
      chassis.moveToPoint(-60, -48.5, 2000);
      chassis.moveToPoint(-53, -48.5, 1500, {.forwards = false});
      chassis.moveToPoint(-60, -48.5, 2500);
    //Moves across board
      chassis.moveToPose(-48,-48, -90, 1500, {.forwards = false});
      pros::delay(750);
      plateArms.retract();
      chassis.turnToHeading(145,1000);
      chassis.moveToPoint(-36, -59, 2000, {}, false);
      Bottom.brake();
      Top.brake();
      chassis.turnToHeading(95, 1000);
      chassis.moveToPose(46, -63.5, 90, 4000);
      chassis.turnToHeading(40,1000);
      chassis.moveToPoint(56, -54.5, 1500);
    //Scores first matchload
      chassis.turnToHeading(95,2000);
      chassis.moveToPoint(0, -49, 7000, {.forwards = false});
      pros::delay(1750);
      lid.retract();
      Top.move(motorVelocity(100));
      Bottom.move(motorVelocity(100));
      pros::delay(1500);
      Top.move(motorVelocity(-100));
      Bottom.move(motorVelocity(-100));
      pros::delay(500);
      Top.move(motorVelocity(100));
      Bottom.move(motorVelocity(100));
      pros::delay(2500);
      lid.extend();
      pros::delay(500);
    //Second matchload
      plateArms.extend();
      chassis.moveToPose(55.5, -52, 90, 1500);
      chassis.moveToPoint(65, -52, 2000);
      chassis.moveToPoint(57, -52, 1500, {.forwards = false});
      chassis.moveToPoint(65, -52, 2500);
    //Scores second matchload
      chassis.moveToPoint(0, -51.5, 3000, {.forwards = false});
      pros::delay(1750);
      lid.retract();
      Top.move(motorVelocity(100));
      Bottom.move(motorVelocity(100));
      pros::delay(1500);
      Top.move(motorVelocity(-100));
      Bottom.move(motorVelocity(-100));
      pros::delay(500);
      Top.move(motorVelocity(100));
      Bottom.move(motorVelocity(100));
      pros::delay(4000);
    //Goes to park
      chassis.moveToPoint(45, -53, 1500, {}, false);
      Bottom.brake();
      Top.brake();
      lid.extend();
      plateArms.retract();
      chassis.turnToHeading(0, 1500);
      chassis.moveToPoint(45 ,-37, 2000);
      chassis.turnToHeading(-90, 1500);
      chassis.moveToPoint(-62, -37, 5000, {.maxSpeed = 75});
      chassis.turnToHeading(-25, 1500);
      chassis.moveToPoint(-68, -10, 1500, {.minSpeed = 127});
      // pros::delay(500);
      // chassis.moveToPoint(-68, -100, 500, {.forwards = false, .minSpeed = 127});

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