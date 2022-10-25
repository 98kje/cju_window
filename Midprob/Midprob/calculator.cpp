#include "calculator.h"

double CCA1, CCA2;
char symbols;
double value;

void calculator_input(void)
{
	scanf_s("%lf", &CCA1);
	scanf_s("%c", &symbols,(2));
	scanf_s("%lf", &CCA2);

}

void calculator(void)
{
	switch (symbols)
	{
	case '+':
	{
		double value = CCA1 + CCA2;
		printf("value : %.2lf\n\n", value);

		break;
	}
	case '-':
	{
		double value = CCA1 - CCA2;
		printf("value : %.2lf\n\n", value);

		break;
	}
	case '*':
	{
		double value = CCA1 * CCA2;
		printf("value : %.2lf\n\n", value);

		break;
	}
	case '/':
	{
		double value = CCA1 / CCA2;
		printf("value : %.2lf\n\n", value);

		break;
	}
	}
}