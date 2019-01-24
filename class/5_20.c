#include<stdio.h>
int main(void)
{
	int side, row, col;
	char fillCharacter;
	
	puts("\nWhat character would you like your square to be made of? ");
	scanf("%c", &fillCharacter);
	
	puts("How big do you want this square of asterisks to be? ");
	scanf("%d", &side);
	
	if((side>=1))
	{
		for(row=0; row<side; row++)
		{
			for(col=0; col<side; col++)
				printf("%c", fillCharacter);
			printf("\n");
		}
	}
	
	else
		printf("Size must be 1 or greater.");
}