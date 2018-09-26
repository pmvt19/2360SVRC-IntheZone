void auto3()
{

		desiredLiftTicks = 200; //Lift the lift
		moveMogo(90); //Open the Mobile Goal
		drive_straight(47); //Drive straight to the mobile goal
		wait1Msec(800);
		moveMogo(0);
		wait1Msec(300);
		moveMogo(-100);
		wait1Msec(1000);
		moveMogo(0);
		setCBAngle(372);
		rollIntake(127); //Drop a preload on the mobile goal


		wait1Msec(500);
		desiredFourTicks = 0;


		rollIntake(0);

		drive_straight(-43);
		desiredFourTicks = 0;
		turnDegrees(isAutoLeft * 120); //Rotate 180 degrees to the left
		drive_straight(2); //Drive straight to the 10 point zone
		//rollIntake(127); //Drop the last cone
		//wait1Msec(500);
		desiredFourTicks = 0;
		turnDegrees(isAutoLeft * 90); //Turn to center position
		desiredFourTicks = 0;
		drive_straight(2);
		wait1Msec(200);
		moveMogo(60);
		drive_straight(15); //drive to center
		desiredFourTicks = 0;
		//turnDegrees(isAutoLeft* -90); //turn to face goals
		//drive_straight(15); //drive to 20 point zone
		moveMogo(-90);//Open Mobile Goal to drop it
		drive_straight(-6);
		moveMogo(0);
		wait1Msec(1000);
		drive_straight(-10); //Back up from the 20 point zone
		moveMogo(-90); //Pull up the mobile goal
		wait1Msec(1000);
		moveMogo(0);

}
