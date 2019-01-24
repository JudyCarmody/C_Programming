#include<stdio.h>
#include<math.h>

#define STDRATE 0.49
#define ADDRATE 0.37
#define EVENING_DISCOUNT 0.35
#define NIGHT_DISCOUNT 0.65

double milTime(double, double);
double beginCall,stopCall,cost,bMin,sMin,nightMinCost,eveningMinCost,dayMinCost, nightMinD,eveningMinD,dayMinD;

int callLengthMinutes,beginHour,stopHour,totalHours,totalMin,beginHours,bMin100,sMin100,nightMin,eveningMin,dayMin,beginCallMin,stopCallMin;

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
		scanf("%lf", &stopCall);
		
		//print result of function milTime with parameters beginCall and stopCall
		printf("Day Minutes: %d\t\tDay Cost: $%.2lf\nEvening Minutes: %d\tEvening Cost: $%.2lf\nNight Minutes: %d\tNight Cost: $%.2lf\nTotal Minutes: %d\tTotal Cost: $%.2lf\n", milTime(beginCall,stopCall));
		printf("\nWould you like to enter another record? Y/N ");
		fflush(stdout);
		scanf("%s", &yn);
	}while(yn=='y' || yn=='Y');
	return (0);
}

// called by printf("...", milTime(param1, param2))
double milTime(double beginCall, double stopCall)
{
	beginHour = (int)beginCall; // convert double beginCall to int beginHour
	stopHour = (int)stopCall;
	bMin = beginCall-beginHour; // decimal minutes
	sMin = stopCall-stopHour;
	bMin100 = bMin*100; // removes decimal
	sMin100 = sMin*100;
	
	if(beginCall<=7.00) // call begins after 7AM
	{
		if(beginCall>16.00) // call begins before 4PM
		{
			if(stopCall<16.00) // call ends before 4PM
			{
				totalHours = stopHour-beginHour;
				totalMin = totalHours*60; // total hours in minutes
				callLengthMinutes = (totalMin+sMin100)-bMin100;
				cost = (callLengthMinutes-1)*ADDRATE+STDRATE;
				
				printf("Minutes: %d\tCost: $%.2lf\n", callLengthMinutes, cost)
			}
			
			if(stopCall>=16.00) // call ends after 4PM
			{
				if(stopCall<22.00) // call ends before 10PM
				{
					beginHours = 16-beginHour; // hours before 4PM
					totalHours = stopHour-beginHour;
					totalMin = totalHours*60; // total hours in minutes
					callLengthMinutes = (totalMin-bMin100)+sMin100; // call length in minutes
				
					dayMin = 960-((beginHour*60)+bMin100); // day minutes 960 = 16*60
					eveningMin = ((stopHour*60)+sMin100)-960; // evening minutes

					dayMinCost = ((dayMin-1)*ADDRATE)+STDRATE; // day minutes cost
					eveningMinCost = (eveningMin*ADDRATE)/EVENING_DISCOUNT; // evening minutes cost
					cost = dayMinCost+eveningMinCost;
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	if(beginCall>=22.00 || beginCall <7.00) // 24 hour, if call goes through midnight (example: 23.00 - 1.00)
	{
		if(beginCall>=22.00)
		{
			beginHours = 24-beginHour; // hours before 24
			totalHours = beginHours+stopHour;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes
			cost = ((((totalHours-sMin100)+(bMin100-1))*ADDRATE)+STDRATE)/NIGHT_DISCOUNT; // calculating cost of call
		}
		
		else if (beginCall<7.00) // night call, begins after midnight
		{
			beginHours = 7-beginHour; // hours before 7AM
			totalHours = stopHour-beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin+sMin100)-bMin100;
		
			nightMin = 420-((beginHour*60)+bMin100); // night Minutes 420 = 7*60
			nightMinCost = (((nightMin-1)*ADDRATE)+STDRATE)/NIGHT_DISCOUNT; // night Cost

			dayMin = ((stopHour*60)+sMin100)-420;
			dayMinCost = dayMin*ADDRATE; // day minutes cost
			cost = dayMinCost+nightMinCost;
		}
	}
	
	else // call does not go through midnight, day and evening calls
	{
		if(beginCall>=7.00 && beginCall<16.00) // call starts between 7AM and 4PM
		{			

			else if(stopCall>=16.00 && stopCall <22.00) // call ends after 4PM, but before 10PM
			{

			}
		}
		
		else if(beginCall>=16.00 && beginCall<22.00) // call starts between 4PM and 10PM
		{
			if(stopCall<22.00)
			{	
				totalHours = stopHour-beginHour;
				totalMin = totalHours*60; // total hours in minutes
				callLengthMinutes = (totalMin+sMin100)-bMin100;
				cost = ((callLengthMinutes*ADDRATE)+STDRATE)/EVENING_DISCOUNT;
			}
			
			else if(stopCall>=22.00)
			{
				beginHours = 22-beginHour; // hours before 10PM
				totalHours = stopHour-beginHour;
				totalMin = totalHours*60; // total hours in minutes
				callLengthMinutes = (totalMin-bMin100)+sMin100; // call length in minutes
				
			 	// day minutes go here  1320 = 22*60
				eveningMin = 1320-((beginHour*60)+bMin100); //evening Minutes
				nightMin = ((stopHour*60)+sMin100)-1320; // night Minutes
				
				eveningMinCost = (((eveningMin-1)*ADDRATE)+STDRATE)/EVENING_DISCOUNT; // evening Cost
				nightMinCost = (nightMin*ADDRATE)/NIGHT_DISCOUNT; // night Cost								
				cost = nightMinCost+eveningMinCost;
			}
		}
	}
	return(dayMin, dayMinCost, eveningMin, eveningMinCost, nightMin, nightMinCost, callLengthMinutes, cost);
}
