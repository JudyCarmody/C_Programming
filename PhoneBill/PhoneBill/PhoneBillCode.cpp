#include<stdio.h>
#include<math.h>

double timeCall(double,double,double,double,double,double,double,double,double,double);
double stdRate = 0.49, addRate = 0.37, beginCall, stopCall, evening1 = 0.35, evening2 = 0.65, currentRate, currentBill, callTime, totalBill = 0, firstMin;

void main()
{
	printf("Enter time call started: ");
	scanf("%lf", &beginCall);
	printf("\nEnter time call stopped: ");
	scanf("%lf", &stopCall);
	
	printf("callTime %ls :: firstMin %ls :: totalBill %ls", callTime, firstMin, totalBill);
}

double timeCall(double beginCall, double stopCall, double stdRate, double addRate, double evening1, double currentRate, double currentBill, double callTime, double totalBill, double firstMin)
{
	if(beginCall>=16.00 && stopCall<=22.00)
	{
		callTime = ceil(stopCall-beginCall);
		firstMin = callTime - 0.01;
		totalBill = ((addRate * firstMin) + stdRate)*0.35;
	}

/*	else if(beginCall>=22.00 && stopCall <=7.00)
	{

	}

	else if(beginCall >=7.00 && stopCall<=16.00)
	{

	}

	else
		printf("Invalid time.");
*/
	return(beginCall, stopCall, stdRate, addRate, evening1, currentRate, currentBill, callTime, totalBill, firstMin);
}