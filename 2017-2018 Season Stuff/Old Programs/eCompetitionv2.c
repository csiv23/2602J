#pragma config(Sensor, in1,    LeftPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in3,    RightPotentiometer, sensorPotentiometer)
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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	bStopTasksBetweenModes = true;
}

/*---------------------------------------------------------------------------*/
/*                                                                            */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void baseControl(int leftPower, int rightPower)
{
	motor[leftSideDrive] = leftPower;
	motor[rightSideDrive] = rightPower;
}

task autonomous()
{

int forwards;
int backwards;
int nada;

forwards = 127;
backwards = -127;
nada = 0;

SensorValue[RightEncoder] = 0;
SensorValue[LeftEncoder] = 0;
//resets sensors
while(SensorValue[LeftEncoder] < 1370)
{
baseControl(forwards, forwards,);
}
}





/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	while(1==1)
	{
		motor[leftSideDrive] = vexRT[Ch3];
		motor[rightSideDrive] = vexRT[Ch2];

	if(SensorValue[RightPotentiometer] <= 520)
	{
		if(vexRT[Btn6D] == 1)
		{
			motor[rightMobileGoal] = 127;
			motor[leftMobileGoal] = 127;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[rightMobileGoal] = 0;
			motor[leftMobileGoal] = 0;
		}
		else
		{
			motor[rightMobileGoal] = 0;
			motor[leftMobileGoal] = 0;
		}
	}
	else if(SensorValue[RightPotentiometer] >= 1150)
	{
		if(vexRT[Btn6D] == 1)
		{
			motor[rightMobileGoal] = 0;
			motor[leftMobileGoal] = 0;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[rightMobileGoal] = -127;
			motor[leftMobileGoal] = -127;
		}
		else
		{
			motor[rightMobileGoal] = 0;
			motor[leftMobileGoal] = 0;
		}
	}
	else
	{
		if(vexRT[Btn6D] == 1)
		{
			motor[rightMobileGoal] = 127;
			motor[leftMobileGoal] = 127;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[rightMobileGoal] = -127;
			motor[leftMobileGoal] = -127;
		}
		else
		{
			motor[rightMobileGoal] = 0;
			motor[leftMobileGoal] = 0;
		}
	}
}
}