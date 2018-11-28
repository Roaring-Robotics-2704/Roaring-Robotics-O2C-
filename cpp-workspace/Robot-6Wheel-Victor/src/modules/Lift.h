/*
 * Lift.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Roaring Robotics
 */

#ifndef SRC_MODULES_LIFT_H_
#define SRC_MODULES_LIFT_H_


class LiftModule : public Module {
private:

public:
	void OperatorControl(){
		bool up = hw::stick->GetRawButton(5);
		bool dn = hw::stick->GetRawButton(3);

		if(up){
			hw::liftMotor->Set(1.0);
		} else if(dn){
			hw::liftMotor->Set(-1.0);
		} else{
			hw::liftMotor->Set(0.0);
		}
	}
};


#endif /* SRC_MODULES_LIFT_H_ */
