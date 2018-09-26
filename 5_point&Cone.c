#include "Grab_Cone.c"
void auto1()
{
		grabMogo();
		setCBAngle(372);
		rollIntake(127); //Drop a preload on the mobile goal
		wait1Msec(500);
		desiredFourTicks = 0;
		rollIntake(0);
		//drive_straightS(4);
		//grabCone();
		//drive_straight(4);
		//turnDegrees(isAutoLeft * 20);
		//drive_straight(4);
		//grabCone();
		//drive_straight(-10);
		turnDegrees(isAutoLeft * 180);
		drive_straight(13);
		//turnDegrees(isAutoLeft * 22);
		moveMogo(90);
		wait1Msec(1000);
		moveMogo(0);
		drive_straight(-5);




}
