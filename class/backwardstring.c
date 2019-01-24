#include<stdio.h>
#include<string.h>

#define ARRSIZE 26

void stringReverse(char*);

void main()
{
	int i;
	char arr_str[ARRSIZE];
	
	printf("\nEnter a phrase: \n");
	scanf("%25s", arr_str);

	puts("\n Input:");
	printf("%s", arr_str);
	puts("\n");
	
	stringReverse(arr_str);
	//	for (i = 0; i < ARRSIZE; i++) {}


}

void stringReverse(char *arr_str)
{
		char arr_str_copy[ARRSIZE] = arr_str;
		int j;
		printf("\nInside stringReverse function.\n\n");
		
		for(j=0; j < ARRSIZE && arr_str[j] != '\0'; j++)
		{ printf("%s", arr_str[j]); }
}
*/