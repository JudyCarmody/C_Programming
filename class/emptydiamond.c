#include<stdio.h>
void main()
{
  int i,j,row;

  printf("Enter the number of rows you want:\n");
  scanf("%d",&row);
  for(i=1;i<=row;i++)
  {
    for(j=row;j>=1;j--)
    {
      if(i==j)
	printf("~");
      else
	  {
		if (i==j+1)
			printf("!");
		else
			printf("q");
	  }
    }
     for(j=2;j<=row;j++)
    {
      if(i==j)
	printf("@");
      else
	printf("^");
    }
    printf("\n");
  }
  for(i=row+1;i<=row+row;i++)
  {
  for(j=row+1;j<=row+row;j++)
    {
      if(i==j)
	printf("#");
      else
	  {
		  if(i==j-1)
			printf("hello world");
			else
				printf("p");
	  }
    }
    for(j=row+row-1;j>=row+1;j--)
    {
      if(i==j)
	printf("*");
      else
	printf("(");
    }
    printf("\n");
  }
}

/*
#include<stdio.h>
#include<conio.h>
void main()
{
  int i,j,row;
  clrscr();
  printf("Enter the number of rows you want:\n");
  scanf("%d",&row);
  for(i=1;i<=row;i++)
  {
    for(j=row;j>=1;j--)
    {
      if(i==j)
	printf("*");
      else
	printf(" ");
    }
     for(j=2;j<=row;j++)
    {
      if(i==j)
	printf("*");
      else
	printf(" ");
    }
    printf("\n");
  }
  for(i=row+1;i<=row+row;i++)
  {
  for(j=row+1;j<=row+row;j++)
    {
      if(i==j)
	printf("*");
      else
	printf(" ");
    }
    for(j=row+row-1;j>=row+1;j--)
    {
      if(i==j)
	printf("*");
      else
	printf(" ");
    }
    printf("\n");
  }
  getch();
}
*/