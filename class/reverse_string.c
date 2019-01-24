#include<stdio.h>
#include<string.h>

void stringReverse(char*, int, int);

void main()
{
	char phrase_arr[100];
	printf("Enter a phrase:\n");
	gets(phrase_arr);
	stringReverse(phrase_arr, 0, strlen(phrase_arr)-1);
	printf("\nThe reversed phrase is:\n%s", phrase_arr);
}

void stringReverse(char *rev_arr, int i, int j)
{
	char c;
	if(i>=j) { return; }
	
	c = *(rev_arr+i);
	*(rev_arr+i) = *(rev_arr+j);
	*(rev_arr+j) = c;
	
	stringReverse(rev_arr, ++i, --j);
}