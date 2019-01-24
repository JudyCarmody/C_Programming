#include<stdio.h>
#include<string.h>

// checks to see if user put in too many characters
//	allows user to try again.
void getInput(char *question, char *inputBuffer, int bufferLength)
{	
	printf("%s(Max %d characters)", question, bufferLength-1);
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
}

int main(void)
{
	int size, i, j;
	char outline, message[21]={'\0'}, *inputBuffer;
	
	getInput("Enter message ", message,21);
		
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
		for(j=i; j>=2; j--) // left half
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
	for(i=size+2; i <=size+size; i++)
	{
	
		// left half
		for(j=size+1; j<2*size; j++) // outline; left side
		{
			if(i==j)
			{
				printf("%c", outline);	
				
				if(i!=size/2 && j!=size)
				{
					if(i<strlen(inputBuffer) && i>=size/2)
					{	
						printf("%3s", " ");	
						j=strlen(inputBuffer-1);		
						inputBuffer = message;
						while(*inputBuffer!='\0')
						{
							printf("%c", *inputBuffer); // prints message
							inputBuffer++;
							j = strlen(inputBuffer-1);			
						}
					}
					else
						printf(" "); // left side, interior, immediate right of outline
				}
				else
					printf(" "); // does not print
			}
			else
				printf(" "); // exterior and interior, left, skip diagonal immediately right of outline
		}
			
		// right half
		for(j=2*size; j>=size-1; j--) // outline; right side
		{
			if(i==j)
			{
				printf("%c", outline); // outline
			
				if(i==size/2 && j==size)
				{
					for(j<=size-1; j>=0; j--) // space exterior to outline, remove line 124
						printf(" "); // does not print unless line 124 is removed
				}
			}
			else
				printf(" "); // right side, interior and exterior to outline
		}
		printf("\n");

	}
}
