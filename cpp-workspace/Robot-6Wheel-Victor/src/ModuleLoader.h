/*
 * ModuleLoader.h
 *
 *  Created on: Jun 21, 2017
 *      Author: cryog
 */

#ifndef SRC_MODULELOADER_H_
#define SRC_MODULELOADER_H_

// Load module headers

#include "modules/Arm.h"
#include "modules/DriveTrain.h" // Load the DriveTrain module
#include "modules/Calibration.h"
#include "modules/Uber.h"
#include "modules/Balls.h"
#include "modules/ReflectorSensors.h"
#include "modules/Grabber.h"
#include "modules/Climber.h"
#include "modules/Autonomous.h" // Theoretically, this should have already been loaded so this line *should* be unnecessary
#include "modules/StatusReportModule.h"
#include "modules/Camera.h"
#include "modules/Lift.h"
#include "modules/Servo.h"

/*
 * Put the module-loading code here.
 */
void loadModules(){
	//robot->registerModule(new AutonomousMain()); // Autonomous needs to be registered before any modules that reference it, so it's safest to keep it first
	robot->registerModule(new CameraModule());
	robot->registerModule(new DriveTrain()); // Registers a new DriveTrain module with the Robot
	//robot->registerModule(new Arm());
	//robot->registerModule(new Calibration());
	//robot->registerModule(new Uber());
	//robot->registerModule(new Balls());
	//robot->registerModule(new ReflectorSensors());
	//robot->registerModule(new Grabber());
	//robot->registerModule(new Climber());
	robot->registerModule(new LiftModule());
	robot->registerModule(new ServoModule());
	robot->registerModule(new StatusReportModule());

}

#endif /* SRC_MODULELOADER_H_ */
