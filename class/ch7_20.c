//ex07_20.c
//What does this program do?
// --- Enter a string with no spaces, program counts number of characters in string.

#include<stdio.h>
#define SIZE 80

int mystery2(const char *s); // prototype

int main(void)
{
	char string[SIZE]; // create char array
	puts("Enter a string: ");
	scanf("%79s", string);
	printf("%d\n", mystery2(string));
} // end main

//What does this function do?
// -- loops through array and counts number of characters in array, stops at null
int mystery2 (const char *s)
{
	int x; // counter
	
	//loop through string
	for(x=0; *s!='\0';++s) { ++x; }
	return x;
} // end function mystery2
