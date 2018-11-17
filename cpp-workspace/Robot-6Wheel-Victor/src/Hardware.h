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

#ifdef OLD_BOT
	Victor* flVictor;
	Victor* frVictor;
	Victor* rlVictor;
	Victor* rrVictor;
#else
#ifdef PRAC_BOT
	Talon* flVictor;
	Talon* frVictor;
	Talon* rlVictor;
	Talon* rrVictor;

	WPI_TalonSRX* actualTalon;
	WPI_TalonSRX* actualTalon2;
#else
	frc::VictorSP* flVictor; // Same thing, just with a Victor
	frc::VictorSP* frVictor; // etc.
	frc::VictorSP* rlVictor; // This is getting boring...
	frc::VictorSP* rrVictor; // You don't actually have to read this (or the 2 above it, for that matter)

	WPI_TalonSRX* actualTalon;
	WPI_TalonSRX* actualTalon2;
#endif
#endif

	frc::Talon* liftTalon;

//	frc::Talon* bkTalon;

#ifdef PRAC_BOT
	frc::Spark* lgrVic;
	frc::Spark* rgrVic;
#else
	frc::VictorSP* lgrVic;
	frc::VictorSP* rgrVic;
#endif


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

	PigeonIMU* pigeon;
	Encoder* liE;
	DigitalInput* cs;

	frc::Victor* armVic1;
	frc::Victor* armVic2;

	frc::Victor* telescopeVic;

	frc::Encoder* telescopeEnc;
	frc::Encoder* armEnc;

	frc::Compressor* compressor1;
	frc::DoubleSolenoid* doubleSol1;
	frc::DoubleSolenoid* doubleSol2;
}


void registerComponents(){ // Oh, here we actually define the hardware

	hw::stick = new frc::Joystick(0); // Initialize the joystick (see "Hardware.h")

	hw::actualTalon = new WPI_TalonSRX(2);
	hw::actualTalon2 = new WPI_TalonSRX(3);

#ifdef OLD_BOT
	hw::flVictor = new Victor(0);
	hw::frVictor = new Victor(1);
	hw::rlVictor = new Victor(3);
	hw::rrVictor = new Victor(2);
	hw::flVictor->SetInverted(true);
	hw::frVictor->SetInverted(true);
#else
#ifdef PRAC_BOT
	hw::flVictor = new Talon(0); // Initializes the Victor at port 3 to be the Front Left
	hw::frVictor = new Talon(3); // Initializes the Victor at port 4 to be the Front Right
	hw::rlVictor = new Talon(1); // Initializes the Victor at port 5 to be the Rear Left
	hw::rrVictor = new Talon(2); // Initializes the Victor at port 6 to be the Rear Right
#else
	hw::flVictor = new frc::VictorSP(3); // Initializes the Victor at port 3 to be the Front Left
	hw::frVictor = new frc::VictorSP(4); // Initializes the Victor at port 4 to be the Front Right
	hw::rlVictor = new frc::VictorSP(5); // Initializes the Victor at port 5 to be the Rear Left
	hw::rrVictor = new frc::VictorSP(6); // Initializes the Victor at port 6 to be the Rear Right
#endif
#endif

//	hw::bkTalon = new frc::Talon(9);		//Change these ports later!!
#ifdef PRAC_BOT
	hw::lgrVic = new frc::Spark(5);
	hw::rgrVic = new frc::Spark(6);
#else
	hw::lgrVic = new frc::VictorSP(2);
	hw::rgrVic = new frc::VictorSP(1);
#endif

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


	hw::liE = new frc::Encoder(2, 3, false, Encoder::EncodingType::k2X);
	hw::cs = new DigitalInput(1);

	//hw::pigeon = new PigeonIMU(0);

	hw::armVic1 = new frc::Victor(1);	//CHANGE VIC ROBORIO PORT LATER!
	hw::armVic2 = new frc::Victor(2);	//CHANGE VIC ROBORIO PORT LATER!

	hw::telescopeVic = new frc::Victor(3); //CHANGE VIC ROBORIO PORT LATER!

	hw::telescopeEnc = new frc::Encoder(8, 9, false, Encoder::EncodingType::k2X);	//CHANGE ENCODER PORTS
	hw::armEnc = new frc::Encoder(10, 11, false, Encoder::EncodingType::k2X);

	hw::compressor1 = new frc::Compressor(2);	//CHANGE PCM NODE ID!

	hw::doubleSol1 = new frc::DoubleSolenoid {0,1};	//CHANGE PCM NODE ID!
	hw::doubleSol2 = new frc::DoubleSolenoid {6,7};	//CHANGE PCM NODE ID!
}

#endif /* SRC_HARDWARE_H_ */
