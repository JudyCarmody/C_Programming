#include<stdio.h>
#include<math.h>

float calcTime(float, float);

int main()
{
	float beginCall1,beginCall2,beginCall3,beginCall4,stopCall1,stopCall2,stopCall3,stopCall4;
	char yn = 'y';

	do
	{
		printf("Call 1 start: ");
		scanf("%f", &beginCall1);
		printf("Call 1 end: ");
		scanf("%f", &stopCall1);
	
		printf("Call 2 start: ");
		scanf("%f", &beginCall2);
		printf("Call 2 end: ");
		scanf("%f", &stopCall2);
	
		printf("Call 3 start: ");
		scanf("%f", &beginCall3);
		printf("Call 3 end: ");
		scanf("%f", &stopCall3);
		
		printf("Call 4 start: ");
		scanf("%f", &beginCall4);
		printf("Call 4 end: ");
		scanf("%f", &stopCall4);		
		
		//print result of function milTime with parameters beginCall and stopCall
		printf("Start Time\tEnd Time\tLength\t\tCost\n");
		printf("***********************************************************\n");
		calcTime(beginCall1,stopCall1);
		calcTime(beginCall2,stopCall2);
		calcTime(beginCall3,stopCall3);
		calcTime(beginCall4,stopCall4);
			
		printf("\nWould you like to enter another record? Y/N ");
		scanf("%s", &yn);
	}while(yn=='y' || yn=='Y');
	return (0);
}

