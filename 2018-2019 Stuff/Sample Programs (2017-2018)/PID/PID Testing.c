#pragma config(StandardModel, "RVW CLAWBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
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

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	//set all sensor values to zero

	while (SensorValue[rightEncoder] > 0)
	//while loop stating that while the value of the right encoder is more than 0, then this code runs

	if (SensorValue[rightEncoder] > (SensorValue[leftEncoder]))
	{
		motor(rightMotor) = motor(leftMotor) - 10;
		motor(leftMotor) = forwards;
	}
	if (SensorValue[leftEncoder] > (SensorValue[rightEncoder]))
	{
		motor(leftMotor) = motor(rightMotor) - 10;
		motor(rightMotor) = forwards;
	}
	//code for automatic straigtening for when robot is moving forwards
{
	motor(rightMotor) = lessforwards;
	motor(leftMotor) = forwards;
	wait1Msec(10000);

}
}
