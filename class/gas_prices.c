#include<stdio.h>
#include<string.h>

#define tank_gallons 15;

void location_c_or_s(char*);
void calc_prices(char*, float*);

float prices_city[] = {1.254, 1.309, 1.399};
float prices_suburb[] = {1.139, 1.179, 1.279};
char location[7];

void main()
{
	printf("Please enter your location (City/Suburb): \n");
	scanf("%s", location);
	
	location_c_or_s(location);
}	

void location_c_or_s(char *location)
{
	if(strchr(location, 'c') != '\0')
	{		
		calc_prices(location, prices_city);
		printf("\n");
	}
	
	if(strchr(location, 's') != '\0')
	{		
		calc_prices(location, prices_suburb);
		printf("\n");
	}
}

void calc_prices(char *location, float *prices)
{
	printf("The average prices for a fill-up in the %s are:\n", location);
	printf("Regular\t\tHigh Octane\tSuper Octane\n");
	
	for(int i = 0; i<=2; i++)
	{
		float temp = prices[i] * tank_gallons;
		printf("%.2lf\t\t", temp);
	}
}
