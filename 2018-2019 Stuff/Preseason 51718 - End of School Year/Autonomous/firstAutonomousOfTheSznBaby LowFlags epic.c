#pragma config(Motor,  port2,           rightSideDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftSideDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)

void baseControl(int leftSpeed, int rightSpeed, int baseTime)
{
	motor[leftSideDrive] = leftSpeed;
	motor[rightSideDrive] = rightSpeed;
	baseTime = wait1Msec(baseTime);
}

task main()
{
	baseControl(-127, -127, 2000);
	//drive backwards to flag

	baseControl(0, 0, 250);
	//breif pause

	baseControl(127, 127, 2000);
	//drive to starting position

}
