#include<stdio.h>
#include<math.h>
double milTime(double, double);
double stdRate = 0.49, addRate = 0.37, eveningDiscount = 0.35, nightDiscount = 0.65, totalMin, beginCall, stopCall, bMin, sMin, callLength,cost;

int callLengthMinutes,beginHour, stopHour, nightMin, totalHours, beginHours,bsMin;

int main()
{	
char yn = 'y';

	do
	{
		printf("Enter time call started: ");
		fflush(stdout); // flashes input cursor on screen.
		scanf("%lf", &beginCall);
		printf("\nEnter time call stopped: ");
		fflush(stdout);
		scanf("%lf", &stopCall);
		
		//print result of function milTime with parameters beginCall and stopCall
		printf("Total Minutes is: %.2lf\n", milTime(beginCall,stopCall));
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
		sMin = stopCall-stopHour; // decimal minutes
		bsMin = (bMin-sMin)*100; // removes decimal

		if(stopCall<beginCall) // 24 hour, if call goes through midnight (example: 23.00 - 1.00)
		{
			totalHours = beginHours+stopHour;	
			beginHours = 24-beginHour;
			nightMin = totalHours*60;
			callLengthMinutes = nightMin-bsMin; // time in minutes!
		
			if(beginCall>=23.00)
			{ cost = (((bsMin-1)*addRate)+stdRate)*nightDiscount; }
			
			else if(beginCall<23.00&&beginCall>=16.00)
			{ cost = ((callLengthMinutes*addRate)+stdRate)*eveningDiscount; }
			
			printf("callLengthMinutes: %d\ncost:%.2lf\n",callLengthMinutes,cost);
		}	
		
		else // call does not go through midnight
		{
			totalHours = (stopHour-beginHour)*60;
			if(beginCall>=7.00 && beginCall<16.00)
			{ cost = (((totalHours-(bMin-1))+sMin)*addRate)+stdRate; }
			
			else if (stopCall>22.00)
			{ cost = (((totalHours-(bMin-1)+sMin)*addRate)+stdRate)*eveningDiscount; }
			
			// if bMin > sMin and is sMin > bMin
			
			callLengthMinutes = totalHours-bsMin;
			printf("beginHour: %d, stopHour: %d\n totalHours: %d\n bMin:%.2lf\n sMin:%.2lf\n bsMin: %d\n",beginHour,stopHour,totalHours,bMin,sMin,bsMin);
		}
	return(callLengthMinutes);
}
