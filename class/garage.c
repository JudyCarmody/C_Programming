#include<stdio.h>
double calculateCharges(double);
void totalCalc(double,double,double,double,double,double);
double minCharge = 2.00, addCharge = 0.50, maxCharge = 10.00, hours1, hours2, hours3;
void main()
{
	printf("Enter hours for three cars, press enter to proceed to next car: ");
	scanf("%lf", &hours1);
	scanf("%lf", &hours2);
	scanf("%lf", &hours3);
	
	printf("\n");
	printf("Car\tHours\tCharge\n");
	calculateCharges(hours1);
	calculateCharges(hours2);
	calculateCharges(hours3);
}

double calculateCharges(double hours)
{
	double carHours1, carHours2, carHours3, charge1, charge2, charge3;
	
	if(hours<=3.00)
	{
		carHours1 = hours;
		charge1 = minCharge;
		printf("1\t%.2lf\t%.2lf\n", carHours1, charge1);
	}
	
	if(hours>3.00 && hours<24.00)
	{
		carHours2 = hours;
		charge2 = ((carHours2-3)*addCharge)+minCharge;	
		printf("2\t%.2lf\t%.2lf\n", carHours2, charge2);
	}
		
	if(hours == 24.00)
	{
		carHours3 = hours;
		charge3 = maxCharge;
		printf("3\t%.2lf\t%.2lf\n", carHours3, charge3);
		totalCalc(carHours1,carHours2,carHours3,charge1,charge2,charge3);
	}
	
//	if(hours > 24.00) { printf("Too long, maximum hours is 24!\n"); }
//	if(hours <= 0)	{ printf("Must be greater than 0!\n"); }
	
	return(0);
}

void totalCalc(double carHours1, double carHours2, double carHours3, double charge1, double charge2, double charge3)
{
	double totalHours, totalCharge;
	
	totalHours = carHours1 + carHours2 + carHours3;
	totalCharge = charge1 + charge2 + charge3;
	printf("Total:\t%.2lf\t%.2lf\n", totalHours, totalCharge);
}
