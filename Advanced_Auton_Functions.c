// Proportional-Integral-Derivative(PID) Control Algorithim to accurately hold/move the lift to any position
task PID_Lift()
{
	//Setup the constants for the P, I, and D aspects of the control loop
	//constants determined through experimentation
	const float leftkP = 0.4;
	const float leftkI = 0.002;
	const float leftkD = 0.3;
	const float rightkP = 0.297;
	const float rightkI = 0.002;
	const float rightkD = 0.24;
	int leftError;
	int rightError;
	int leftPrevError = 0 ;
	int rightPrevError = 0;
	int leftIntegral = 0;
	int rightIntegral = 0;
	int leftDeriv;
	int rightDeriv;
	int left_power;
	int right_power;
	while(true)
	{
		//Checks if the the PID control algorithim should be activated or not
		if (isLiftPID == true){
			//Proportional component, calculates the difference between the desired position and the robot's current position
			leftError = desiredLiftTicks - SensorValue[leftLiftQuad];
			rightError = desiredLiftTicks + SensorValue[rightLiftQuad];
			//Integral component, sums up the errors to account for smaller values of error that cannot be rectified
			leftIntegral = leftIntegral + leftError;
			rightIntegral = rightIntegral + rightError;
			//Derivative component, predicts future error by taking the difference of the current and previous error, prevents overshoot
			leftDeriv = leftError-leftPrevError;
			rightDeriv = rightError - rightPrevError;
			//resets the integral component if it becomes too high
			if (rightIntegral > 1000){
				rightIntegral = 0;
			}
			if (leftIntegral > 1000){
				leftIntegral = 0;
			}

			leftPrevError = leftError;
			rightPrevError = rightError;
			//multiply each component by each its repective constant and send it to the motors
			left_power = leftError*leftkP + leftIntegral*leftkI + leftDeriv* leftkD;
			right_power = rightError*rightkP + rightIntegral*rightkI + rightDeriv* rightkD;
			//send power to the motors
			leftsideLift(left_power);
			rightsideLift(right_power);
		}
		wait1Msec(MOTOR_TASK_DELAY);
	}
}


typedef struct {

	bool enabled;

	float KP;
	float KI;
	float KD;

	float target;

	float output;

	float error;
	float prevError;

	float proportion;
	float integral;
	float derivative;

} PIDController;

PIDController cb;

void setCBAngle(const float angle) {
	cb.enabled = true;
	cb.target = angle;
}

void disableCBPID() {
	cb.enabled = false;
}

// Arctangent Control Algorithim to accurately hold/move the lift to any position
task pid_fourbar()
{
		//chain bar
	cb.KP = 0.2;
	cb.KI = 0.;
	cb.KD = 0.5;
	while(true)
	{
		cb.prevError = cb.error; //Set the current error to the previous error
		cb.error = cb.target - (SensorValue[fourPot]);

		cb.proportion = cb.error * cb.KP; //Calculate the proportion
		cb.integral += cb.prevError * cb.KI;
		cb.derivative = (cb.error - cb.prevError) * cb.KD; //Calculate the derivative

		cb.output = cb.proportion + cb.integral + cb.derivative; //Calculate the output
		cb.output = cb.output > 127 ? 127 : (cb.output < -127 ? -127 : cb.output);

		if(cb.enabled){
			motor[fourbar] = cb.output;
	}
	wait1Msec(20);
}}
