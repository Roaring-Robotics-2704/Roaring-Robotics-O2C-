/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;
import edu.wpi.first.wpilibj.PWMTalonSRX;
import edu.wpi.first.wpilibj.SpeedControllerGroup;
import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.command.Command;
import edu.wpi.first.wpilibj.command.CommandGroup;

/**
 * The VM is configured to automatically run this class, and to call the
 * functions corresponding to each mode, as described in the IterativeRobot
 * documentation. If you change the name of this class or the package after
 * creating this project, you must also update the build.gradle file in the
 * project.
 */
public class Robot extends IterativeRobot {
  private static final String kDefaultAuto = "Default";
  private static final String kCustomAuto = "My Auto";
  private String m_autoSelected;
  private final SendableChooser<String> m_chooser = new SendableChooser<>();
  
  public DifferentialDrive drive; // tank drive interface

  public SpeedControllerGroup left; // needed for PID
  public SpeedControllerGroup right;

  public Joystick js; // represents client joystick

  /*
    Defines what the robot should be doing in each mode.
  */
  private CommandGroup autonomousCommands;
  private CommandGroup driverCommands;

  /**
   * This function is run when the robot is first started up and should be
   * used for any initialization code.
   */
  @Override
  public void robotInit() {
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

  public void stopLogic() {
    if (autonomousCommands.isRunning()) {
      autonomousCommands.cancel();
    }
    if (driverCommands.isRunning()) {
      driverCommands.cancel();
    }
  }

  /**
   * Run on every autonomous begin.
   */
  @Override
  public void autonomousInit() {
    stopLogic();
    autonomousCommands.start();
  }

  /**
   * Run on every teleoperator begin.
   */
  @Override
  public void teleopInit() {
    stopLogic();
    driverCommands.start();
  }

  /**
   * This function is called periodically during test mode.
   */
  @Override
  public void testPeriodic() {
  }
}
