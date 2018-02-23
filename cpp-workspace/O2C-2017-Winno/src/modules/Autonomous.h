/*
 * AutonomousMain.h
 *
 *  Created on: Jul 1, 2017
 *      Author: cryog
 */

#ifndef AUTONOMOUSMAIN_H_
#define AUTONOMOUSMAIN_H_

#include "unregisteredModules/AutonomousEntry.h"


namespace AutonomousPrivate{
	bool running;
	static frc::Timer* autoTimer = new frc::Timer();
	static vector<Module*> autoModules;
	static vector<unsigned long> autoModuleIds;
	map<unsigned long, map<int, map<int, AutonomousEntry*>>> autoData;
	bool hasRunOnce = false;
	bool loaded = false;
}
class AutonomousMain : public Module{
public:
	void ModuleInit(){
		frc::SmartDashboard::SetDefaultNumber("Starting position (1, 2 or 3)", 0);
		AutonomousPrivate::autoTimer->Reset();
		AutonomousPrivate::autoTimer->Stop();
	}
	void ModeChange(){
		AutonomousPrivate::autoTimer->Stop();
		AutonomousPrivate::autoTimer->Reset();
		AutonomousPrivate::hasRunOnce = false;
	}
	void Disabled(){
		AutonomousPrivate::hasRunOnce = false;
	}
	static void save(){
		RobotStatus::autonomousSaveStatus = false;
		for(unsigned long l : AutonomousPrivate::autoModuleIds){
					for(int x=0; x<=3; x++){
						for(char c : "LR"){
							AutonomousEntry* e = AutonomousPrivate::autoData[l][x][c];
							e->save(e->getFileName());
						}
					}
				}
		RobotStatus::autonomousSaveStatus = true;
	}
	static void registerAutoModule(Module* m){
		AutonomousPrivate::loaded = true;
		unsigned long tmid = m->ModuleId();
		AutonomousPrivate::autoModules.push_back(m);
		AutonomousPrivate::autoModuleIds.push_back(tmid);
		map<int, map<int, AutonomousEntry*>> mo;
		for(int x=0; x<=3; x++){
			map<int, AutonomousEntry*> e2;
			for(char c : "LR"){
				AutonomousEntry* e = new AutonomousEntry(tmid, x, c);
				e->load(e->getFileName());
				e2.emplace(c, e);
			}
			mo.emplace(x, e2);
		}
		AutonomousPrivate::autoData.emplace(tmid, mo);
	}
	void ClearAuto(){
		for(unsigned long id : AutonomousPrivate::autoModuleIds){
			AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->ix = 0;
			AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->clear();

		}
	}
	static vector<double> getAutonomousData(Module* m){ // Returns empty vector if there's no data to return or it's too early to retrurn data
		unsigned long id = m->ModuleId();
		double d = AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->peekAtNextValues();
		SmartDashboard::PutNumber("Next AutoInstruction Time", d);
		if(d < AutonomousPrivate::autoTimer->Get() && d >= 0.0){
			pair<vector<double>, double>* pr = AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->getNextValues();
			if(pr != NULL)
				AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->putTmpVal(pr->first);
				return pr->first;
		}
		if(d >= 0.0)
			return AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->getTmpVal();
		return vector<double>();
	}
	static void putAutonomousData(Module* m, vector<double> d){
		AutonomousPrivate::autoData[m->ModuleId()][DriverStation::GetInstance().GetLocation()][RobotStatus::gameSpecificMessage[0]]->putLastValues(d, AutonomousPrivate::autoTimer->Get());
	}
	void Autonomous(){
		if(!AutonomousPrivate::hasRunOnce){
			AutonomousPrivate::hasRunOnce = true;
			AutonomousPrivate::autoTimer->Start();
		}
	}
	void OperatorControl(){
		if(isTrainingMode()){
			if(!AutonomousPrivate::hasRunOnce){
				AutonomousPrivate::hasRunOnce = true;
				AutonomousPrivate::autoTimer->Start();
			}
		} else{
			AutonomousPrivate::hasRunOnce = false;
			AutonomousPrivate::autoTimer->Stop();
			AutonomousPrivate::autoTimer->Reset();

		}
	}
};

#endif /* AUTONOMOUSMAIN_H_ */
