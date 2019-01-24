#include<stdio.h>
#include<math.h>

double milTime(double, double);
double stdRate = 0.49, addRate = 0.37, newERate,newNRate,beginCall,stopCall,cost,bMin,sMin,nightMinCost,eveningMinCost,dayMinCost, nightMinD,eveningMinD,dayMinD;

int eveningDiscount = 35, nightDiscount = 65, callLengthMinutes,beginHour,stopHour,totalHours,totalMin,beginHours,bMin100,sMin100,nightMin,eveningMin,dayMin,beginCallMin,stopCallMin;

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
	newERate = stdRate*eveningDiscount;
	newNRate = stdRate*nightDiscount;
	
	if(bMin100<=59) // how many minutes from the next hour?
	{ bMin100 = abs(bMin100-60); }

	if(beginCall>=22.00 || beginCall <7.00) // 24 hour, if call goes through midnight (example: 23.00 - 1.00)
	{
		if(beginCall>=22.00)
		{
			beginHours = 24-beginHour; // hours before 24
			totalHours = beginHours+stopHour;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes
			cost = ((((totalHours-sMin100)+(bMin100-1))*addRate)+stdRate)/nightDiscount; // calculating cost of call
		}
		
		else if (beginCall<7.00) // night call, begins after midnight
		{
			beginHours = 7-beginHour; // hours before 7AM
			totalHours = stopHour-beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin+sMin100)-bMin100;
		
			nightMin = 420-((beginHour*60)+bMin100); // night Minutes 420 = 7*60
			nightMinCost = (((nightMin-1)*addRate)+stdRate)/nightDiscount; // night Cost

			dayMin = ((stopHour*60)+sMin100)-420;
			dayMinCost = dayMin*addRate; // day minutes cost
			cost = dayMinCost+nightMinCost;
		}
	}
	
	else // call does not go through midnight, day and evening calls
	{
		if(beginCall>=7.00 && beginCall<16.00) // call starts between 7AM and 4PM
		{			
			if(stopCall<16.00) // call ends before 4PM
			{
				totalHours = stopHour-beginHour;
				totalMin = totalHours*60; // total hours in minutes
				callLengthMinutes = (totalMin+sMin100)-bMin100;
				cost = (callLengthMinutes-1)*addRate+stdRate;
			}

			else if(stopCall>=16.00 && stopCall <22.00) // call ends after 4PM, but before 10PM
			{
				beginHours = 16-beginHour; // hours before 4PM
				totalHours = stopHour-beginHour;
				totalMin = totalHours*60; // total hours in minutes
				callLengthMinutes = (totalMin-bMin100)+sMin100; // call length in minutes
				
				dayMin = 960-((beginHour*60)+bMin100); // day minutes 960 = 16*60
				eveningMin = ((stopHour*60)+sMin100)-960; // evening minutes

				dayMinCost = ((dayMin-1)*addRate)+stdRate; // day minutes cost
				eveningMinCost = (eveningMin*addRate)/eveningDiscount; // evening minutes cost
				cost = dayMinCost+eveningMinCost;
			}
		}
		
		else if(beginCall>=16.00 && beginCall<22.00) // call starts between 4PM and 10PM
		{
			if(stopCall<22.00)
			{	
				totalHours = stopHour-beginHour;
				totalMin = totalHours*60; // total hours in minutes
				callLengthMinutes = (totalMin+sMin100)-bMin100;
				cost = ((callLengthMinutes*addRate)+stdRate)/eveningDiscount;
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
				
				eveningMinCost = (((eveningMin-1)*addRate)+stdRate)/eveningDiscount; // evening Cost
				nightMinCost = (nightMin*addRate)/nightDiscount; // night Cost								
				cost = nightMinCost+eveningMinCost;
			}
		}
	}
	return(dayMin, dayMinCost, eveningMin, eveningMinCost, nightMin, nightMinCost, callLengthMinutes, cost);
}