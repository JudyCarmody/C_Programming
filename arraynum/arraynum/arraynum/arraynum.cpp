#include <stdio.h>
#define NUM_ARR_SIZE 20;
#define FREQ_SIZE 20;

int num_arr[20] = {22, 56, 78, 94, 22, 94, 38, 10, 11, 12, 22, 12, 13, 14, 15, 16, 17, 88, 88, 77};
int frequency[20];

size_t arr_count;
size_t freq_count;

void main()
{
	int i,j;

	for (arr_count = 0; arr_count<NUM_ARR_SIZE; ++arr_count)
	{ ++frequency[num_arr[arr_count]]; }

	for(freq_count = 1; freq_count<FREQ_SIZE; ++freq_count)
	{ printf("%6d%17d\n", freq_count, frequency[freq_count]); }
}