#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Intake/Outake motors
  motor bottom = motor(PORT7, ratio6_1, false);
  motor top = motor(PORT6, ratio6_1, false);


//Pneumatics
  //"Hatch"
        pneumatics hatch = pneumatics(Brain.ThreeWirePort.H, false);
    //"Lid"
        pneumatics lid = pneumatics(Brain.ThreeWirePort.F, false);
    //"Thingy"
        pneumatics plateArms = pneumatics(Brain.ThreeWirePort.G, false);

void vexcodeInit( void ) {
  // nothing to initialize
}