#include "Grab_Cone.c"

void auto2()
{
		desiredLiftTicks = 250; //Lift the lift
		grabMogo();
		rollIntake(127);
		grabCone();
		wait1Msec(100000);
		grabCone();
		drive_straight(-45);
		turnDegrees(isAutoLeft * 180);
		moveMogo(90);
		drive_straight(5);
		wait1Msec(500);
		moveMogo(0);
		drive_straight(-5);

		/*desiredLiftTicks = 200; //Lift the lift
		moveMogo(90); //Open the Mobile Goal
		drive_straight(50); //Drive straight to the mobile goal
		wait1Msec(800);
		moveMogo(0);
		desiredFourTicks = 480; //Move chainbar to up position
		moveMogo(-90);
		wait1Msec(1000);
		rollIntake(127); //Drop a preload on the mobile goal
		moveMogo(0);
		turnDegrees(isAutoLeft * 180); //Rotate 180 degrees to the right
		desiredFourTicks = 0;
		drive_straight(55); //Drive straight to the 10 point zone
		moveMogo(-90); //Open Mobile Goal to drop it
		drive_straight(-10); //Back up from the 5point zone

		moveMogo(0);*/


}
