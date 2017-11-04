/*
 * AutonomousMain.h
 *
 *  Created on: Jul 1, 2017
 *      Author: cryog
 */

#ifndef AUTONOMOUSMAIN_H_
#define AUTONOMOUSMAIN_H_


namespace AutonomousPrivate{
	frc::Timer* autoTimer = new frc::Timer();
	bool running;
}
class AutonomousMain : public Module{
	void ModuleInit(){
		frc::SmartDashboard::SetDefaultNumber("Starting position (1, 2 or 3)", 0);
		AutonomousPrivate::autoTimer->Reset();
		AutonomousPrivate::autoTimer->Stop();
	}
	void Autonomous(){
		if(AutonomousPrivate::autoTimer->Get() < 2.0){
			int autoMode = frc::SmartDashboard::GetNumber("Starting position (1, 2 or 3)", 0);
			double lr = 0;
			double vel = -1.0;
			switch(autoMode){
			case 1:
				// We're on the left side. Correct for that.
				//lr = -.1;
				break;
			case 2:
				// We're in the middle. We can't safely go.
				vel = 0.0;
				break;
			case 3:
				// We're on the right side. Correct for that.
				//lr = .1;
				break;
			default:
				// Sit there looking pretty
				vel = 0.0;
				break;
			}
			if(!AutonomousPrivate::running){
				AutonomousPrivate::autoTimer->Reset();
				AutonomousPrivate::autoTimer->Start();
				AutonomousPrivate::running = true;
			}
			DriveTrain::drive(lr, vel, 0.0, false);
		} else{
			DriveTrain::drive(0.0, 0.0, 0.0, false);
		}
	}
	void ModeChange(){
		AutonomousPrivate::autoTimer->Reset();
		AutonomousPrivate::autoTimer->Stop();
		AutonomousPrivate::running = false;
	}
};


#endif /* AUTONOMOUSMAIN_H_ */
