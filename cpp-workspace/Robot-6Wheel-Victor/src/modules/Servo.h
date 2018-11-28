/*
 * Lift.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Roaring Robotics
 */

#ifndef SRC_MODULES_SERVO_H_
#define SRC_MODULES_SERVO_H_


class ServoModule : public Module {
private:
public:
	void OperatorControl(){
		bool openClaw = hw::stick->GetRawButton(1);

		if(openClaw){
			hw::servo->Set(0.0);
		} else{
			hw::servo->Set(1.0);
		}
	}
};


#endif /* SRC_MODULES_SERVO_H_ */
