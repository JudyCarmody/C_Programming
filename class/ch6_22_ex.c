#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum (int grades[][EXAMS], size_t pupils, size_t tests);
int maximum (int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(int grades[][EXAMS], size_t pupils, size_t tests);

int main(void)
{
	size_t student;
	int studentGrades[STUDENTS][EXAMS] = {{77,68,86,73},{96,87,89,78},{70,90,86,81}};
	puts("The array is: ");
	printArray(studentGrades, STUDENTS, EXAMS);
	
	printf("\n\nLowest Grade: %d\nHighest Grade: %d\n", minimum(studentGrades, STUDENTS, EXAMS), maximum(studentGrades, STUDENTS, EXAMS));
	
	for(student=0; student<STUDENTS; ++student)
	{
		printf("The average grade for student %u is %.2f\n", student, average(studentGrades[student], EXAMS));
	}
}

int minimum(int grades[][EXAMS], size_t pupils, size_t tests)
{
	size_t i;
	size_t j;
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

int maximum(int grades[][EXAMS], size_t pupils, size_t tests)
{
	size_t i;
	size_t j;
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

double average(const int setOfGrades[], size_t tests)
{
	size_t i;
	int total =0;
	
	for(i=0; i<tests; ++i) { total += setOfGrades[i]; }
	return (double) total/tests;
}

void printArray(int grades[][EXAMS], size_t pupils, size_t tests)
{
	size_t i;
	size_t j;
	
	printf("%s","                  [0]   [1]   [2]   [3]");
	for (i=0; i<pupils; ++i);
	{
		printf("\nStudent [%d] ", i);
		for(j=0; j<tests; ++j) 
		{ printf("%-5d ", grades[i][j]); }
	}
}