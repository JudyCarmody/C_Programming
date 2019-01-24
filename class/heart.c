#include<stdio.h>
#include<string.h>

// if user's message is too long, print error and allow user to try again
int getInput(char *question, char *inputBuffer, int bufferLength)
{
	printf("%s (Max %d characters): ", question, bufferLength-1);
	fgets(inputBuffer, bufferLength, stdin);
	if(inputBuffer[strlen(inputBuffer)-1] != '\n')
	{
		int dropped = 0;;
		while(fgetc(stdin) != '\n')
			dropped++;
		if(dropped>0)
		{
			printf("Too many characters.  Input over by %d characters.\n", dropped);
			getInput(question, inputBuffer, bufferLength);
		}
	}
	
	else
		inputBuffer[strlen(inputBuffer)-1] ='\0';
	return 0;
}

int main(void)
{
	int size, i, j;
	char outline, message[21];
	
	getInput("Enter message ", message, 21);
		
	printf("Enter character heart will be made of: ");
	scanf("%c", &outline);
	
	printf("Enter size of heart: ");
	scanf("%d", &size);

	// top
	for(i=0; i<=size; i+=2)
	{
		// spacing for left side; centers both semi circles
		for(j=1; j<size-i; j+=2)
			printf(" ");
		
		// left semi circle
		for(j=i; j>=2; j--) // left half
		{
			if(i==j)
				printf("%c", outline);
			else
				printf(" ");
		}
		
		for(j=1; j<=i; j++) // right half
		{
			if(i==j)
				printf("%c", outline);
		}
		
		// Space for Center
		for(j=1; j<=size-i; j++)
			printf(" ");
		
		// right semi circle
		for(j=i; j>=1; j--) // left half
		{
			if(i==j)
				printf("%c", outline);
		}
		
		for(j=1; j<=i; j++) // right half
		{
			if(i==j)
				printf("%c", outline);
			else
				printf(" ");
		}
		printf("\n");  
	}  
	
	// bottom
	for(i=1; i<=2*size+1; i++)
	{	
		for(j=size; j<2*size; j++) // outline; left side
		{
			if(i==j)
			{
				printf("%c", outline);
			
				for(j=i; j<4*size+1-2*i; j++)
				{
					printf("%s\n", message);
					j+=strlen(message)-1;
				}
			}
			else
				printf(" ");
		}
			
		for(j=size+size; j>=size+1; j--) // outline; right side
		{
			if(i==j)
				printf("%c", outline);
			else
				printf(" ");
		}
		printf("\n");
	}
}
