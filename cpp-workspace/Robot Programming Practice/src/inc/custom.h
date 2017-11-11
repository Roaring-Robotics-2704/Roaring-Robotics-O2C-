/*
 * custom.h
 *
 *  Created on: Nov 10, 2017
 *      Author: Alex Anderson
 */

#ifndef INC_CUSTOM_H_
#define INC_CUSTOM_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

namespace frc{
class SampleRobot{
	virtual void RobotInit();
	virtual void OperatorControl();
	virtual void Test();
	virtual void Autonomous();
	//
	virtual bool IsOperatorControl();
	virtual bool IsAutonomous();
	virtual bool IsTest();
	virtual bool IsEnabled();
};
class SmartDashboard{
public:
	static void PutNumber(double number){
		// Do nothing
	}
};
class Victor{
public:
	Victor(int channel){

	}
	void Set(double velocity){
		velocity = std::max(std::min(velocity, 1.0), -1.0);
	}

private:
	double velocity = 0.0;
};
}
namespace mystuff{
	namespace pri{
	enum robotState{
		OPERATOR_CONTROL,
		AUTONOMOUS,
		TEST
	};
	robotState curState;
	bool enabled = false;
	double robotX;
	double robotY;
	frc::SampleRobot robot;
	}
	void update(){

	}
}
bool frc::SampleRobot::IsEnabled(){
	return mystuff::pri::enabled;
}
bool frc::SampleRobot::IsOperatorControl(){
	return mystuff::pri::curState == mystuff::pri::OPERATOR_CONTROL;
}
template<class RobotClass>
void START_ROBOT_CLASS(){
	mystuff::pri::robot = RobotClass();
}


#endif /* INC_CUSTOM_H_ */
