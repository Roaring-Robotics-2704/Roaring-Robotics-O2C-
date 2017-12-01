/*
 * Grabber.h
 */


#ifndef GRABBER_H_
#define GRABBER_H_

class Grabber : public Module {
	 void OperatorControl(){
			bool leftTrigger = hw::stick->GetRawButton(7);
			bool leftBumper  = hw::stick->GetRawButton(5);

			if(leftBumper){
				hw::grabServ->SetAngle(120);
			} else if(leftTrigger){
					hw::grabServ->SetAngle(-120);
			} else{
				hw::grabServ->SetAngle(0);
			}

	}

	void Autonomous(){



	}

};

#endif /* GRABBER_H_ */



