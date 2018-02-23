/*
 * Don't actually edit this file unless you know what you're doing. It's tested and works just fine!
 * If this appears to be broken, it's probably your own code or something...
 */
#ifndef SRC_ROBOT_H // Test if Robot.h has been loaded yet (this is the "include guard" - I have one in every file except Main.cpp)
#define SRC_ROBOT_H // It has now!

#define PI 3.14159265359

bool isLifting = false;

namespace RobotPrivate {
	bool lOver1 = false;
	bool lOver2 = false;
	bool lOver3 = false;
	bool debugMode = false;
	long long debugKey = 0;
	int debugIx = 0;
	bool trainingMode = false;
}

bool isDebugMode(){
	return RobotPrivate::debugMode;
}
bool isTrainingMode(){
	return RobotPrivate::trainingMode;
}

// Load necessary files

#include <WPILib.h>
#include <iostream> // Allows us to output debugging information to the DriverStation
#include <memory> // Allows for dynamic memory allocation. This is used for maintaining a list of robot modules
#include <string> // "Hello, world" or something like that
#include <vector>

#include <fstream>

#include <ctre/Phoenix.h>

#include <Joystick.h> // he
#include <SampleRobot.h> // The base of the robot code (as far as defined by WPILib)
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>
//#include <RobotDrive.h> // We don't actually use this, I don't know why it's still here
#include <Timer.h> // Allows for creating waits in the code
#include <Victor.h> // You should know what this is for...
#include <Encoder.h>
#include <AnalogGyro.h>
#include <math.h>
#include <map>

#include "Hardware.h" // Load the robot's hardware from Hardware.h
#include "Module.h" // Load the robot module template. See the module code in other files

#include "unregisteredModules/libc.h"
#include "unregisteredModules/RobotStatus.h"

#include "modules/Autonomous.h"

// Done loading necessary files

void* voidpRobotInstance; // This will later point to the Robot's instance so that other things can call to the Robot class
namespace RobotPrivate{
	int registeredModules = 0; // We don't have any modules loaded yet
	Module** modules = NULL; // A pointer to a module pointer (this can get a bit confusing) being used as an array of modules
}

/*
 * The robot's main class. This needs to extend one of SampleRobot, IterativeRobot, or CommandRobot. I chose to extend SampleRobot
 */
class Robot: public frc::SampleRobot { // Creates a robot that extends the WPILib SampleRobot (SampleRobot gives more control over
										// what the robot actually does, despite the fact that we don't use that extra control)
private:
	// Nothing was needed here. Oh, well...
public:
	Robot() {
		std::cout << "Creating robot instance...\n"; // std::cout declares a print statement. It's just the C++ way of writing it.
		voidpRobotInstance = this; // Create a reference to this robot so other code can talk to it
		//Note SmartDashboard is not initialized here, wait until RobotInit to make SmartDashboard calls
		std::cout << "Created robot instance.\n";
	}
	void RobotInit_() { // Read to the bottom before looking at this
		std::cout << "Initializing robot hardware...";
		registerComponents();
		CameraServer::GetInstance()->StartAutomaticCapture();
		std::cout << "Initialized robot hardware.";
		std::cout << "Initializing modules...";
		for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
			Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
			module->ModuleInit(); // Runs the module's init code
		}
		std::cout << "Initialized robot modules.";
	}

	virtual void RobotInit(); // This will be given something to do later, hence being `virtual`

	/*
	 * This is called once when the robot switches to Autonomous mode.
	 */
	void Autonomous() {
		for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
			Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
			module->ModeChange(); // Runs the module's Autonomous code
		}
		while (IsAutonomous() && IsEnabled()) { // Check that the robot should still run Autonomous code
			for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
				Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
				module->Autonomous(); // Runs the module's Autonomous code
			}
			frc::Wait(0.005); // Wait for the motors to update
		}
	}

	/*
	 * This is called once when the robot switches to TeleOp mode
	 */
	void OperatorControl() override {
		for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
			Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
			module->ModeChange(); // Runs the module's Autonomous code
		}
		while (IsOperatorControl() && IsEnabled()) { // Check that the robot should still run TeleOp code
			for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
				Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
				module->OperatorControl(); // Runs the module's TeleOp code
			}
