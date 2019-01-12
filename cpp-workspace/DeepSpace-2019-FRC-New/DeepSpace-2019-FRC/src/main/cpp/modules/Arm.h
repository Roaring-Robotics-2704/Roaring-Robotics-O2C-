/*
 * Arm.h
 */


#ifndef ARM_H_
#define ARM_H_

class Arm : public Module {
private:
	double frontBound;
	double bottomBound;
	double armLength;
	double robotHeight;
	bool wasPressed = false;
	Timer t2;
	Timer t1;
public:

	void ModuleInit(){
		hw::compressor1->SetClosedLoopControl(true);	//Turn the compressor off and on based on pressure switch configuration
	}

	void OperatorControl(){				//Get joystick button input
		bool liftButton = hw::stick->GetRawButton(7);
		bool lowerButton = hw::stick->GetRawButton(8);
		bool clawToggle1 = hw::stick->GetRawButton(2);

		if(liftButton){
			hw::armVic1->Set(-.7);						//Raise the arm
			hw::armVic2->Set(-.7);

		} else if(lowerButton){
			hw::armVic1->Set(.7);						//Lower the arm
			hw::armVic2->Set(.7);
		} else{
			hw::armVic1->Set(0);						//No motion
			hw::armVic2->Set(0);
		}
		if (clawToggle1 && !wasPressed){				//Depending on the state of the claw, open or close pneumatic claw
				hw::doubleSol1->Set(frc::DoubleSolenoid::Value::kForward);
				t1.Reset();
				t1.Start();
				t2.Reset();
				t2.Start();
		}

		if(t2.Get() >= 0.25){							//Turn off the solenoid after 1/4 sec
			hw::doubleSol1->Set(frc::DoubleSolenoid::Value::kOff);
			t2.Stop();
			t2.Reset();
		}
		if(t1.Get() >= 5){								//Reverse the direction after 5 secs
			hw::doubleSol1->Set(frc::DoubleSolenoid::Value::kOff);
			t1.Stop();
			t1.Reset();
			hw::doubleSol1->Set(frc::DoubleSolenoid::Value::kReverse);
			t2.Reset();
			t2.Start();
		}
		wasPressed = clawToggle1;
	}

	void Autonomous(){
	}

	void telescopeArm(){
		double armExtension = hw::telescopeEnc->Get();
		double armAngle = hw::armEnc->Get();
		double dnc = 50;
		double robotHeight = 60;
		double robotLength = 35;

		double distance1, distance2;

		distance1 = sqrt(pow(robotHeight / cos(armAngle) * sin(armAngle), 2) + pow(robotHeight, 2) - robotLength);
		distance2 = sqrt(pow(dnc, 2) + pow(dnc / sin(armAngle) * cos(armAngle), 2) - robotLength);

		int buf1 = 5;
		int buf2 = 10;

		if (armExtension >= distance1 - buf1 || armExtension >= distance2 - buf1){
			hw::telescopeVic->Set(-0.7);
		}else if(armExtension <= distance1 - buf2 || armExtension <= distance2 - buf2) {
			hw::telescopeVic->Set(0.7);
		}else{
			hw::telescopeVic->Set(0.0);
		}
	}
};

#endif /* ARM_H_ */


