#include<stdio.h>
int main(void)
{
	int input, calcA, calcB, calcC, year;
	char yn = 'y';

	do
	{
		printf("%s", "Enter the year you were born: ");
		scanf("%d", &input);
		
		calcA = input - 4;
		calcB = calcA / 12;
		calcC = calcB * 12;
		year = calcA - calcC;
		
		if(year == 0)
		{
			printf("%s", "You were born during the Year of the Rat!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 1)
		{	printf("%s", "You were born during the Year of the Ox!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 2)
		{
			printf("%s", "You were born during the Year of the Tiger\n!");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 3)
		{
			printf("%s", "You were born during the Year of the Rabbit\n!");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 4)
		{
			printf("%s", "You were born during the Year of the Dragon!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 5)
		{
			printf("%s", "You were born during the Year of the Snake!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 6)
		{
			printf("%s", "You were born during the Year of the Horse!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 7)
		{	
			printf("%s", "You were born during the Year of the Sheep!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 8)
		{
			printf("%s", "You were born during the Year of the Monkey!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 9)
		{
			printf("%s", "You were born during the Year of the Rooster!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else if(year == 10)
		{	
			printf("%s", "You were born during the Year of the Dog!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}	
		
		else if(year == 11)
		{
			printf("%s", "You were born during the Year of the Pig!\n");
			printf("%s", "Would you like to enter another year? (y/n)\n");
			scanf("%s", &yn);
		}
		
		else
		{
			printf("%s", "Enter another year or type 'n' to exit: \n");
			scanf("%s", &yn);
		}
	}while(yn == 'y');

	if (yn =='n')
		printf("%s", "Program End.");
}
