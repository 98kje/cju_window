#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Enter 1


int main(void)
{
	int num = 0;
	int sizer = 0;
	int count = 0;
	char* pi = {};

	
	int i,j, k = 0;
	
	printf("양수를 입력하세요 : ");
	scanf_s("%d", &num);

	pi = (char*)malloc(num * sizeof(char));

	if (pi == NULL)
	{
		printf("메모리가 부족합니다 .\n");
		exit(1);

	}


	for (i = 2; i < num; i++)
	{

		for (j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{

				pi[count] = 'x';
				break;

			}
		}if (i == j)
			pi[count] = i;
		count += 1;

	}

	

	
	for (int i = 0; i < count; i++)
	{
		if (pi[i] == 120)
		{
			sizer = pi[i];
			k = i;
			k++;
			printf("\tx");
			
		}
		else
		{
			printf("\t%d", pi[i]);
		}
		
		if (((i + Enter) % 5) == 0)
		{
		printf("\n");
		}

		
	}
	free(pi);
	
	return 0;
}