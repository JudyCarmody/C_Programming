#include<stdio.h>
void main()
{
	long *lPtr, value1 = 200000, value2;
	lPtr = &value1;
	printf("value of value1: %ld\n", *lPtr);
	value2 = *lPtr;
	printf("value of value2: %ld\n", value2);
	printf("address of value1 (&value1):\t%p\n", &value1);
	printf("address of valuei (lPtr):\t%p\n", lPtr);
}
