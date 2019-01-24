#include<stdio.h>
int main()
{
	int input, sum, multiply, subtract;

	printf("Enter a number:\n");
	scanf("%d", &input);

	sum = input + 5;
	multiply = sum * 2;
	subtract = multiply - 7;

	printf("The final number is: %d\n", subtract);
}