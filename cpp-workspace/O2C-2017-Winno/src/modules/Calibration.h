/*
 * Calibration.h
 *
 *  Created on: Jul 1, 2017
 *      Author: cryog
 */

#ifndef CALIBRATION_H_
#define CALIBRATION_H_


namespace CalibrationPrivate{
	double calibrationFactor;
}
class Calibration : public Module{
private:
	bool calibrationStatus = false;
	double avgWheelRot;

	int flRot;
	int frRot;
	int rlRot;
	int rrRot;

	int lFlRot;
	int lFrRot;
	int lRlRot;
	int lRrRot;

	double flSpd;
	double frSpd;
	double rlSpd;
	double rrSpd;

	frc::Timer flT;
	frc::Timer frT;
	frc::Timer rlT;
	frc::Timer rrT;

	void resetCalibration(){
		hw::gyro->Reset();

		flRot = 0;
		frRot = 0;
		rlRot = 0;
		rrRot = 0;

		flT.Reset();
		frT.Reset();
		rlT.Reset();
		rrT.Reset();

		flT.Start();
		frT.Start();
		rlT.Start();
		rrT.Start();
	}
	double wheelRotToDegrees(double wheelRot){
		return wheelRot * (8.0 / 27.0);
		//return wheelRot * (6.0 / 20.5);
	}
public:
	void ModuleInit(){
		frc::SmartDashboard::PutBoolean("Calibration enabled", false);
		frc::SmartDashboard::SetPersistent("Calibration");
		CalibrationPrivate::calibrationFactor = frc::SmartDashboard::GetNumber("Calibration", 0.0);
		frc::SmartDashboard::PutNumber("Heading", 0.0);
		frc::SmartDashboard::PutNumber("Heading_raw", 0.0);
		frc::SmartDashboard::PutNumber("Gyro calibration", CalibrationPrivate::calibrationFactor);
	}
	void OperatorControl(){
		bool lastCalibStatus = calibrationStatus;
		calibrationStatus = frc::SmartDashboard::GetBoolean("Calibration enabled", false);
		if(calibrationStatus != lastCalibStatus){
			resetCalibration();
		}
		frc::SmartDashboard::PutNumber("Heading", hw::gyro->GetAngle() * CalibrationPrivate::calibrationFactor);
		frc::SmartDashboard::PutNumber("Heading_raw", hw::gyro->GetAngle());
		frc::SmartDashboard::PutNumber("Gyro calibration", CalibrationPrivate::calibrationFactor);
		if(!calibrationStatus) return;
		if(flRot != lFlRot){
			flSpd = flT.Get();
			flT.Reset();
		}
		if(frRot != lFrRot){
			frSpd = frT.Get();
			frT.Reset();
		}
		if(rlRot != lRlRot){
			rlSpd = rlT.Get();
			rlT.Reset();
		}
		if(rrRot != lRrRot){
			rrSpd = rrT.Get();
			rrT.Reset();
		}

		double rotFl = flRot + flSpd * flT.Get();
		double rotFr = frRot + frSpd * frT.Get();
		double rotRl = rlRot + rlSpd * rlT.Get();
		double rotRr = rlRot + rrSpd * rrT.Get();
		double avgRot = (abs(rotFl) + abs(rotFr) + abs(rotRl) + abs(rotRr)) / 4.0;
		frc::SmartDashboard::PutNumber("Encoder rotation", avgRot);
		double sensitivity = wheelRotToDegrees(avgRot) / hw::gyro->GetAngle();
		CalibrationPrivate::calibrationFactor = sensitivity;

		lFlRot = flRot;
		lFrRot = frRot;
		lRlRot = rlRot;
		lRrRot = rrRot;
	}
	static double getCalibrationFactor(){
		return CalibrationPrivate::calibrationFactor;
	}
};


#endif /* CALIBRATION_H_ */
