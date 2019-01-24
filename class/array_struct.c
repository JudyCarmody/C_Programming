#include<stdio.h>
#include<math.h>

#define STUDENTS 5

typedef struct
{
	char studentName[20];
	float examScore;
} StudentGrades;

void calcAvg(StudentGrades const * ptrInput);
void descendingDisplay(StudentGrades const * ptrInput);

void main()
{
	struct StudentGrades *ptrInformation;
	int count = 0;
	StudentGrades input[STUDENTS];
	
	printf("Enter name and grade:\n");
	
	while (count <STUDENTS)
	{
		scanf("%c,%f", &input);
		count++;
	}
	
	calcAvg(input);
	descendingDisplay(input);
}

void calcAvg(StudentGrades const *ptrInput)
{
	puts("In classAvg function.\n---Nothing Here---\n\n");
	printf("Name: %s -- Grade: %.0f", input.studentName, input.examScore);
}

void descendingDisplay(StudentGrades const * ptrInput)
{
	puts("In descendingDisplay function.\n---Nothing Here---\n\n");
}