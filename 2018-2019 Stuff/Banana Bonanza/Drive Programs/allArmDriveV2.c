#pragma config(Motor,  port2,           leftSideDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftTurntable, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightTurntable, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void liftControl(int liftPower)
{
	motor[leftTurntable] = liftPower;
	motor[rightTurntable] = liftPower;

}

void armControl(int armPower)
{
	motor[leftArm] = armPower;
	motor[rightArm] = armPower;
}

task main()
{
	while (1 == 1)
	{

		if(vexRT[Btn6DXmtr2] == 1)
			{
				armControl( 127 );
			}
			else if(vexRT[Btn6UXmtr2] == 1)
			{
				armControl( -127 );
			}
			else
			{
				armControl( 0 );
			}

	}
}