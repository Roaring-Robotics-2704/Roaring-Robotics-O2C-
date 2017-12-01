/*
 * Bucket.h
 */


#ifndef BUCKET_H_
#define BUCKET_H_

class Bucket : public Module {
	 void OperatorControl(){
			bool rightTrigger = hw::stick->GetRawButton(8);
			bool rightBumper  = hw::stick->GetRawButton(6);

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



