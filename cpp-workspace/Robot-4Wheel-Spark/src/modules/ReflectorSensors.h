/*
 * ReflecorSensors.h
 *
 *  Created on: Jul 18, 2017
 *      Author: cryog
 */

#ifndef REFLECTORSENSORS_H_
#define REFLECTORSENSORS_H_


class ReflectorSensors : public Module{
	void OperatorControl(){
		frc::SmartDashboard::PutNumber("Left sensor", hw::lPhoto->Get() ? 1.0 : 0.0);
		frc::SmartDashboard::PutNumber("Right sensor", hw::rPhoto->Get() ? 1.0 : 0.0);
	}
};


#endif /* REFLECTORSENSORS_H_ */
