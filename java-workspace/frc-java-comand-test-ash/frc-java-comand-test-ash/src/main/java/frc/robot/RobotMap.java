/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
public class RobotMap {
  // For example to map the left and right motors, you could define the
  // following variables to use with your drivetrain subsystem.
  // public static int leftMotor = 1;
  // public static int rightMotor = 2;

  // If you are using multiple modules, make sure to define both the port
  // number and the module. For example you with a rangefinder:
  // public static int rangefinderPort = 1;
  // public static int rangefinderModule = 1;
  public DifferentialDrive drive; // tank drive interface

  public SpeedControllerGroup left; // needed for PID
  public SpeedControllerGroup right;

  
  public static void init(){
     // initialize hardwares
    this.left = new SpeedControllerGroup(new PWMTalonSRX(1),new PWMTalonSRX(0)); // left motors 
    this.right = new SpeedControllerGroup(new PWMTalonSRX(2),new PWMTalonSRX(3)); // right motors 
    this.drive = new DifferentialDrive(left,right);
    this.js = new Joystick(0);
    // initialize command groups
    autonomousCommands = new CommandGroup("autonomousCommands");
    driverCommands = new CommandGroup("driverCommands");

    // initialize tank drive controls
    CommandTankDrive td = new CommandTankDrive();
    td.setRobot(this);
    driverCommands.addSequential(td);
  }
}
