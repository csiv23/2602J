#pragma config(Motor,  port2,           leftSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightSideDrive, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task Forwards()
{
	while(1==1)
	{
	motor[leftSideDrive] = vexRT[Ch3];
	motor[rightSideDrive] = vexRT[Ch2];
	}
}

task Reverse()
{
		while(1==1)
		{
		stopTask(Forwards);
		motor[leftSideDrive] = -vexRT[Ch3];
		motor[rightSideDrive] = -vexRT[Ch2];
	}
}

task main()
{
	while(1==1)
	{

		startTask(Forwards);

		if(vexRT[Btn8U] == 1)
		{
				stopTask(Reverse);
			startTask(Forwards);
		}

		if(vexRT[Btn8D] == 1)
		{
			startTask(Reverse);
		}
	}
}
