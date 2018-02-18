/*
 * Climber.h
 *
 *  Created on: Feb 10, 2018
 *      Author: epeterson
 */

#ifndef SRC_MODULES_CLIMBER_H_
#define SRC_MODULES_CLIMBER_H_

class Climber : public Module {
public:
	void OperatorControl(){
		bool winch = hw::stick->GetRawButton(8);


		if(winch){
			hw::winchVictor1->Set(.7);		//Activate winch
			hw::winchVictor2->Set(-.7);
		} else{
			hw::winchVictor1->Set(0);		//Turn off winch
			hw::winchVictor2->Set(0);
		}
	}
};




#endif /* SRC_MODULES_CLIMBER_H_ */
