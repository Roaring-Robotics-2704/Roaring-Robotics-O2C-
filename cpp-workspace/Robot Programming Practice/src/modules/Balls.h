/*
 * Balls.h
 *
 *  Created on: Jul 15, 2017
 *      Author: cryog
 */

#ifndef BALLS_H_
#define BALLS_H_


class Balls : public Module {
private:
public:
	void OperatorControl(){
		bool shootBtn = hw::stick->GetRawButton(3);
		if(shootBtn){
			hw::ballVic0->Set(-1.0);
		} else{
			hw::ballVic0->Set(0.0);
		}
	}
};
#endif /* BALLS_H_ */
