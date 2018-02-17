/*
 * Cubelift.h
 */


#ifndef CUBELIFT_H_
#define CUBELIFT_H_

class Cubelift : public Module {
	 void OperatorControl(){
		 if(isDebugMode()){

			 return;
		 }
#ifdef CONTROLLER_ALT_1
			bool up = hw::stick->GetRawButton(6);
			bool down  = hw::stick->GetRawButton(4);

			bool top =false; hw::topBkInput->Get();
			bool bot =false; hw::botBkInput->Get();
#else
			bool up = hw::stick->GetRawButton(8);
			bool down  = hw::stick->GetRawButton(6);
#endif

			// Buttons to control the upwards and downwards motion of the cube lift
			if(up){
				if (!top)
					hw::actualTalon->Set(ControlMode::PercentOutput, .5);		//upwards motion of cube lift
			} else if(down){
				if (!bot)
					hw::actualTalon->Set(ControlMode::PercentOutput, -.5); //downwards motion of cube lift
			} else{
				hw::actualTalon->Set(ControlMode::PercentOutput, 0);		//No motion
			}
	}

	void Autonomous(){



	}

};

#endif /* BUCKET_H_ */



