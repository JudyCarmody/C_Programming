// ex07_26.c
// What does this program do?
// --- checks if two strings are the same (1 = TRUE, they are the same; 0 = FALSE, they are not the same)

#include<stdio.h>
#define SIZE 80

int mystery3(const char *s1, const char *s2); // prototype

int main(void)
{
	char string1[SIZE]; //create char array
	char string2[SIZE]; //create char array
	puts("Enter two strings: ");
	scanf("%79s%79s", string1, string2);
	printf("The result is: %d\n", mystery3(string1,string2));
} //end main

int mystery3(const char *s1, const char *s2)
{
	int result = 1;
	for(; *s1!='\0' && *s2!='\0'; ++s1, ++s2)
	{
		if(*s1 != *s2) { result = 0; }
		
	} // end for
	
	return result;
} // end function mystery3
