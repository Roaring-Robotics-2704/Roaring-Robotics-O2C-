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
	void OperatorControl(){
		SmartDashboard::PutNumber("Debug Mode", isDebugMode());
		SmartDashboard::PutNumber("Autonomous Training", isTrainingMode());
		SmartDashboard::PutNumber("Current Debug Key", RobotPrivate::debugKey);
		SmartDashboard::PutNumber("Current Auto Time", AutonomousPrivate::autoTimer->Get());
	}
	void Disabled(){
		SmartDashboard::PutNumber("Debug Mode", isDebugMode());
		SmartDashboard::PutNumber("Autonomous Training", isTrainingMode());
		SmartDashboard::PutNumber("Current Debug Key", RobotPrivate::debugKey);
		SmartDashboard::PutNumber("Current Auto Time", AutonomousPrivate::autoTimer->Get());
	}
	void Autonomous(){

		SmartDashboard::PutNumber("Debug Mode", isDebugMode());
		SmartDashboard::PutNumber("Autonomous Training", isTrainingMode());
		SmartDashboard::PutNumber("Current Debug Key", RobotPrivate::debugKey);
		SmartDashboard::PutNumber("Current Auto Time", AutonomousPrivate::autoTimer->Get());
	}
};


#endif /* SRC_MODULES_STATUSREPORTMODULE_H_ */
