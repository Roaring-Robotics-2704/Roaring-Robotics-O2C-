/*
 * Grabber.h
 */


#ifndef GRABBER_H_
#define GRABBER_H_

class Grabber : public Module {
	 void OperatorControl(){
			bool grab = hw::stick->GetRawButton(1);			//Change these buttons later!!
			bool eject  = hw::stick->GetRawButton(2);

			if(grab){
				hw::lgrVic->Set(.7);		//rotate motors to grab cube (left)
				hw::rgrVic->Set(.7);		//rotate motors to grab cube (right)
			} else if(eject){
					hw::lgrVic->Set(-.7); //rotate motors opposite direction to eject cube (left)
					hw::rgrVic->Set(-.7); //rotate motors opposite direction to eject cube (right)
			} else{
				hw::lgrVic->Set(0);		//No motion (left)
				hw::rgrVic->Set(0);		//No motion (right)
			}
	}

	void Autonomous(){
	}
};

#endif /* GRABBER_H_ */



