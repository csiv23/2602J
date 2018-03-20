#pragma config(Sensor, in1,    LeftPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in2,    CenterLine,     sensorLineFollower)
#pragma config(Sensor, in3,    RightPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in4,    GyroSensor,     sensorGyro)
#pragma config(Sensor, in6,    LeftLine,       sensorLineFollower)
#pragma config(Sensor, in7,    RightLine,      sensorLineFollower)
#pragma config(Sensor, dgtl3,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightMobileGoal, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightTipper,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftSideDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftTipper,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftMobileGoal, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("Globals")
#pragma DebuggerWindows("Motors")



void baseControl (int speed)
{
		motor[leftSideDrive] = speed;
		motor[rightSideDrive] = speed;
}

//reading: ticks -- 627.2ticks/revolution
// 1 turn of the wheels -- 4 inch wheels = 627.2 *2 ticks
//1 turn of each wheel 4*pi inches
//4*pi inches = 627.2*2 ticks

//ticks/inch = 627.2 * 2 /4*pi= 99.82198


int inchToTicks (float inch)
{
		int ticks;
		ticks = inch*99.82198;
		return ticks;
 }

int fixTimerValue (float rawSeconds)
{
	int miliseconds;
	miliseconds = rawSeconds*1000;
	if (miliseconds < 250)
	{
			miliseconds = 250;
	}
	return miliseconds;
}
void PIDBaseControl (float target, float waitTime, float maxPower = 1)
{
		float Kp = 0.26;
		float Ki = 0;
		float Kd = 0.05;

		int error;

		float proportion;
		int integralRaw;
		float integral;
		int lastError;
		int derivitave;

		float integralActiveZone = inchToTicks(3);


		int finalPower;

		bool timerBool = true;

		SensorValue(LeftEncoder) = 0;
		SensorValue(RightEncoder) = 0;


		clearTimer(T1);

		while(time1[T1] < fixTimerValue(waitTime))
		{
			error = inchToTicks(target) - (SensorValue[RightEncoder]) +(SensorValue[LeftEncoder]);

			proportion = Kp*error;

			if (abs(error) < integralActiveZone && error != 0)
			{
				integralRaw = integralRaw+error;
			}
			else
			{
				integralRaw = 0;
			}

			integral = Ki*integralRaw;

			derivitave = Kd*(error-lastError);
		 	lastError = error;

		 	if (error == 0)
		 	{
		 			derivitave = 0;
			}

			finalPower = proportion+integral+derivitave; //proportion+derivitave + intergral

			if(finalPower > maxPower*127)
			{
				finalPower = maxPower*127;
			}
			else if(finalPower < -maxPower*127)
			{
				finalPower= -maxPower*127;
			}

			baseControl(finalPower);

			wait1Msec(40);

			if (error < 30)
			{
					timerBool = false;
			}

			if (timerBool)
			{
				clearTimer(T1);
			}
	}
	baseControl(0);
}



task main()
{
	SensorValue(RightEncoder) = 0;
	SensorValue(LeftEncoder) = 0;

	PIDBaseControl(1, 0, 1); //move forward 12 inches with 1 sec delay 70% power;


	while(1 == 1)
			{
				if(SensorValue[RightEncoder] >= 360)
{
	motor[leftSideDrive] = 0;
	motor[rightSideDrive] = 0;

}

			}
}
