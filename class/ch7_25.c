#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

const int studentGrades[STUDENTS][EXAMS] = {{77,68,86,73},{96,87,89,78},{70,90,86,81}};
int student = STUDENTS;

int minimum (const int grades[][EXAMS], int pupils, int tests);
int maximum (const int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGrades[], int pupils, int tests);
int printArray(const int grades[][EXAMS], int pupils, int tests);

void one(int a);
void two(int b);
void three(int c);
void four(int d);
void five(int e);

int main(void)
{
	void(*processGrades[5])(int) = {one,two,three,four,five};
	int menu;
	
	printf("%s", "Enter a choice:\n0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n3 Print average on all tests for each student\n4 End program\n");
	scanf("%d", &menu);
	
	while(menu >=0 && menu <5)
	{
		(*processGrades[menu])(menu);
		
		printf("%s", "Enter a choice:\n0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n3 Print average on all tests for each student\n4 End program\n");
		scanf("%d", &menu);
	}
}

void one(int a)
{
	printf("%s", "The array of grades:\n");
	printf("%s","           [0] [1] [2] [3]");
	for(student=0; student<STUDENTS; ++student) { printArray(studentGrades, STUDENTS, EXAMS); }
	puts("\n");
}

void two(int b) { minimum(studentGrades, STUDENTS, EXAMS); }
void three(int c) { maximum(studentGrades, STUDENTS, EXAMS); }
void four(int d)
{
	puts("");	
	for(student=0; student<STUDENTS; ++student) { average(studentGrades[student], STUDENTS, EXAMS); }
	puts("");
}

void five(int e)
{
	puts("Program execution terminated.\n");
	exit(EXIT_SUCCESS);
}

int minimum(const int grades[][EXAMS], int pupils, int tests)
{
	int i;
	int j;
	int lowGrade = 100;
	
	for(i=0; i<pupils; ++i) { for (j=0; j<tests; ++j) { if(grades[i][j] < lowGrade) { lowGrade = grades [i][j]; } } }
	printf("\nMinimum Grade: %d\n\n", lowGrade);
	return 0;
}

int maximum(const int grades[][EXAMS], int pupils, int tests)
{
	int i;
	int j;
	int highGrade = 0;
	
	for(i=0; i<pupils; ++i) { for(j=0; j<tests; ++j) { if(grades[i][j]>highGrade) { highGrade = grades[i][j]; } } }
	printf("\nMaximum Grade: %d\n\n", highGrade);
	return 0;
}

double average(const int setOfGrades[], int pupils, int tests)
{
	int i;
	int total =0;
	double averageGrade;
		
	for(i=0; i<tests; ++i) { total += setOfGrades[i]; }
	averageGrade = (double) total/tests;
	printf("Average Grade for student[%d]: %.2lf\n", student, averageGrade);
	return 0;
}

int printArray(const int grades[][EXAMS], int pupils, int tests)
{
	int i;
	int j;
	
	puts("");	
	for (i=0; i<student; ++i);
	{
		printf("\nStudent [%d] ", i);
		for(j=0; j<tests; ++j) { printf("%-3d ", grades[i][j]); }
	}
	
	return 0;
}