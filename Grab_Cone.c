void grabCone()
{
		desiredLiftTicks = 250;
		//drive_straight(3);
		wait1Msec(500);
		setCBAngle(1800);
		wait1Msec(500);
		rollIntake(-100);
		desiredLiftTicks = 0;
		wait1Msec(500);
		rollIntake(0);
		desiredLiftTicks = 300;
		wait1Msec(500);

		setCBAngle(200);
		wait1Msec(500);
		desiredLiftTicks = 0;
		wait1Msec(500);
		rollIntake(127);
		desiredLiftTicks = 200;
}

void grabMogo()
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
	}
