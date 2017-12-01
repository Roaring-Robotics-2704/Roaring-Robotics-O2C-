/*
 * ModuleLoader.h
 *
 *  Created on: Jun 21, 2017
 *      Author: cryog
 */

#ifndef SRC_MODULELOADER_H_
#define SRC_MODULELOADER_H_

// Load module headers

#include "modules/DriveTrain.h" // Load the DriveTrain module
#include "modules/AutonomousMain.h"
#include "modules/Bucket.h"
#include "modules/Calibration.h"
#include "modules/Uber.h"
#include "modules/Balls.h"
#include "modules/ReflectorSensors.h"
#include "modules/Grabber.h"

/*
 * Put the module-loading code here.
 */
void loadModules(){
	robot->registerModule(new DriveTrain()); // Registers a new DriveTrain module with the Robot
	robot->registerModule(new Bucket());
	//robot->registerModule(new Calibration());
	//robot->registerModule(new Uber());
	robot->registerModule(new Balls());
	//robot->registerModule(new ReflectorSensors());
	//robot->registerModule(new AutonomousMain());
	robot->registerModule(new Grabber());

}

#endif /* SRC_MODULELOADER_H_ */
