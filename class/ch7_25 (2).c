#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void printArray(int grades[][EXAMS], int pupils, int tests);
int minimum (int grades[][EXAMS], int pupils, int tests);
int maximum (int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGrades[], int tests);

int main(void)
{
	int student;
	int studentGrades[STUDENTS][EXAMS] = {{77,68,86,73},{96,87,89,78},{70,90,86,81}};
	int menu;
	char yn = 'y';
	
	while(yn=='y' || yn == 'Y')
	{
		printf("Enter a choice:\n"
		"0 Print the array of grades"
		"1 Find the minimum grade"
		"2 Find the maximum grade"
		"3 Print average on all tests for each student"
		"4 End program");
		scanf("%d", &menu);
	}
	
	while(menu <=4 && menu <=0)
	{
		switch(menu)
		{
			case 0: // print array
				printArray(studentGrades, STUDENTS, EXAMS);
				break;
			case 1: // find minimum
				printf("The minimum grade is: %d",  minimum(studentGrades, STUDENTS, EXAMS);
				break;
			case 2: // find maximum
				printf("The maximum grade is: %d", maximum(studentGrades, STUDENTS, EXAMS);				
				break;
			case 3: // print average
				for(student=0; student<STUDENTS; ++student)
				{ printf("The average for student %u is: %.2f\n", student, average(studentGrades[student], EXAMS)); }
				break;
			case 4:
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid input.\n");
		}
	}
	printf ("Would you like to enter another choice? Y/N\n");
	scanf("%c", yn);
}

void printArray(int grades[][EXAMS], int pupils, int tests)
{
	int i;
	int j;
	
	printf("%s","\t\t\t\t[0]\t[1]\t[2]\t[3]");
	for (i=0; i<pupils; ++i);
	{
		puts("The array is:\n");
		printf("\nStudent Grades[%d] ", i);
		for(j=0; j<tests; ++j) { printf("%-5d", grades[i][j]); }
	}
}

int minimum(int grades[][EXAMS], int pupils, int tests)
{
	int i;
	int j;
	int lowGrade = 100;
	
	for(i=0; i<pupils; ++i)
	{
		for (j=0; j<tests; ++j)
		{
			if(grades[i][j] < lowGrade) { lowGrade = grades [i][j]; }
		}
	}
	return lowGrade;
}

int maximum(int grades[][Exams], int pupils, int tests)
{
	int i;
	int j;
	int highGrade = 0;
	
	for(i=0; i<pupils; ++i)
	{
		for(j=0; j<tests; ++j)
		{
			if(grades[i][j]>highGrade) { highGrade = grades[i][j]; }
		}
	}
	return highGrade;
}

double average(const int setOfGrades[], int tests)
{
	int i;
	int total =0;
	
	for(i=0; i<tests; ++i) { total += setOfGrades[i]; }
	return (double) total/tests;
}