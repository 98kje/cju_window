
#include <stdio.h>

#define MINSIZE 90
#define MAXSIZE 100 

int main(void)
{   
	int chest;
	char size;

	printf("chest = ");
	scanf_s("%d", &chest);

	if (chest <= MINSIZE)
	{
		size = 'S';
		printf("your size %c", size);  
	}

	else if (chest >= MINSIZE && chest <= MAXSIZE)
	{
		size = 'M';
		printf("your size %c", size);
	}
	
	else if (chest > MAXSIZE)
	{
		size = 'L';
		printf("your size %c", size);
	}
	return 0;

}