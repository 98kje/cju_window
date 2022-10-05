#include <stdio.h>

int main(void)
{
	int i, j, k;

	for (k = 0; k < 1; k++)
	{
		printf("    *");
	}
	printf("\n");


	for (j = 0; j < 2; j++)
	{
		printf("  * ");
	}
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("*   ");
	}
	printf("\n");



	return 0;
}