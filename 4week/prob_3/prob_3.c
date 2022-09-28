#include <stdio.h>

int main(void)
{
	int A, B;
	char symbols;

	printf("input your arithmetic operation ; ");
	scanf_s("%d%c%d", &A, &symbols,1, &B);

	switch (symbols)
	{
	case '+':
	{
		int value = A + B;
		printf("value : %d", value);

		break;
	}
	case '-':
	{
		int value = A - B;
		printf("value : %d", value);

		break;
	}
	case '*':
	{
		int value = A * B;
		printf("value : %d", value);

		break;
	}
	case '/':
	{
		int value = A / B;
		printf("value : %d", value);

		break;
	}
	}
	

}
