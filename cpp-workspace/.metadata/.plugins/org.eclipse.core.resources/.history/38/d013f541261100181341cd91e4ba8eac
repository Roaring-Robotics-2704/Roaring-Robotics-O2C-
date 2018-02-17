/*
 * Grabber.h
 */


#ifndef GRABBER_H_
#define GRABBER_H_

class Grabber : public Module {
	 void OperatorControl(){
		 if(isDebugMode()){

			 return;
		 }
#ifdef CONTROLLER_ALT_1
			bool leftBumper  = hw::stick->GetRawButton(5);
#else
			bool leftBumper  = hw::stick->GetRawButton(5);
#endif

			if(leftBumper){
				hw::grabServ->SetAngle(120);
			} else{
				hw::grabServ->SetAngle(0);
			}

	}

	void Autonomous(){



	}

};

#endif /* GRABBER_H_ */



