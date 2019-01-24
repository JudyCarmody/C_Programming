#include<stdio.h>
int main(void)
{
	int i, j, k, count=4;

	for(i=1; i<=count; i++)
	{
		for(j=1; j<=count-i; j++)
			printf("%c", '!');
	
		for(k=1; k<=2*i-1; k++)
			printf("%c", '*');
		printf("\n");
	}
	
	for(i=(count-1); i>0; i--)
	{
		for(j=1; j<=(count-i); j++)
			printf("%c", '~');
		for(k=1; k<=(2*i-1); k++)
			printf("%c", '&');
		printf("\n");
	}
	
}