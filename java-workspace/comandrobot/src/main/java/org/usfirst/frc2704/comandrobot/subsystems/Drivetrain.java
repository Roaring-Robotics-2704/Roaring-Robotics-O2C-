// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// Java from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


package org.usfirst.frc2704.comandrobot.subsystems;


import org.usfirst.frc2704.comandrobot.commands.*;
import edu.wpi.first.wpilibj.livewindow.LiveWindow;
import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.PIDOutput;
import edu.wpi.first.wpilibj.PIDSource;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=IMPORTS
import edu.wpi.first.wpilibj.PWMTalonSRX;
import edu.wpi.first.wpilibj.SpeedController;
import edu.wpi.first.wpilibj.SpeedControllerGroup;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=IMPORTS


/**
 *
 */
public class Drivetrain extends Subsystem {

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    private PWMTalonSRX rightfront;
    private PWMTalonSRX rightrear;
    private SpeedControllerGroup speedControllerGroup1;
    private PWMTalonSRX leftfront;
    private PWMTalonSRX leftrear;
    private SpeedControllerGroup speedControllerGroup2;
    private DifferentialDrive differentialDrive1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    public Drivetrain() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
        rightfront = new PWMTalonSRX(0);
        addChild("right front",rightfront);
        rightfront.setInverted(false);
        
        rightrear = new PWMTalonSRX(2);
        addChild("right rear",rightrear);
        rightrear.setInverted(false);
        
        speedControllerGroup1 = new SpeedControllerGroup(rightfront, rightrear  );
        addChild("Speed Controller Group 1",speedControllerGroup1);
        
        
        leftfront = new PWMTalonSRX(5);
        addChild("left front",leftfront);
        leftfront.setInverted(false);
        
        leftrear = new PWMTalonSRX(4);
        addChild("left rear",leftrear);
        leftrear.setInverted(false);
        
        speedControllerGroup2 = new SpeedControllerGroup(leftfront, leftrear  );
        addChild("Speed Controller Group 2",speedControllerGroup2);
        
        
        differentialDrive1 = new DifferentialDrive(speedControllerGroup2, speedControllerGroup1);
        addChild("Differential Drive 1",differentialDrive1);
        differentialDrive1.setSafetyEnabled(true);
        differentialDrive1.setExpiration(0.1);
        differentialDrive1.setMaxOutput(1.0);

        

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    }
    public void takejoystickinputs(Joystick joystick1){
        differentialDrive1.tankDrive(joystick1.getX(), joystick1.getY());
    }
    public void stop(){
        differentialDrive1.tankDrive(0, 0);
    }
    @Override
    public void initDefaultCommand() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        // Set the default command for a subsystem here.
        // setDefaultCommand(new MySpecialCommand());
    }

    @Override
    public void periodic() {
        // Put code here to be run every loop

    }

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // Put methods for controlling this subsystem
    // here. Call these from Commands.

}
