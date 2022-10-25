#include <stdio.h>

int main(void)
{
	int a, b;
	int i=0 , j=0;
	printf("2이상의 정수를 입력하세요 : ");	
	scanf_s("%d", &i);

	for (int a = 2; j <= 100; a++)
	{
		j % a != 0;
		printf("%d", a);
		if (a == 6) break;
	}

	
}
