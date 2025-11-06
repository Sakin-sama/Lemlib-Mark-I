#include "auton_functions.hpp"
#include "pros/rtos.hpp"

//Intakes blocks
  void intake(std::string correctColor, int time) {
    BottomBack.brake();
    for (int i = 0; 25*i < time; i++) {
      BottomOut.move(motorVelocity(70));
      TopOut.move(motorVelocity(100));
      TopBack.move(motorVelocity(60));
      Mandibles.move(50);
      colorSorting(correctColor);
      pros::delay(25);
    }
    stopAll();
  }

//Bottom block export
  void bottomBlockExport(int time) {
    TopOut.brake();
    TopBack.brake();
    BottomOut.move(motorVelocity(-50));
    BottomBack.move(motorVelocity(-100));
    Mandibles.move(-50);
    pros::delay(time);
    stopAll();
  }

//Middle block export
  void middleBlockExport(int time) {
    TopOut.brake();
    Mandibles.brake();
    BottomOut.move(motorVelocity(50));
    BottomBack.move(motorVelocity(-100));
    TopBack.move(motorVelocity(-60));
    pros::delay(time);
    stopAll();
  }

//Top block export
  void topBlockExport(int time) {
    Mandibles.brake();
    BottomOut.move(motorVelocity(60));
    TopOut.move(motorVelocity(-100));
    BottomBack.move(motorVelocity(-100));
    TopBack.move(motorVelocity(60));
    pros::delay(time);
    stopAll();
  }

//Stops all intakes
  void stopAll() {
    Mandibles.brake();
    BottomOut.brake();
    TopOut.brake();
    BottomBack.brake();
    TopBack.brake();
  }

//Reversi
  void reversi(int time) {
    BottomBack.brake();
    BottomOut.move(motorVelocity(-70));
    TopOut.move(motorVelocity(-100));
    TopBack.move(motorVelocity(-60));
    Mandibles.move(-50);   
    pros::delay(400);
    pros::delay(time);
    stopAll();
  }

//Mandibles
  void mandibleOpen() { //To score
  RightMandiblePnuematic.retract();
  LeftMandiblePnuematic.retract();
  }

  void mandibleClosed() { //To match load
  RightMandiblePnuematic.extend();
  LeftMandiblePnuematic.extend();
  }