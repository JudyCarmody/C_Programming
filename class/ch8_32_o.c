#include<stdio.h>
#include<string.h>
void main()
{
	char date[10];
	
	puts("Enter a date in this format: mm/dd/yyyy: ");
	scanf("%9s", date);
	
	if(date[0] == '0')
	{
		if(date[1] == '1')
			printf("January %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '2')
			printf("February %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '3');
			printf("March %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '4')
			printf("April %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '5')
			printf("May %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '6')
			printf("June %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '7')
			printf("July %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '8')
			printf("August %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '9')
			printf("September %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
	}
	
	if(date[0] == '1')
	{
		if(date[1] == '0')
			printf("October %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '1')
			printf("November %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
		if(date[1] == '2')
			printf("December %d%d, %d%d%d%d", date[3],date[4],date[6],date[7],date[8],date[9]);
	}	
}