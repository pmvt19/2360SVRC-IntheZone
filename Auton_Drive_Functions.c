void drive_straight(float dist) // distance in inches
{
	SensorValue[leftDriveQuad] = 0;
	SensorValue[rightDriveQuad] = 0;
	int desiredDriveTicks = (dist/(4* PI))*392;
	while (abs(desiredDriveTicks - SensorValue[rightDriveQuad]) > 12) {
		leftsideDrive(80* atan(0.009 * (desiredDriveTicks + SensorValue[rightDriveQuad])));
		rightsideDrive(80* atan(0.009 * (desiredDriveTicks + SensorValue[rightDriveQuad])));
	}
	leftsideDrive(0);
	rightsideDrive(0);
}

void turnDegrees(float angle){

	SensorValue[in2] = 0;

	bool rightTurn = angle > 0;

	float previous = SensorValue[in2] / 10.0;
	float current = SensorValue[in2] / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const float speed = 60;
	float leftSpeed = rightTurn ? speed : -speed;
	float rightSpeed = -leftSpeed;

	const float K = 0.08;

	while( fabs(sum) < fabs(angle-3) ) {

		previous = current;
		current = SensorValue[in2] / 10.0;
		if(abs(current - previous) <= 180)
		{
		sum += current - previous;
		}
		angleDifference = fabs(angle) - fabs(sum);

		leftsideDrive(leftSpeed * atan(K * fabs(angleDifference) ));
		rightsideDrive( rightSpeed * atan(K * fabs(angleDifference)));
		wait1Msec(20);
	}
	leftsideDrive(0);
	rightsideDrive(0);
}

void turnDegreesSmall(float angle){

	SensorValue[in2] = 0;

	bool rightTurn = angle > 0;

	float previous = SensorValue[in2] / 10.0;
	float current = SensorValue[in2] / 10.0;
	float sum = 0;
	float angleDifference = angle;

	const float speed = 60;
	float leftSpeed = rightTurn ? speed : -speed;
	float rightSpeed = -leftSpeed;

	const float K = 0.1;

	while( fabs(sum) < fabs(angle-3) ) {

		previous = current;
		current = SensorValue[in2] / 10.0;
		if(abs(current - previous) <= 180)
		{
		sum += current - previous;
		}
		angleDifference = fabs(angle) - fabs(sum);

		leftsideDrive(leftSpeed * atan(K * fabs(angleDifference) ));
		rightsideDrive( rightSpeed * atan(K * fabs(angleDifference)));
		wait1Msec(20);
	}
	leftsideDrive(0);
	rightsideDrive(0);
}

void drive_straightS(float dist) // distance in inches
{
	SensorValue[leftDriveQuad] = 0;
	SensorValue[rightDriveQuad] = 0;
	int desiredDriveTicks = (dist/(4* PI))*392;
	while (abs(desiredDriveTicks - SensorValue[rightDriveQuad]) > 12) {
		leftsideDrive(50* atan(0.009 * (desiredDriveTicks + SensorValue[rightDriveQuad])));
		rightsideDrive(50* atan(0.009 * (desiredDriveTicks + SensorValue[rightDriveQuad])));
	}
	leftsideDrive(0);
	rightsideDrive(0);
}
