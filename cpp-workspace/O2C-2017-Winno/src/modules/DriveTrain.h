/*
 * DriveTrain.h
 *
 *  Created on: Jun 26, 2017
 *      Author: cryog
 */

#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_

namespace DriveTrainPrivate{
	double maxCorrectPerTick = 50.0;
	double speedFactor = 0.01;
	double minSpeed = .2;
	int speedControl = 0;
	bool lSpeedBtn;
	double avgSpeed;
	double flTi = 1.0;
	double frTi = 1.0;
	double rlTi = 1.0;
	double rrTi = 1.0;
	int ticksSpeed = 1;
	int ticksModTicksSpeed = 0;
	double flDev = 1.0;
	double frDev = 1.0;
	double rlDev = 1.0;
	double rrDev = 1.0;
	int lFl = 0;
	int lFr = 0;
	int lRl = 0;
	int lRr = 0;
	double avgSpd;
	double gflTi;
	double gfrTi;
	double grlTi;
	double grrTi;
}
class DriveTrain : public Module { // The code that drives the robot
public:
	void OperatorControl(){
		double leftAxisY = -hw::stick->GetY(hw::stick->kLeftHand);
		double rightAxisZ = hw::stick->GetThrottle();

		hw::flVictor->Set(leftAxisY);
		hw::rlVictor->Set(leftAxisY);

		hw::frVictor->Set(rightAxisZ);
		hw::rrVictor->Set(rightAxisZ);

	}
};


#endif /* DRIVETRAIN_H_ */
