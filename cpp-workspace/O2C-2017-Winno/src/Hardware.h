/*
 * Hardware.h
 *
 *  Created on: Jun 26, 2017
 *      Author: cryog
 */

#ifndef SRC_HARDWARE_H_
#define SRC_HARDWARE_H_

namespace hw {

	frc::Joystick* stick; // Declare that the robot has a Joystick. Don't actually bother defining it
	WPI_VictorSPX* flVictor; // Same thing, just with a Victor
	WPI_VictorSPX* frVictor; // etc.
	WPI_VictorSPX* rlVictor; // This is getting boring...
	WPI_VictorSPX* rrVictor; // You don't actually have to read this (or the 2 above it, for that matter)

	TalonSRX* actualTalon;

//	frc::Talon* bkTalon;

	frc::VictorSP* lgrVic;
	frc::VictorSP* rgrVic;

	frc::Talon* liftTalon;

	WPI_VictorSPX* winchVictor1;
	WPI_VictorSPX* winchVictor2;

	frc::DigitalInput* topBkInput;
	frc::DigitalInput* botBkInput;

	frc::Victor* ballVic0;
	frc::Victor* ballVic1;

	frc::Encoder* flE;
	frc::Encoder* frE;
	frc::Encoder* rlE;
	frc::Encoder* rrE;

	frc::AnalogGyro* gyro;

	frc::Victor* uberDriver;
	frc::Victor* earpiece;

	frc::DigitalInput* lPhoto;
	frc::DigitalInput* rPhoto;

	frc::Relay* pneurelay;

	frc::Servo* grabServ;
	frc::MecanumDrive* rd;
}


void registerComponents(){ // Oh, here we actually define the hardware

	hw::stick = new frc::Joystick(0); // Initialize the joystick (see "Hardware.h")

	hw::actualTalon = new TalonSRX(1);

	hw::flVictor = new WPI_VictorSPX(3); // Initializes the Victor at port 0 to be the Front Left
	hw::frVictor = new WPI_VictorSPX(4); // Initializes the Victor at port 1 to be the Front Right
	hw::rlVictor = new WPI_VictorSPX(5); // Initializes the Victor at port 2 to be the Rear Left
	hw::rrVictor = new WPI_VictorSPX(6); // Initializes the Victor at port 3 to be the Rear Right

//	hw::bkTalon = new frc::Talon(9);		//Change these ports later!!

	hw::lgrVic = new frc::VictorSP(2);
	hw::rgrVic = new frc::VictorSP(1);

	hw::topBkInput = new frc::DigitalInput(7);	//Change ports later!!
	hw::botBkInput = new frc::DigitalInput(8);

	hw::liftTalon = new frc::Talon(6);			//Change ports later!!

	hw::winchVictor1 = new WPI_VictorSPX(1);		//Change ports later!!
	hw::winchVictor2 = new WPI_VictorSPX(2);

	hw::flE = new frc::Encoder(6, 7, false, Encoder::EncodingType::k2X);
	hw::frE = new frc::Encoder(3, 2, false, Encoder::EncodingType::k2X);
	hw::rlE = new frc::Encoder(4, 5, false, Encoder::EncodingType::k2X);
	hw::rrE = new frc::Encoder(1, 0, false, Encoder::EncodingType::k2X);

	hw::gyro = new frc::AnalogGyro(1);

	hw::uberDriver = new frc::Victor(4);
	hw::earpiece = new frc::Victor(5);

	hw::ballVic0 = new frc::Victor(9);

	hw::lPhoto = new DigitalInput(8);
	hw::rPhoto = new DigitalInput(9);

	hw::pneurelay = new frc::Relay(0);

	hw::grabServ = new frc::Servo(8);
	hw::rd = new MecanumDrive(*hw::flVictor, *hw::rlVictor, *hw::frVictor, *hw::rrVictor);
}

#endif /* SRC_HARDWARE_H_ */
