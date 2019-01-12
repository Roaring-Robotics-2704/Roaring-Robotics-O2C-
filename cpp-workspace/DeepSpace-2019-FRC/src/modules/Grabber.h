/*
 * Grabber.h
 */


#ifndef GRABBER_H_
#define GRABBER_H_

class Grabber : public Module {
private:
	Timer t1;
	Timer t2;
	bool wasPressed = false;
public:

	void ModuleInit(){

	}

	 void OperatorControl(){					//Get joystick button input
			bool clawToggle2 = hw::stick->GetRawButton(1);	//CHANGE BUTTON
			bool grab = hw::stick->GetRawButton(5);	//CHANGE BUTTON
			bool eject = hw::stick->GetRawButton(7);	//CHANGE BUTTON

			if (grab){
				hw::lgrVic->Set(0.7);			//Rotate grabber wheels to pull cubes in
				hw::rgrVic->Set(0.7);
			} else if(eject){
				hw::lgrVic->Set(-0.7);			//Rotate grabber wheels to eject cubes
				hw::rgrVic->Set(-0.7);
			}else {
				hw::lgrVic->Set(0);				//No motion
				hw::rgrVic->Set(0);
			}

			if (clawToggle2 && !wasPressed){	//Depending on state of claw, open or close pneumatic claw
					hw::doubleSol2->Set(frc::DoubleSolenoid::Value::kForward);
					t1.Reset();
					t1.Start();
					t2.Reset();
					t2.Start();
			}
			if(t2.Get() >= 0.25){				//Turn off the solenoid after 1/4 sec
				t2.Stop();
				t2.Reset();
				hw::doubleSol2->Set(frc::DoubleSolenoid::Value::kOff);
			}
			if (t1.Get() >= 5){					//Reverse the direction after 5 secs
				t1.Stop();
				t1.Reset();
				hw::doubleSol2->Set(frc::DoubleSolenoid::Value::kReverse);
				t2.Reset();
				t2.Start();
			}
			wasPressed = clawToggle2;
	}

	void Autonomous(){
	}
};

#endif /* GRABBER_H_ */


