/*
 * PigeonIMU.h
 *
 *  Created on: Apr 3, 2018
 *      Author: cryog
 */

#ifndef SRC_MODULES_PIGEONIMU_H_
#define SRC_MODULES_PIGEONIMU_H_

namespace PigeonData{
	double yawPitchRoll[3];
	double fusedHeading;
	PigeonIMU::GeneralStatus status;
}

class Pigeon : public Module{
private:
public:
	/*
	void ModuleInit(){
		SmartDashboard::PutString("Pigeon State", "Not ready");
		do{
			hw::pigeon->GetGeneralStatus(PigeonData::status);
		} while(PigeonData::status.state != PigeonIMU::PigeonState::Ready);
		SmartDashboard::PutString("Pigeon State", "Ready");
		hw::pigeon->SetYaw(0, 100);
		hw::pigeon->SetFusedHeading(0, 100);
	}
	void OperatorControl(){
		hw::pigeon->GetGeneralStatus(PigeonData::status);
		hw::pigeon->GetYawPitchRoll(PigeonData::yawPitchRoll);
		PigeonData::fusedHeading = hw::pigeon->GetFusedHeading();
	}
	*/
};


#endif /* SRC_MODULES_PIGEONIMU_H_ */
