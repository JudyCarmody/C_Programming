// input: 92.6, 77.5, 66.3, 90.7, 87.2

#include<stdio.h>
#include<math.h>
#include<string.h>

#define NUM_STUDENT 5

typedef struct Students
{
  float grade;
  char name[10];
}Students;

Students arrStudent[NUM_STUDENT];

void calcAvg(Students arrStudent[]);
void descendSort(Students arrStudent[]);

void main()
{
	int i;
	
	for(i = 0; i<NUM_STUDENT; i++)
	{
		puts("Enter student name: ");
		scanf("%s", arrStudent[i].name);
		puts("Enter grade for this student: ");
		scanf("%f", &arrStudent[i].grade);
	}
	
	puts("");
	calcAvg(arrStudent);
	descendSort(arrStudent);
}

void calcAvg(Students arrStudent[])
{		
	int i, avg, total = 0;
	for(i = 0; i < NUM_STUDENT; i++) { total += ceil(arrStudent[i].grade); }
	avg = (int)total/NUM_STUDENT;
	printf("Class average: %d\n\n", avg);
}

void descendSort(Students arrStudent[])
{
	int i, j;
	Students temp;
	for(i = 0; i<NUM_STUDENT; i++)
	{
		for(j=i+1; j<NUM_STUDENT; j++)
		{
			if(arrStudent[i].grade < arrStudent[j].grade)
			{
				temp = arrStudent[i];
				arrStudent[i] = arrStudent[j];
				arrStudent[j] = temp;
			}
		}
	}
	
	for(i = 0; i<NUM_STUDENT; i++)
	printf("%12s%5c%.0f\n", arrStudent[i].name, ' ', ceil(arrStudent[i].grade));
	puts("");
}