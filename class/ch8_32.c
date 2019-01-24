#include<stdio.h>
#include<string.h>
int main()
{
	int i=0, j=0, k=0;

	char date[11], month[3], day[3], year[5];
	char *strToken = date;
	const char delim[2] = "/";
	
	puts("Enter a date in this format: mm/dd/yyyy: ");
	scanf("%10s", date);
	puts(""); // for new line

	// this block puts the tokens into new arrays
	while (strToken != NULL && i == 0)
	{
		strToken = strtok(date, delim);
		sscanf(date, "%s %*s %d", month, &i);
		
		strToken = strtok(NULL, delim);
		sscanf(strToken, "%s %*s %d", day, &j);
		
		strToken = strtok(NULL, delim);
		sscanf(strToken, "%s %*s %d", year, &k);
		i++;
	}
	
	// checks month[0], then checks month[1] to find appropriate month
	if(month[0] == '0')
		{
			if(month[1] == '1')
				printf("January %s, %s\n",day, year);
			if(month[1] == '2')
				printf("February %s, %s\n",day, year);
			if(month[1] == '3')
				printf("March %s, %s\n",day, year);
			if(month[1] == '4')
				printf("April %s, %s\n",day, year);
			if(month[1] == '5')
				printf("May %s, %s\n",day, year);
			if(month[1] == '6')
				printf("June %s, %s\n",day, year);
			if(month[1] == '7')
				printf("July %s, %s\n",day, year);
			if(month[1] == '8')
				printf("August %s, %s\n",day, year);
			if(month[1] == '9')
				printf("September %s, %s\n",day, year);
	}
	
	if(month[0] == '1')
	{
		if(month[1] == '0')
			printf("October %s, %s\n",day, year);
		if(month[1] == '1')
			printf("November %s, %s\n",day, year);
		if(month[1] == '2')
			printf("December %s, %s\n",day, year);
	}	
	
	return (0);
}
