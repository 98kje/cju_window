#include <stdio.h>

struct cracker
{
	int price;
	char name[20];
	double calories;
};



int main(void)
{
	struct cracker s1 = { 0,"���ĸ�", 0 };  //2580��, 650kcal 
				   
	printf("���ĸ��� ���ݰ� ������ �Է��ϼ��� : ");

	scanf_s("%d%lf", &s1.price, &s1.calories);
	printf("\n\n���� %d �� \t ���� %.1lf kcal\n", s1.price, s1.calories);
	
}