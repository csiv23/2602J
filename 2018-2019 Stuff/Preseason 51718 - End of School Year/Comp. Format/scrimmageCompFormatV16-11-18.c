#pragma config(Motor,  port2,           rightSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftSideDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
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

void baseControl(int leftSpeed, int rightSpeed, int baseTime)
{
	motor[leftSideDrive] = leftSpeed;
	motor[rightSideDrive] = rightSpeed;
	baseTime = wait1Msec(baseTime);
}

task autonomous()
{
	baseControl(-127, -127, 2000);
	//drive backwards to flag

	baseControl(0, 0, 250);
	//breif pause

	baseControl(127, 127, 2000);
	//drive to starting position

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


int reverseStatus = 0;


task Battery()
{
bLCDBacklight = true;
string mainBattery, backupBattery;

while(true)
{
	clearLCDLine(0);
	clearLCDLine(1);

	//display

	displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	displayNextLCDString(mainBattery);

	displayLCDString(1, 0, "Backup:  ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0,'V');
	displayNextLCDString(backupBattery);

	wait1Msec(100);
}
}

task Forwards()
{
	while(1==1)
	{
	motor[leftSideDrive] = vexRT[Ch3];
	motor[rightSideDrive] = vexRT[Ch2];
	reverseStatus = 0;
	}
}

task Reverse()
{
		while(1==1)
		{
		stopTask(Forwards);
		motor[leftSideDrive] = -vexRT[Ch3];
		motor[rightSideDrive] = -vexRT[Ch2];
		reverseStatus = 1;
	}
}

task usercontrol()
{
	while(1==1)
		{

			startTask(Forwards);

			if(vexRT[Btn8R] == 1)
			{
				startTask(Battery);
				wait1Msec(3500);
				stopTask(Battery);
			}

			if(vexRT[Btn8U] == 1)
			{
				stopTask(Reverse);
				startTask(Forwards);
			}
			if(vexRT[Btn8D] == 1)
			{
			if(reverseStatus == 1)
			{
				startTask(Forwards);
			}
			else
			{
				startTask(Reverse);
			}
		}

			if(vexRT[Btn6U] == 1)
			{
				motor[clawMotor] = 127;
			}
			else if(vexRT[Btn6D] == 1)
			{
				motor[clawMotor] = -127;
			}
			else
			{
				motor[clawMotor] = 0;
			}
		}
	}

