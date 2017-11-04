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
//#include "modules/Calibration.h"


/*
 * Put the module-loading code here.
 */
void loadModules(){
	robot->registerModule(new DriveTrain()); // Registers a new DriveTrain module with the Robot
	//robot->registerModule(new Calibration());
}

#endif /* SRC_MODULELOADER_H_ */
