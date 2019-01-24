#include<stdio.h>
#include<math.h>

double milTime(double, double);
double beginCall, endCall;

int main()
{	
	char yn = 'y';

	do
	{
		printf("Enter time call started: ");
		fflush(stdout); // flashes input cursor on screen.
		scanf("%lf", &beginCall);
		printf("Enter time call stopped: ");
		fflush(stdout);
		scanf("%lf", &endCall);
		
		//print result of function milTime with parameters beginCall and stopCall
		printf("Day Minutes: %d\t\tDay Cost: $%.2lf\n"
			"Evening Minutes: %d\tEvening Cost: $%.2lf\n"
			"Night Minutes: %d\tNight Cost: $.2lf\n"
			"Total Minutes: %d\t Total Cost: %.2lf\n"
			, milTime(beginCall,endCall));
		
		printf("\nWould you like to enter another record? Y/N ");
		fflush(stdout);
		scanf("%s", &yn);
	}while(yn=='y' || yn=='Y');
	return (0);
}

// called by printf("...", milTime(param1, param2))
double milTime(double beginCall, double endCall)
{
	double stdRate = 0.49, addRate = 0.37;
	int eveningDiscount = 35, nightDiscount = 65, beginCallHour, endCallHour
		,beginCallMin, endCallMin, dayMin, eveningMin, nightMin, bCallHMin
		,eCallHMin, totalCallMin, dayCost, eveningCost, nightCost, totalCost;
	
	beginCallHour = ceil(beginCall);
	endCallHour = ceil(endCall);
	bCallHMin = beginCallHour*60; // hours as minutes
	eCallHMin = endCallHour*60;
	beginCallMin = beginCall*100; // remove decimal from minutes
	endCallMin = endCall*100;
	dayMin=0;
	eveningMin=0;
	nightMin=0;


	if(beginCallHour>=7.00 && beginCallHour<16.00) // call begins between 7AM and 4PM
	{
		totalCallMin = ((endCallHour+eCallHMin)-(beginCallHour-bCallHMin));
		if(endCallHour<16.00)// call ends at 4PM
		{
			dayMin = totalCallMin;
			dayCost = (dayMin-1)*addRate+stdRate;
		}

		else if(endCallHour>=16.00)//call ends after 4PM
		{
		
		}
	}

	else if(beginCallHour>=16.00 && beginCallHour<22.00) // call begins between 4PM and 10PM
	{
		if(endCallHour<22.00) // call ends at 10PM
		{}

		else if(endCallHour>=22.00) // call ends after 10PM
		{}
	}
	else if(beginCallHour>=22.00 &&beginCallHour>7.00) // call begins between 10PM and 7AM
	{
		if (endCallHour <7.00) // call ends before 7AM
		{}

		else if(endCallHour>=7.00) // call ends after 7PM
		{}
	}

	return(dayMin, dayCost, eveningMin, eveningCost, nightMin, nightCost, totalCallMin, totalCost);
}