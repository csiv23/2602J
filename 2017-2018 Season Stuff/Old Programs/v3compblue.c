#pragma config(Sensor, dgtl3,  RightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  LeftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightMobileGoal, tmotorVex393_MC29, openLoop, reversed)
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
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
int forwards;
int backwards;
int nada;

forwards = 95;
backwards = -95;
nada = 0;

{
		motor[rightSideDrive] = 58;
		motor[leftSideDrive] = forwards;
		wait1Msec(2400);
		//drives forwards to mobile goal
		motor[rightSideDrive] = 0;
		motor[leftSideDrive] = 0;
		wait1Msec(1000);
		//stops
		motor[gripMotor] = forwards;
		wait1Msec(500);
		//drops preload onto mobile goal
		motor[gripMotor] = nada;
		wait1Msec (750);
		//stops passive intake
		motor[rightMobileGoal] = backwards;
		motor[leftMobileGoal] = -115;
		wait1Msec(750);
		//mobile goal lift picks up mobile goal
		motor[rightSideDrive] = -58;
		motor[leftSideDrive] = backwards;
		wait1Msec(2000);
		//robot goes in reverse
		motor[rightSideDrive] = backwards;
	motor[leftSideDrive] = nada;
	wait1Msec(2100);
	//robot turns and points towards corner
	motor[rightSideDrive] = nada;
	motor[leftSideDrive] = nada;
	wait1Msec(500);
	//robot stops
	motor[rightSideDrive] = 78;
	motor[leftSideDrive] = 125;
	wait1Msec(3000);
	//goes towards zone
	motor[rightSideDrive] = nada;
	motor[leftSideDrive] = nada;
	wait1Msec(1000);
	//stops
	motor[leftMobileGoal] = forwards;
		motor[rightMobileGoal] = forwards;
		wait1Msec(1000);
		//drops mobile goal
		motor[leftMobileGoal] = nada;
		motor[rightMobileGoal] = nada;
		wait1Msec(1000);
		//stops
		motor[rightSideDrive] = -70;
 motor[leftSideDrive] = -120;
 wait1Msec(1000);
 //backs up
 motor[rightSideDrive] = nada;
 motor[leftSideDrive] = nada;
 //stops
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
	int forwards;
	int lessforwards;
	int backwards;
	int lessbackwards;
	int nada;


	forwards = 95;
	lessforwards = 85;
	backwards = -95;
	lessbackwards = -85;
	nada = 0;


	while (true)
	{
		motor[rightSideDrive] = vexRT[Ch2];
		motor[leftSideDrive] = vexRT[Ch3];
		motor[turntableMotor] = vexRT[Ch4Xmtr2];

		if(vexRT[Btn8LXmtr2] == 1)
		{
			motor[liftExtension] = forwards;
			motor[mainLift] = forwards;
		}
		else if(vexRT[Btn8DXmtr2] == 1)
		{
			motor[liftExtension] = backwards;
			motor[mainLift] = backwards;
		}
		else
		{
			motor[liftExtension] = nada;
			motor[mainLift] = nada;
		}
		if(vexRT[Btn5UXmtr2] == 1)
		{
			motor[rightMobileGoal] = forwards;
			motor[leftMobileGoal] = forwards;
		}
		else if(vexRT[Btn5DXmtr2] == 1)
		{
			motor[rightMobileGoal] = backwards;
			motor[leftMobileGoal] = backwards;
		}
		else
		{
			motor[rightMobileGoal] = nada;
			motor[leftMobileGoal] = nada;
		}
		if(vexRT[Btn6UXmtr2] == 1)
		{
			motor[gripMotor] = forwards;
		}
		else if(vexRT[Btn6DXmtr2] == 1)
		{
			motor[gripMotor] = backwards;
		}
		else
		{
			motor[gripMotor] = nada;
		}
	}
}