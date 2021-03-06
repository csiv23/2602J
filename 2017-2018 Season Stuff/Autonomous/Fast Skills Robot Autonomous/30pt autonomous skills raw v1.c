#pragma config(Sensor, in1,    LeftPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in3,    RightPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in5,    LeftLine,       sensorLineFollower)
#pragma config(Sensor, in6,    CenterLine,     sensorLineFollower)
#pragma config(Sensor, in7,    RightLine,      sensorLineFollower)
#pragma config(Sensor, dgtl3,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightMobileGoal, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mainLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           turntableMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftSideDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           gripMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           liftExtension, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftMobileGoal, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void baseControl(int leftPower, int rightPower)
{
	motor[leftSideDrive] = leftPower;
	motor[rightSideDrive] = rightPower;
}

void liftControl (int leftLift, int rightLift)
{
	motor[leftMobileGoal] = leftLift;
	motor[rightMobileGoal] = rightLift;
}


	task Straighten()
{

int difference;
int leftStart;
int rightStart;


leftStart = 95;
rightStart = 127;


SensorValue(RightEncoder) = 0;
SensorValue(LeftEncoder) = 0;


	while(1 == 1)
	{
		difference = abs(SensorValue(LeftEncoder) - SensorValue(RightEncoder))/1000;

		if(SensorValue(RightEncoder) == SensorValue(LeftEncoder))
		{
			baseControl(leftStart, rightStart);
		}

		if(SensorValue(RightEncoder) > SensorValue(LeftEncoder))
		{
			baseControl(leftStart, (rightStart - difference));
		}

		if(SensorValue(LeftEncoder) > SensorValue(RightEncoder))
		{
			baseControl((leftStart - difference), rightStart);
		}
	}
}

task BackStraighten()
{
float difference;
float leftStart;
float rightStart;


leftStart = -57.5;
rightStart = -47.5;


SensorValue(RightEncoder) = 0;
SensorValue(LeftEncoder) = 0;

	while(1 == 1)
	{

		difference = abs(SensorValue(LeftEncoder) - SensorValue(RightEncoder))/1000;

		if(SensorValue(RightEncoder) == SensorValue(LeftEncoder))
		{
			baseControl(leftStart, rightStart);
		}

		if(SensorValue(RightEncoder) > SensorValue(LeftEncoder))
		{
			baseControl(leftStart, (rightStart - difference));
		}

		if(SensorValue(LeftEncoder) > SensorValue(RightEncoder))
		{
			baseControl((leftStart - difference), rightStart);
		}
	}
}

task BackStraightenFast()
{
float difference;
float leftStart;
float rightStart;


leftStart = -101;
rightStart = -95;


SensorValue(RightEncoder) = 0;
SensorValue(LeftEncoder) = 0;

	while(1 == 1)
	{

		difference = abs(SensorValue(LeftEncoder) - SensorValue(RightEncoder))/1000;

		if(SensorValue(RightEncoder) == SensorValue(LeftEncoder))
		{
			baseControl(leftStart, rightStart);
		}

		if(SensorValue(RightEncoder) > SensorValue(LeftEncoder))
		{
			baseControl(leftStart, (rightStart - difference));
		}

		if(SensorValue(LeftEncoder) > SensorValue(RightEncoder))
		{
			baseControl((leftStart - difference), rightStart);
		}
	}
}


task main()
{
	{
		liftControl (127, 127);
	wait1Msec(750);
	//bring out mobile goal

	liftControl (0, 0);
	wait1Msec(100);
	//stop

	startTask(Straighten);
	baseControl (127, 127);
	wait1Msec(1950);
	stopTask(Straighten);
	//drive to mobile goal

	baseControl (0,0);
	wait1Msec(250);
	//stop

	motor[rightMobileGoal] = -100;
	motor[leftMobileGoal] = -100;
	wait1Msec(600);
	//mobile goal grabs cone

	motor[rightMobileGoal] = 0;
	motor[leftMobileGoal] = 0;
	wait1Msec(100);
	//stop

	startTask(BackStraighten);
	baseControl (-127, -127);
	wait1Msec(1750);
	//back up

	baseControl (-127, -127);
  untilLight (2951, in6);
  stopTask(BackStraighten);
	//back up to line

	baseControl(-100, -25);
	wait1Msec(1250);
	//first pivot

	baseControl(0, 0);
	wait1Msec(100);
	//quick stop

	baseControl(-50, 50);
wait1Msec(650);
//2nd pivot

baseControl(0, 0);
wait1Msec(200);
//quick stop

startTask(Straighten);
baseControl(80, 80);
wait1Msec(1450);
stopTask(Straighten);
//drive to 20 pt

baseControl(0, 0);
wait1Msec(100);
//stops

liftControl(90, 90);
wait1Msec(75);
//places mobile goal in 20pt zone

liftControl(0, 0);
wait1Msec(50);
//stop lift

liftControl(-90, -90);
wait1Msec(75);
//pull out

liftControl(0, 0);
wait1Msec(50);
//stop lift

baseControl(0, 0);
wait1Msec(100);
//stop

startTask(BackStraightenFast);
baseControl(-127, -127);
wait1Msec(1000);
//back up


baseControl(-127, -127);
untilDark(2951, in6);
stopTask(BackStraightenFast);
//back up straight out of 20pt zone

baseControl(0, 0);
liftControl(0, 0);
wait1Msec(100);
//stop

	startTask(Straighten);
	baseControl(127, 127);
	wait1Msec(150);
	stopTask(Straighten);
	//forwards straighten


	baseControl(0, 0);
	wait1Msec(100);
	//stop

	baseControl(-100, 127);
	wait1Msec(385);
	//face wall (PIVOT)

	startTask(BackStraightenFast);
	baseControl(-127, -127);
	wait1Msec(1675);
	stopTask(BackStraightenFast);




}
}
