#include <stdio.h>

int rec_func(int n)
{
	if (n == 1)
		return 1;

	return (n + rec_func(n - 1));
}

int main()
{
	int n = 0;
	printf("input : ");
	scanf_s("%d", &n);

	printf("result : %d\n", rec_func(n));

	return 0;
}
