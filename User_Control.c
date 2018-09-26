int FourbarCtl;
int MogoCtl;
int IntakeCtl;
int LiftCtl;
int SpeedCtl;

task usercontrol()
{
	startTask( MotorSlewRateTask );
	startTask( tankDrive );
	startTask( pid_fourbar );
	isLiftPID = false;
	isFourbarAuto = false;

	// Reset LCD Display
	clearLCD(true);
	displayLCDCenteredString(0, "2360S");
	displayLCDCenteredString(1, "SubZERO");


	while (true)
	{
		// DR4B Lift Control
		LiftCtl = (vexRT[Btn6D] << 1) + vexRT[Btn6U];
		switch (LiftCtl)
		{
			case 1: // Btn6U
				leftsideLift(120);
				rightsideLift(120);
				break;
			case 2: // Btn6D
				leftsideLift(-120);
				rightsideLift(-120);
				break;
			default: //Do nothing when either both or neither are pressed
				leftsideLift(0);
				rightsideLift(0);
				break;
		}

		// Mobile goal controls
		MogoCtl = (vexRT[Btn8D] << 1) + vexRT[Btn8U];
		switch (MogoCtl)
		{
			case 1: // Btn8U
				moveMogo(110);
				break;
			case 2: // Btn8D
				moveMogo(-110);
				break;
			default: //Do nothing when either both or neither are pressed
				moveMogo(0);
				break;
		}


		// Roller Intake Controls
		IntakeCtl = (vexRT[Btn6DXmtr2] << 1) + vexRT[Btn6UXmtr2];
		switch (IntakeCtl)
		{
			case 1: // Btn6UXmtr2
				rollIntake(-120);
				break;
			case 2: // Btn6DXmtr2
				rollIntake(120);
				break;
			default: //Do nothing when either both or neither are pressed
				rollIntake(0);
				break;
		}


		// Fourbar Controls
		FourbarCtl = (vexRT[Btn7UXmtr2] << 3) + (vexRT[Btn7DXmtr2] << 2) + (vexRT[Btn5UXmtr2] << 1) + vexRT[Btn5DXmtr2];
		switch (FourbarCtl)
		{
			case 4: // Btn5Dmtr2
				/*disableCBPID();
				moveFourbar(120);*/
				setCBAngle(1800);
				break;
			case 8: // Btn5Umtr2
				disableCBPID();
				moveFourbar(-120 );
				break;
			case 1: //Btn7Dxmtr2, up
				disableCBPID();
				moveFourbar(120);
				break;
			case 2: //Btn7Uxmtr2, parallel
				setCBAngle(580);
				break;

			default: //Do nothing when either both or neither are pressed
				if (cb.enabled == false){
					moveFourbar(0);
				}
				break;
		}

		// Drive Speed Control
		SpeedCtl = (vexRT[Btn8RXmtr2] << 1) + vexRT[Btn8DXmtr2]  +(vexRT[Btn8UXmtr2] << 2);
		switch(SpeedCtl)
		{
			case 1: //Btn 8D
				kP_tank = 2; //Slow
				break;
			case 2: //Btn 8R
				kP_tank = 1.54; //Medium
				break;
			case 4: //Btn 8U
				kP_tank = 1.25; //Fast
				break;
			default:
			 break;
		}
		wait1Msec(20);
	}
}
