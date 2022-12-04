//17932040 김재은 4주차 과제

#include <stdio.h>

#define TWENTY 20
#define TEENAGERMIN 85   //20세미만 청소년 최소사이즈
#define TEENAGERMAX 95   //20세미만 청소년 최대사이즈
#define ADULTMIN 90      //20세이상 성인 최소사이즈
#define ADULTMAX 100	//20세이상 성인 최대사이즈

int main(void)
{
	int age, chest;
	char size;
	printf("Your age : ");
	scanf_s("%d", &age);
	printf("Your chest size : ");
	scanf_s("%d", &chest);

	if (age < TWENTY)
	{
		if (chest < TEENAGERMIN)
		{
			size = 'S';
		}
		else if (chest >= TEENAGERMIN && chest < TEENAGERMAX)
		{
			size = 'M';
		}
		else if (chest >= TEENAGERMAX)
		{
			size = 'L';
		}
	}
	else if (age >= TWENTY)
	{
		if (chest < ADULTMIN)
		{
			size = 'S';
		}
		else if (chest >= ADULTMIN && chest < ADULTMAX)
		{
			size = 'M';
		}
		else if (chest >= ADULTMAX)
		{
			size = 'L';
		}
	}
	printf("나이는 %d이며 사이즈는 %c입니다.\n", age, size);
}