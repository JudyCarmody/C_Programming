#include <stdio.h>

void main()
{
	int i,j,k,num_arr[20], size = 20;
	
	printf("\nEnter 20 integers between 10 and 100: \n");
	for (i = 0; i<size; i++) { scanf("%d", &num_arr[i]); }
	for (i = 0; i < size; i++)
	{
		for (j=i + 1; j < size;)
		{
			if(num_arr[j] == num_arr[i])
			{
				for(k=j; k < size; k++)
				{ num_arr[k] = num_arr[k+1]; }
				
				size--;
			}
			
			else { j++; }
		}
	}
	
	printf("\n The nonduplicate values are\n");
	for(i=0; i<size; i++)
	{ printf("%d ", num_arr[i]); }
	
	printf("\n");
}
