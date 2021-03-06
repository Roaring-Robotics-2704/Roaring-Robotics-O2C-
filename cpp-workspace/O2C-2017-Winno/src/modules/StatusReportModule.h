/*
 * StatusReportModule.h
 *
 *  Created on: Feb 19, 2018
 *      Author: cryog
 */

#ifndef SRC_MODULES_STATUSREPORTMODULE_H_
#define SRC_MODULES_STATUSREPORTMODULE_H_


class StatusReportModule : public Module{
public:
	void ModuleInit(){
		RobotStatus::autonomousSaveStatus = false; // Is the autonomous code saved to the RoboRIO?
	}
	void OperatorControl(){
		SmartDashboard::PutNumber("Debug Mode", isDebugMode()); // Output data to the DriverStation dashboard
		SmartDashboard::PutNumber("Autonomous Training", isTrainingMode());
		SmartDashboard::PutNumber("Current Debug Key", RobotPrivate::debugKey);
		SmartDashboard::PutNumber("Current Auto Time", AutonomousPrivate::autoTimer->Get());
		SmartDashboard::PutNumber("Field Position", DriverStation::GetInstance().GetLocation());
		SmartDashboard::PutNumber("Autonomous Save Status", RobotStatus::autonomousSaveStatus);
		SmartDashboard::PutString("Game Data", RobotStatus::gameSpecificMessage);
	}
	void Disabled(){
		SmartDashboard::PutNumber("Debug Mode", isDebugMode());
		SmartDashboard::PutNumber("Autonomous Training", isTrainingMode());
		SmartDashboard::PutNumber("Current Debug Key", RobotPrivate::debugKey);
		SmartDashboard::PutNumber("Current Auto Time", AutonomousPrivate::autoTimer->Get());
		SmartDashboard::PutNumber("Field Position", DriverStation::GetInstance().GetLocation());
		SmartDashboard::PutNumber("Autonomous Save Status", RobotStatus::autonomousSaveStatus);
		SmartDashboard::PutString("Game Data", RobotStatus::gameSpecificMessage);
	}
	void Autonomous(){

		SmartDashboard::PutNumber("Debug Mode", isDebugMode());
		SmartDashboard::PutNumber("Autonomous Training", isTrainingMode());
		SmartDashboard::PutNumber("Current Debug Key", RobotPrivate::debugKey);
		SmartDashboard::PutNumber("Current Auto Time", AutonomousPrivate::autoTimer->Get());
		SmartDashboard::PutNumber("Field Position", DriverStation::GetInstance().GetLocation());
		SmartDashboard::PutNumber("Autonomous Save Status", RobotStatus::autonomousSaveStatus);
		SmartDashboard::PutString("Game Data", RobotStatus::gameSpecificMessage);
	}
};


#endif /* SRC_MODULES_STATUSREPORTMODULE_H_ */
