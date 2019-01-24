#include<stdio.h>
#include<math.h>

#define STDRATE 0.49
#define ADDRATE 0.37
#define EVENING_DISCOUNT 0.35
#define NIGHT_DISCOUNT 0.65

float calcTime(float, float);
float calcTotal(int, int, int, int, int, float, float, float, float);

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
		
		printf("\n\nStart Time\tEnd Time\tLength\t\tCost\n");
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

float calcTime(float beginCall, float stopCall)
{
	float cost,bMin,sMin,nightMinCost,eveningMinCost;
	float dayMinCost,nightMinD,eveningMinD,dayMinD;
	float cost1, cost2, cost3, cost4;
	
	int callLengthMinutes,beginHour,stopHour,totalHours,totalMin,beginHours,bMin100;
	int sMin100,nightMin,eveningMin,dayMin,beginCallMin,stopCallMin;
	int callLengthMinutes1, callLengthMinutes2, callLengthMinutes3, callLengthMinutes4;
	static unsigned int call_count = 0;

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
			cost = (callLengthMinutes-1)*ADDRATE+STDRATE;
			
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
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

			dayMinCost = (dayMin-1)*ADDRATE+STDRATE; // day minutes cost
			eveningMinCost = (eveningMin*ADDRATE)*EVENING_DISCOUNT; // evening minutes cost
			cost = dayMinCost+eveningMinCost;
				
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
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
			cost = ((callLengthMinutes*ADDRATE)+STDRATE)*EVENING_DISCOUNT;
		
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
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
				
			eveningMinCost = (((eveningMin-1)*ADDRATE)+STDRATE)*EVENING_DISCOUNT; // evening Cost
			nightMinCost = ((nightMin)*ADDRATE)*NIGHT_DISCOUNT; // night Cost								
			cost = nightMinCost+eveningMinCost;
				
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n", eveningMin, eveningMinCost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n\n", nightMin, nightMinCost);	
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
				
			eveningMinCost = (((eveningMin-1)*ADDRATE)+STDRATE)*EVENING_DISCOUNT; // evening Cost
			nightMinCost = ((nightMin)*ADDRATE)*NIGHT_DISCOUNT; // night Cost								
			cost = nightMinCost+eveningMinCost;
				
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);	
			printf("\t\t\t\t%d (35%%)\t\t$%.2lf\n\n", eveningMin, eveningMinCost);
		}
		
		if(stopCall<16.00 && stopCall>7.00)
		{
			int newBHour = 24-beginHour;
			totalHours = (newBHour+stopHour)*60;
			callLengthMinutes = (totalHours-bMin100)+sMin100;
		
			eveningMin = ((beginHours*60)-bMin100); //evening Minutes
			dayMin = ((stopHour*60)+sMin100)-420;
			nightMin = (callLengthMinutes - eveningMin)-dayMin; // night Minutes

			eveningMinCost = (((eveningMin-1)*ADDRATE)+STDRATE)*EVENING_DISCOUNT; // evening Cost
			nightMinCost = (nightMin*ADDRATE)*NIGHT_DISCOUNT; // night Cost								
			dayMinCost = dayMin*ADDRATE;
			cost = nightMinCost+eveningMinCost;
		
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (35%%)\t$%.2lf\n", eveningMin, eveningMinCost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);
			printf("\t\t\t\t%d (0%%)\t\t$%.2lf\n\n", dayMin, dayMinCost);
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
			cost = ((((totalHours-sMin100)+(bMin100-1))*ADDRATE)+STDRATE)*NIGHT_DISCOUNT; // calculating cost of call
	
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n\n", callLengthMinutes, cost);
		}
		
		if(stopCall>7.00 && beginCall<24.00) // call ends after 7AM
		{
			beginHours = 24-beginHour; // hours before 24
			totalHours = stopHour-beginHours;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = ((totalHours-bMin100)-1)+sMin100; // call length in minutes
			
			nightMin = ((stopHour*60)+sMin100)-420;
			nightMinCost = (((nightMin-1)*ADDRATE)+STDRATE)*NIGHT_DISCOUNT;
				
			dayMin = ((stopHour*60)+sMin100) - 420;
			dayMinCost = dayMin*ADDRATE;

			cost = nightMinCost + eveningMinCost + dayMinCost;

			printf("%.2lf\t\t%.2lf\t\t%d minutes\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
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
			cost = ((((totalHours-sMin100)+(bMin100-1))*ADDRATE)+STDRATE)*NIGHT_DISCOUNT; // calculating cost of call
	
			printf("%.2lf\t\t%.2lf\t\t%d minutes\t\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t\t$%.2lf\n\n", callLengthMinutes, cost);
		}
		
		if(stopCall>7.00) // call ends after 7AM
		{
			totalHours = stopHour-beginHour;	// total number of hours
			totalHours = totalHours*60; // total hours in minutes
			callLengthMinutes = (totalHours-bMin100)+sMin100; // call length in minutes			
			
			nightMin = 420-((beginHour*60)+bMin100);
			nightMinCost = (((nightMin-1)*ADDRATE)+STDRATE)*NIGHT_DISCOUNT;
				
			dayMin = ((stopHour*60)+sMin100)-420;
			dayMinCost = (dayMin*ADDRATE)+STDRATE;
			
			dayMin++;
			callLengthMinutes++;
			
			cost = nightMinCost + dayMinCost;

			printf("%.2lf\t\t%.2lf\t\t%d minutes\t$%.2lf\n", beginCall, stopCall, callLengthMinutes, cost);
			printf("\t\t\t\t%d (65%%)\t$%.2lf\n", nightMin, nightMinCost);
			printf("\t\t\t\t%d (0%%)\t$%.2lf\n\n", dayMin, dayMinCost);		
		}
	}
	call_count++;
	
	if(call_count==1)
	{
		callLengthMinutes1 = callLengthMinutes;
		cost1 = cost;
	}
	
	if(call_count==2)
	{
		callLengthMinutes2 = callLengthMinutes;
		cost2 = cost;
	}
	
	if(call_count==3)
	{
		callLengthMinutes3 = callLengthMinutes;
		cost3 = cost;
	}
	
	if(call_count==4)
	{
		callLengthMinutes4 = callLengthMinutes;
		cost4 = cost;
	}
	
	calcTotal(call_count, callLengthMinutes1, callLengthMinutes2, callLengthMinutes3, callLengthMinutes4, cost1, cost2, cost3, cost4);
	return(beginCall,stopCall);
}

float calcTotal(int call_count, int callLengthMinutes1, int callLengthMinutes2, int callLengthMinutes3, int callLengthMinutes4, float cost1, float cost2, float cost3, float cost4)
{
	int totalMinutes =  callLengthMinutes1 + callLengthMinutes2 + callLengthMinutes3 + callLengthMinutes4;
	float totalCost = cost1 + cost2 + cost3 + cost4;
	
	if(call_count==4) { printf("\t\tTotal:\t\t%d minutes\t$%.2f", totalMinutes, totalCost); }
	return(0);
}
