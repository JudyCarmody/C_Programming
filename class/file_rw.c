#include <stdio.h>
void main()
{
	FILE * infile;
	FILE * outfile;
	
	int age;
	char name[20];
	
	infile = fopen("myfile.txt", "r");
	outfile = fopen("dupfile.dat", "w");
	
	if (infile == NULL)
		printf("File does not exist.\n");
	else
		printf("Program execution successful.");
	
	while(fscanf(infile,"%s%d", name,&age) !=EOF)
	{
		fprintf(outfile,"%s\t%d\n", name, age);
	}
	
	fclose(infile);
	fclose(outfile);
}