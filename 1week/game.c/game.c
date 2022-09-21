#include <stdio.h>
//make Rock Paper Scissors

int main(void)
{
	int num1;

	printf("START Rock Paper Scissors!!\n");
	printf("Choice 1, 2, 3 : \n");
	scanf_s("%d", &num1);
	if (num1 == 1)
	{
		printf("win\n");
	}
	else if (num1 == 2)
	{
		printf("draw\n");
	}
	else if (num1 == 3)
	{
		printf("lose\n");
	}

	return 0;
}