/*
 * Module.h
 *
 *  Created on: Jun 21, 2017
 *      Author: cryog
 */

#ifndef SRC_MODULE_H_
#define SRC_MODULE_H_

namespace ModuleClassPrivate{
	unsigned long lMid;
};
/*
 * The template for the Robot modules. This doesn't actually need to change. Ever. Well, maybe not *ever* but you get the point
 */
class Module{
private:
	unsigned long mid;

public:
	Module(){
		this->mid = ++ ModuleClassPrivate::lMid;
	}

	virtual void ModuleInit(){}

	virtual void OperatorControl(){} // For TeleOp modules, define this
	virtual void Autonomous(){} // For Autonomous modules, define this
		// Or for modules that do both, define BOTH!
	virtual void ModeChange(){};
	virtual void ClearAuto(){};
	const unsigned long ModuleId(){
		return this->mid;
	}
};


#endif /* SRC_MODULE_H_ */
