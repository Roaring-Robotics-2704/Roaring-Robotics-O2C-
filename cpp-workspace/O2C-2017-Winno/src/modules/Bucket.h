/*
 * Bucket.h
 */


#ifndef BUCKET_H_
#define BUCKET_H_

class Bucket : public Module {
	 void OperatorControl(){
		 if(isDebugMode()){

			 return;
		 }
#ifdef CONTROLLER_ALT_1
			bool rightTrigger = hw::stick->GetRawButton(6);
			bool rightBumper  = hw::stick->GetRawButton(4);
#else
			bool rightTrigger = hw::stick->GetRawButton(8);
			bool rightBumper  = hw::stick->GetRawButton(6);
#endif

			if(rightBumper){
				hw::bkVictor->Set(.7);
			} else if(rightTrigger){
					hw::bkVictor->Set(-.7);
			} else{
				hw::bkVictor->Set(0);
			}

	}

	void Autonomous(){



	}

};

#endif /* BUCKET_H_ */