#ifdef CONTROLLER_ALT_1
			bool overBtn1 = hw::stick->GetRawButton(12);
			bool overBtn2 = hw::stick->GetRawButton(11);
			bool b1 = false;
			bool b2 = false;
			if(overBtn1){
				if(!RobotPrivate::lOver1){
					b1 = true;
				}
				RobotPrivate::lOver1 = true;
			} else{
				RobotPrivate::lOver1 = false;
			}
			if(overBtn2){
				if(!RobotPrivate::lOver2){
					b2 = true;
				}
				RobotPrivate::lOver2 = true;
			} else{
				RobotPrivate::lOver2 = false;
			}
			if(overBtn1 && overBtn2){
				if(!RobotPrivate::lOver3){
					switch(RobotPrivate::debugKey){
					case 0b1001:
						if(!RobotPrivate::debugMode){
							RobotPrivate::debugMode = true;

							std::cout << "Debug mode activated.\n";
						} else{
							RobotPrivate::debugMode = false;
							std::cout << "Debug mode is now disabled.\n";
						}
						break;
					case 0b101:
						if(!RobotPrivate::trainingMode){
							std::cout << "Autonomous training mode activated.\n";
							RobotPrivate::trainingMode = true;
							for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
								Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
								module->ClearAuto(); // Runs the module's Autonomous code
							}
							AutonomousMain::save();
							RobotStatus::autonomousSaveStatus = false;
						} else{
							std::cout << "Autonomous training mode is now disabled: " << RobotPrivate::debugKey << "\n";
							RobotPrivate::trainingMode = false;
							AutonomousMain::save();
						}
						break;
					default:
						RobotPrivate::debugMode = false;
						RobotPrivate::trainingMode = false;
						AutonomousMain::save();
					}
					RobotPrivate::debugKey = 0;
					RobotPrivate::debugIx = 0;
					RobotPrivate::lOver3 = true;
				}
			} else if(b1){
				long long a = 1 << (RobotPrivate::debugIx ++);
				RobotPrivate::debugKey ^= a;
			} else if(b2){
				long long a = 0 << (RobotPrivate::debugIx ++);
				RobotPrivate::debugKey ^= a;
			}
			if(!(overBtn1 && overBtn2)){
				RobotPrivate::lOver3 = false;
			}

#else
			// Nothing here, yet
#endif
					frc::Wait(0.005); // Wait for the motors to update
		}
	}

	/*
	 * Runs during test mode
	 */
	void Test() override {
		for(int a=0; a<RobotPrivate::registeredModules; a++){ // Loops through the registered modules (see the module code)
			Module* module = RobotPrivate::modules[a]; // Creates temporary variable `module` and sets it to the current module
			module->ModeChange(); // Runs the module's Autonomous code
		}
		// Do nothing (We're too cool for automated tests)
	}

	void registerModule(Module* module){ // Loads a module for the robot to run
		RobotPrivate::modules = (Module**) realloc(RobotPrivate::modules, ++RobotPrivate::registeredModules * sizeof(Module*));
			// ^^^ Increases the module list's size to allow for the storing of the new module, keeping the existing contents
		RobotPrivate::modules[RobotPrivate::registeredModules-1] = module; // Sets the module list's last element to the new module
		AutonomousMain::registerAutoModule(module);
	}
};

Robot* robot = (Robot*) voidpRobotInstance; // Finally, declare the robot reference to actually be a Robot

#include "ModuleLoader.h" // Waiting to include Robot-dependent code until we actually have a Robot

void Robot::RobotInit(){

	std::cout << "Initializing robot modules...\n";
	loadModules(); // Loads all the modules from "ModuleLoader.h"
	RobotInit_(); // Finishes the robot init process (look toward the top  of this file)
	CameraServer::GetInstance()->StartAutomaticCapture();

}

#endif // Ends the include guard, and Robot.h
