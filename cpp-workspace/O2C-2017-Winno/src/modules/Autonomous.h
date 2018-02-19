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
	map<unsigned long, map<int, AutonomousEntry*>> autoData;
	bool hasRunOnce = false;
}
class AutonomousMain : public Module{
public:
	void ModuleInit(){
		frc::SmartDashboard::SetDefaultNumber("Starting position (1, 2 or 3)", 0);
		AutonomousPrivate::autoTimer->Reset();
		AutonomousPrivate::autoTimer->Stop();
	}
	void ModeChange(){
		AutonomousPrivate::autoTimer->Reset();
		AutonomousPrivate::autoTimer->Stop();
		AutonomousPrivate::hasRunOnce = false;
	}
	void Disabled(){
		AutonomousPrivate::hasRunOnce = false;
	}
	static void registerAutoModule(Module* m){
		unsigned long tmid = m->ModuleId();
		AutonomousPrivate::autoModules.push_back(m);
		AutonomousPrivate::autoModuleIds.push_back(tmid);
		map<int, AutonomousEntry*> mo;
		mo.emplace(DriverStation::GetInstance().GetLocation(), new AutonomousEntry(tmid, DriverStation::GetInstance().GetLocation()));
		AutonomousPrivate::autoData.emplace(tmid, mo);
	}
	void ClearAuto(){
		for(unsigned long id : AutonomousPrivate::autoModuleIds){
			AutonomousPrivate::autoData[id][0]->ixS = 0;
			AutonomousPrivate::autoData[id][0]->ixV = 0;
			AutonomousPrivate::autoData[id][0]->clear();

		}
	}
	static vector<double> getAutonomousData(Module* m){ // Returns empty vector if there's no data to return or it's too early to retrurn data
		unsigned long id = m->ModuleId();
		double d = AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()]->peekAtNextValues()->second;
		if(d > AutonomousPrivate::autoTimer->Get()){
			return AutonomousPrivate::autoData[id][DriverStation::GetInstance().GetLocation()]->getNextValues()->first;
		}
		return vector<double>();
	}
	static void putAutonomousData(Module* m, vector<double> d){
		AutonomousPrivate::autoData[m->ModuleId()][DriverStation::GetInstance().GetLocation()]->putLastValues(d, AutonomousPrivate::autoTimer->Get());
	}
	void Autonomous(){
	}
};

#endif /* AUTONOMOUSMAIN_H_ */
