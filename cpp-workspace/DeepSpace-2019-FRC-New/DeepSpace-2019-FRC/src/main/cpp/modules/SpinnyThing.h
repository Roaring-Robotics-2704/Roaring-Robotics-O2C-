/*
 * Lift.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Roaring Robotics
 */

#ifndef SRC_MODULES_SPINNYTHING_H_
#define SRC_MODULES_SPINNYTHING_H_


class SpinnyModule : public Module {
private:

public:
	void OperatorControl(){
		bool reverse = hw::stick->GetRawButton(2);

		if(reverse){
			hw::spinnyMotor->Set(-1.0);
		} else{
			hw::spinnyMotor->Set(1.0);
		}
	}
};


#endif /* SRC_MODULES_SPINNYTHING_H_ */
