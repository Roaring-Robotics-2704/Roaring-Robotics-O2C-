/*
 * DriveTrain.h
 *
 *  Created on: Jun 26, 2017
 *      Author: cryog
 */

#ifndef DRIVETRAIN_H_
#define DRIVETRAIN_H_


#define MAX_SPEED_FACTOR .95

// Per-controller defines

// Standard (Logitech Dual Action) Controllers
	/* Nothing here yet */
// Type 1 controllers (Logitech Extreme 3D Pro)
#define TYPE_1_CONTROLLER_ROT_DEGREES 25


//

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
	double orientation = 0.0;

	size_t autoIx;
}
class DriveTrain : public Module { // The code that drives the robot
public:
	void OperatorControl(){
		double leftAxisX = hw::stick->GetX(); // Gets the left joystick's left<->right movement (from 0.0 to 1.0)
		double leftAxisY = hw::stick->GetY(); // Same thing, with its up<->down movement
#ifdef PRAC_BOT
		leftAxisY *= -1.0;
#endif
		double rightAxisZ = hw::stick->GetZ(); // Now get the right Joystick's left<->right movement
		drive(leftAxisX, leftAxisY, rightAxisZ, false);
	}
	void drive(double leftAxisX, double leftAxisY, double rightAxisZ, bool correctOverride){


#ifdef CONTROLLER_ALT_1
		double rotDeg = TYPE_1_CONTROLLER_ROT_DEGREES * rightAxisZ;
		double magn = sqrt(leftAxisX * leftAxisX + leftAxisY * leftAxisY);
		double angle = atan2(leftAxisX, leftAxisY);
		angle += rotDeg * (PI / 180.8);
		leftAxisX = sin(angle) * magn;
		leftAxisY = cos(angle) * magn;
#endif
		double speedFactor = 0.0;
#ifdef CONTROLLER_ALT_1
		speedFactor = MAX_SPEED_FACTOR * (hw::stick->GetThrottle() / 2.0 + 0.5);
#else
		bool speedBtn = hw::stick->GetRawButton(12);
		if(speedBtn){
			if(!DriveTrainPrivate::lSpeedBtn){
				DriveTrainPrivate::speedControl = (DriveTrainPrivate::speedControl + 1) % 4;
			}
			DriveTrainPrivate::lSpeedBtn = true;
		} else{
			DriveTrainPrivate::lSpeedBtn = false;
		}

		switch(DriveTrainPrivate::speedControl){
		case 0:
			speedFactor = .5 * MAX_SPEED_FACTOR;
			break;
		case 1:
			speedFactor = .75 * MAX_SPEED_FACTOR;
			break;
		case 2:
			speedFactor = MAX_SPEED_FACTOR;
			break;
		case 3:
			speedFactor = 0.0;
		}
#endif
		SmartDashboard::PutNumber("DriveTrain speed", speedFactor);

#ifdef CONTROLLER_ALT_1
#endif
		rightAxisZ *= 0.35;

		 if(!isLifting){
			 if(isTrainingMode()){
				 vector<double> autoStates;
				 autoStates.push_back(leftAxisX);
				 autoStates.push_back(leftAxisY);
				 autoStates.push_back(rightAxisZ);

				 AutonomousMain::putAutonomousData(this, autoStates);
			 }
			 if(!isDebugMode())
				 hw::rd->DriveCartesian(leftAxisX, leftAxisY, rightAxisZ);
			 else{
				 if(hw::stick->GetRawButton(8))
					 hw::rd->DriveCartesian(0.0, 1.0, 0.0);
				 else if(hw::stick->GetRawButton(7))
					 hw::rd->DriveCartesian(0.0, -1.0, 0.0);
				 else
					 hw::rd->DriveCartesian(0.0, 0.0, 0.0);
			 }
		 } else{
			 AutonomousMain::putAutonomousData(this, vector<double>{0.0, 0.0, 0.0});
		 }
	}
	void ModeChange(){
		DriveTrainPrivate::autoIx = 0;
	}
	void Autonomous(){
		vector<double> autoData = AutonomousMain::getAutonomousData(this);
		SmartDashboard::PutNumber("Autonomous Buffer Length", autoData.size());
		if(autoData.size() == 3)
			hw::rd->DriveCartesian(autoData[0], autoData[1], autoData[2]);
		else
			hw::rd->DriveCartesian(0.0, 0.0, 0.0);
	}
	void ModuleInit(){
	}
};


#endif /* DRIVETRAIN_H_ */