// called by printf("...", milTime(param1, param2))
float calcTime(float beginCall, float stopCall)
{
	float stdRate = 0.49, addRate = 0.37, eveningDiscount = 0.35, nightDiscount = 0.65;
	float cost,bMin,sMin,nightMinCost,eveningMinCost;
	float dayMinCost,nightMinD,eveningMinD,dayMinD;
	
	int callLengthMinutes,beginHour,stopHour,totalHours,totalMin,beginHours,bMin100;
	int sMin100,nightMin,eveningMin,dayMin,beginCallMin,stopCallMin;

	beginHour = (int)beginCall; // convert double beginCall to int beginHour
	stopHour = (int)stopCall;
	bMin = beginCall-beginHour; // decimal minutes
	sMin = stopCall-stopHour;
	bMin100 = bMin*100; // removes decimal
	sMin100 = sMin*100;

	if(beginCall>=7.00 && beginCall <16.00) // call begins after 7AM, but before 4PM
	{
		if(stopCall<16.00) // call ends before 4PM
		{
			totalHours = stopHour-beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin+sMin100)-bMin100;
			cost = (callLengthMinutes-1)*addRate+stdRate;
			
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (0%%)\t$%.2lf\n\n", callLengthMinutes, cost);
		}
		
		if(stopCall>16.00 && stopCall<=22.00) // call ends between 4PM and 10PM
		{
			beginHours = 16-beginHour; // hours before 4PM
			totalHours = stopHour-beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin-bMin100)+sMin100; // call length in minutes
				
			dayMin = ((beginHours*60)-bMin100);
			eveningMin = ((stopHour*60)+sMin100)-960; // evening minutes

			dayMinCost = (dayMin-1)*addRate+stdRate; // day minutes cost
			eveningMinCost = (eveningMin*addRate)*eveningDiscount; // evening minutes cost
			cost = dayMinCost+eveningMinCost;
				
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n", eveningMin, eveningMinCost);
			printf("\t\t\t\t%d (0%%)\t$%.2lf\n\n", dayMin, dayMinCost);
		}
	}

	if(beginCall>=16.00 && beginCall<22.00) // call begins after 4PM, but before 10PM
	{
		if(stopCall<22.00 && stopCall>16.00) // call ends before 10PM
		{
			totalHours = stopHour-beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin+sMin100)-bMin100;
			cost = ((callLengthMinutes*addRate)+stdRate)*eveningDiscount;
		
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n\n", callLengthMinutes, cost);
		}
		
		if(stopCall>22.00 && stopCall<24.00) // call ends after 10PM
		{
			beginHours = 22-beginHour; // hours before 10PM
			totalHours = stopHour-beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin-bMin100)+sMin100; // call length in minutes
				
			eveningMin = ((beginHours*60)-bMin100); //evening Minutes
			nightMin = 1320-(stopHour*60)+sMin100; // night Minutes
				
			eveningMinCost = (((eveningMin-1)*addRate)+stdRate)*eveningDiscount; // evening Cost
			nightMinCost = ((nightMin)*addRate)*nightDiscount; // night Cost								
			cost = nightMinCost+eveningMinCost;
				
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);	
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n\n", eveningMin, eveningMinCost);
		}
		
		if(stopCall>0.00 && stopCall<7.00)
		{
			beginHours = 22-beginHour; // hours before 10PM
			totalHours = stopHour+beginHour;
			totalMin = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalMin-bMin100)+sMin100; // call length in minutes
				
		 	// day minutes go here  1320 = 22*60
			eveningMin = 1320-((beginHour*60)+bMin100); //evening Minutes
			nightMin = (stopHour*60)+sMin100; // night Minutes
				
			eveningMinCost = (((eveningMin-1)*addRate)+stdRate)*eveningDiscount; // evening Cost
			nightMinCost = ((nightMin)*addRate)*nightDiscount; // night Cost								
			cost = nightMinCost+eveningMinCost;
				
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);	
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n\n", eveningMin, eveningMinCost);
		}
		
		if(stopCall<16.00 && stopCall>7.00)
		{
			totalHours = (beginHour-stopHour)*60;
			callLengthMinutes = (totalHours-bMin100)+sMin100;
		
			eveningMin = ((beginHours*60)-bMin100); //evening Minutes
			nightMin = 1320-(stopHour*60)+sMin100; // night Minutes
			dayMin = ((stopHour*60)+sMin100)-420;

			dayMinCost = (dayMin*addRate)+stdRate;
			eveningMinCost = (((eveningMin-1)*addRate)+stdRate)*eveningDiscount; // evening Cost
			nightMinCost = ((nightMin)*addRate)*nightDiscount; // night Cost								
			cost = nightMinCost+eveningMinCost;
		
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n", eveningMin, eveningMinCost);
			printf("\t\t\t\t%d (0%%)\t  $%.2lf\n\n", dayMin, dayMinCost);
		}
	}
	
	if(beginCall>=22.00) // call begins after 10PM
	{
		if(stopCall<7.00 && beginCall<24.00) // call ends before 7AM
		{
			beginHours = 24-beginHour; // hours before 24
			totalHours = stopHour+beginHours;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes
			cost = ((((totalHours-sMin100)+(bMin100-1))*addRate)+stdRate)*nightDiscount; // calculating cost of call
	
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n\n", callLengthMinutes, cost);
		}
		
		if(stopCall>7.00 && beginCall<24.00) // call ends after 7AM
		{
			beginHours = 24-beginHour; // hours before 24
			totalHours = stopHour-beginHours;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes
			
			nightMin = ((stopHour*60)+sMin100)-420;
			nightMinCost = (((nightMin-1)*addRate)+stdRate)*nightDiscount;
				
			dayMin = ((stopHour*60)+sMin100) - 420;
			dayMinCost = ((dayMin)*addRate);

			cost = nightMinCost + eveningMinCost + dayMinCost;

			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);
			printf("\t\t\t\t%d (0%%)\t$%.2lf\n\n", dayMin, dayMinCost);		
		}
	}
		
	if(beginCall>0.00 && beginCall<7.00)
	{
		if(stopCall<7.00) // call ends before 7AM
		{
			totalHours = stopHour-beginHour;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes
			cost = ((((totalHours-sMin100)+(bMin100-1))*addRate)+stdRate)*nightDiscount; // calculating cost of call
	
			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t\t$%.2lf\n\n", callLengthMinutes, cost);
		}
		
		if(stopCall>7.00) // call ends after 7AM
		{
			totalHours = stopHour-beginHour;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes			
			
			nightMin = 420-((beginHour*60)+bMin100);
			nightMinCost = (((nightMin-1)*addRate)+stdRate)*nightDiscount;
				
			dayMin = ((stopHour*60)+sMin100)-420;
			dayMinCost = (dayMin*addRate)+stdRate;
			
			dayMin++;
			callLengthMinutes++;
			
			cost = nightMinCost + dayMinCost;

			printf("%.2lf\t\t%.2lf\t\t%d\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);
			printf("\t\t\t\t%d (0%%)\t  $%.2lf\n\n", dayMin, dayMinCost);		
		}
	}
	
	return(beginCall, stopCall);
}
