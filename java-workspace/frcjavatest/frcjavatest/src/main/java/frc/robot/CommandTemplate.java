package frc.robot;
import edu.wpi.first.wpilibj.command.Command;

public class CommandTemplate extends Command {

    private Robot robot;
    public void setRobot(Robot robot) { // gives this command access to hardware.
        this.robot=robot;
    }

    /**
    * The initialize method is called the first time this Command is run after being started.
    */
    @Override
    protected void initialize() {
        // Your initialization code here.
    }

    /**
    * The execute method is called repeatedly until this Command either finishes or is canceled.
    */
    @SuppressWarnings("MethodName")
    @Override
    protected void execute() {
        // Your execution code here.
    }

    /**
    * Returns whether this command is finished. If it is, then the command will be removed and {@link
    * Command#end() end()} will be called.
    *
    * <p>It may be useful for a team to reference the {@link Command#isTimedOut() isTimedOut()}
    * method for time-sensitive commands.
    *
    * <p>Returning false will result in the command never ending automatically. It may still be
    * cancelled manually or interrupted by another command. Returning true will result in the
    * command executing once and finishing immediately. We recommend using {@link InstantCommand}
    * for this.
    *
    * @return whether this command is finished.
    * @see Command#isTimedOut() isTimedOut()
    */
    protected boolean isFinished() {
        return false; // Change to your own code.
    }

    /**
    * Called when the command ended peacefully. This is where you may want to wrap up loose ends,
    * like shutting off a motor that was being used in the command.
    */
    protected void end() {
        // Your termination code here.
    }

    /**
    * Called when the command ends because somebody called {@link Command#cancel() cancel()} or
    * another command shared the same requirements as this one, and booted it out.
    *
    * <p>This is where you may want to wrap up loose ends, like shutting off a motor that was being
    * used in the command.
    *
    * <p>Generally, it is useful to simply call the {@link Command#end() end()} method within this
     * method, as done here.
    */
    protected void interrupted() {
        end();
    }
}