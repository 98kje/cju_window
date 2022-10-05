#include <stdio.h>

int main(void)
{
	int a, b, c, d;
	int result;
	int stage;

	printf("What TIMES TABLE ? : ");
	scanf_s("%d", &stage);
	while (stage)
	{
		printf("Let's Times Tables #%d\n", stage);
		for (a = 1; a < 10; a++)
		{
			result = stage * a;
			printf("%d * %d = %d\n", stage, a, result);
			continue;
			if (a == 10) break;
		}break;
	}
	
	
	
}