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
		bool padButton1 = hw::stick->GetRawButton(11);	//Change these buttons!!
		bool padButton2 = hw::stick->GetRawButton(12);
		bool padButton3 = hw::stick->GetRawButton(10);

		if(padButton2){
			hw::liftTalon->Set(.7);		//upwards motion of lift
		} else if(padButton1){
			hw::liftTalon->Set(-.7); //downwards motion of lift
		} else{
			hw::bkTalon->Set(0);		//No motion
		}

		if(padButton3){
			hw::winchVictor1->Set(.7);		//Activate winch
			hw::winchVictor2->Set(.7);
		} else{
			hw::winchVictor1->Set(0);		//Turn off winch
			hw::winchVictor2->Set(0);
		}
	}
};




#endif /* SRC_MODULES_CLIMBER_H_ */
