/*
 * Uber.h
 *
 *  Created on: Jul 5, 2017
 *      Author: cryog
 */

#ifndef UBER_H_
#define UBER_H_


class Uber : public Module{
private:
	bool ignoreInput = true;
	double volume;
	int state;
	int state2;
	bool state3;
	double ropeSpeed = 1.0;
public:
	void OperatorControl(){
		bool leftTrigger = hw::stick->GetRawButton(7);
		bool leftBumper  = hw::stick->GetRawButton(5);

		hw::earpiece->Set(0);
		hw::uberDriver->Set(0);
		if(ignoreInput || !leftTrigger){
			volume = 0;
		}
		if(leftTrigger && leftBumper){
			ignoreInput = true;
			if(state < 170){
				hw::uberDriver->Set(-.5);
				hw::earpiece->Set(-.3);
			} else{
				hw::earpiece->Set(0);
			}
			state ++;
			state2 = 0;
			volume = 0;
			state3 = true;
		} else if(!ignoreInput){
			state = 0;
			if(leftTrigger){
				volume += .0025;
				hw::uberDriver->Set(std::min(volume, 1.0 * ropeSpeed));
				state2 = 0;
			} else if(leftBumper){
				state3 = false;
				volume = 0;
				if(state2 < 120){
					hw::earpiece->Set(-.3);
					hw::uberDriver->Set(1.0 * ropeSpeed);
					state2 ++;
				}
			}
		} else if(!(leftBumper || leftTrigger)){
			state = 0;
			volume = 0;
			ignoreInput = false;
			state2 = 0;
			hw::earpiece->Set(.3);
		}
	}
};


#endif /* UBER_H_ */
