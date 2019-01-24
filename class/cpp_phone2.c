#include <stdio.h>
#include <math.h>

double callCalculator(double, double);

static double FLAT_RATE = .49; // first minute
static double ADD_RATE = .37; // additional minutes
static double EVENING_DISCOUNT = .35;
static double NIGHT_DISCOUNT = .65;

static int DAY = 420; // 7AM, minimum value
static int EVENING = 960; // 4PM, minimum value
static int NIGHT = 1320; // 10PM, minimum value
static int MIDNIGHT = 1440; // midnight

double beginCall, endCall;

void main()
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
		/*printf("Day Minutes: %d\t\tDay Cost: $%.2lf\n"
			"Evening Minutes: %d\tEvening Cost: $%.2lf\n"
			"Night Minutes: %d\tNight Cost: $.2lf\n"
			"Total Minutes: %d\t Total Cost: %.2lf\n"
			, callCalculator(beginCall,endCall));
		*/
		
			printf("timeToMinutes: %d\tcallCost: $%.2lf\ncallCost2: $%.2lf\ttotalCost: $.2lf\nlength: %d\n", callCalculator(beginCall, endCall));
		printf("\nWould you like to enter another record? Y/N ");
		fflush(stdout);
		scanf("%s", &yn);
	}while(yn=='y' || yn=='Y');
}

double callCalculator(double bCall, double eCall)
{	
	int beginHour = (int)beginCall; // convert double beginCall to int beginHour
	int stopHour = (int)stopCall;
	int bMin = beginCall-beginHour; // decimal minutes
	int sMin = stopCall-stopHour;
	
	int hour = 0; // hour value input
	int minute = 0; // minute value input
	
	int length; // length (in minutes) of the phone call
	int timeToMinutes = hour*60 + minute; // hour*60 + minute = time in minutes at which the call was started
	double callCost = 0; // cost of individual call being computed
	double totalCost = 0; // total cost of all calls computed
	double callCost2 = 0;
		
	if (timeToMinutes < DAY) // start time is before 420 (7 AM)
	{
		if (timeToMinutes + length < DAY) // end time is before 420 (7 AM)
		{ callCost = length * NIGHT_DISCOUNT; }
		
		else // end time is after 420
		{
			callCost = ((DAY - timeToMinutes) *FLAT_RATE);
			callCost2 = (((timeToMinutes + length) - DAY) *EVENING_DISCOUNT);
			callCost = callCost + callCost2;
		}
	}

	else if ((timeToMinutes > DAY)&&(timeToMinutes < EVENING)) // start time is between 7 AM and 4 PM
	{
		if (timeToMinutes + length < EVENING) // end time is before 4 PM
		{ callCost = length * FLAT_RATE; }

		else // end time is after 4 PM
		{
			callCost = ((EVENING - timeToMinutes) * FLAT_RATE); 
			callCost2 = (((timeToMinutes + length) - EVENING) * EVENING_DISCOUNT);	
			callCost = callCost + callCost2;
		}
	}
	
	else // start time is after 6 PM
	{ callCost = length * NIGHT_DISCOUNT; }

	totalCost += callCost;
	
	return(timeToMinutes, callCost, callCost2, totalCost, length);
}