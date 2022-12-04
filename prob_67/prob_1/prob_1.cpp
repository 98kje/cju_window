//중간고사 전 과제 제출

#include <stdio.h>
#include <string.h>


#define Length 4
#define Stop 5

void input_password(int* num, int size);
void print_input(int* num, int size);
int same_password(int* num1, int* num2);
int diff_password(int* num1, int* num2);
int k = 1;

int password[Length] = { 1, 9, 1, 6 };

int main(void)
{
	int ipPass[Length] = {};   //input password
	

	while (1)
	{

		input_password(ipPass, Length);
		print_input(ipPass, Length);

		if (same_password(ipPass, password))
		{
			break;
		}
		else if (diff_password(ipPass, password))
		{
			break;
		}

	}

}

void input_password(int* num, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%dth password : ", i + 1);
		scanf_s("%d", &num[i]);
	}
}

void print_input(int* num, int size)
{
	printf("input PassWord = ");
	for (int i = 0; i < size; i++)
		printf("%d ", num[i]);
}

int same_password(int* num1, int* num2)
{
	if ((num1[0] == num2[0]) && (num1[1] == num2[1]) && (num1[2] == num2[2]) && (num1[3] == num2[3]))
	{
		printf("\n\n'normal termination ....'\n\n");
		return 1;
	}
	return 0;
}

int diff_password(int* num1, int* num2)
{
	if ((num1[0] != num2[0]) || (num1[1] != num2[1]) || (num1[2] != num2[2]) || (num1[3] != num2[3]))
	{
		
		printf("\n\n'%dth not matched, retry.....'\n\n", k);
		k++;
		if (k == Stop)
		{
			printf("--------------------WARNING! Force close the program.-----------------------\n\n\n\"");
			return 1;
		}
	}
	return 0;
}