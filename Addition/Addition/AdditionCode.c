#include<stdio.h>
int main()
{
	int num1, num2, sum;
	printf("Enter two numbers: \n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	sum=num1+num2;
	printf("Sum of %d and %d is %d", num1, num2, sum);
	return(0);
}