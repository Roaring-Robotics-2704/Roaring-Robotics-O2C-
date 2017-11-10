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
};
class Victor{
public:
	Victor(int channel){

	}
	void set(double velocity){
		velocity = std::max(std::min(velocity, 1.0), -1.0);
	}

private:
	double velocity = 0.0;
};
}
namespace mystuff{
	namespace pri{
	double robotX;
	double robotY;
	frc::SampleRobot robot;
	}
	void update(){

	}
}
template<class RobotClass : frc::SampleRobot>
void START_ROBOT_CLASS(){
	mystuff::pri::robot = robot();
}


#endif /* INC_CUSTOM_H_ */
