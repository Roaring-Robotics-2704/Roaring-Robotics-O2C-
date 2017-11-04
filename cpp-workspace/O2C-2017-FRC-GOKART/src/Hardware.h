/*
 * Hardware.h
 *
 *  Created on: Jun 26, 2017
 *      Author: cryog
 */

#ifndef SRC_HARDWARE_H_
#define SRC_HARDWARE_H_

namespace hw {

	frc::Joystick* stick; // Declare that the robot has a Joystick. Don't actually bother defining it
	frc::Victor* l;
	frc::Victor* r;

	frc::AnalogGyro* gyro;
}


void registerComponents(){ // Oh, here we actually define the hardware

	hw::stick = new frc::Joystick(0); // Initialize the joystick (see "Hardware.h")

	hw::l = new frc::Victor(0);
	hw::r = new frc::Victor(1);

	//hw::gyro = new frc::AnalogGyro(1);

}

#endif /* SRC_HARDWARE_H_ */
