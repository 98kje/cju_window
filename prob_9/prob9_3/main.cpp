#include <stdio.h>

struct cracker
{
	int price;
	char name[20];
	double calories;
};



int main(void)
{
	struct cracker s1 = { 0,"양파링", 0 };  //2580원, 650kcal 
				   
	printf("양파링의 가격과 열량을 입력하세요 : ");

	scanf_s("%d%lf", &s1.price, &s1.calories);
	printf("\n\n가격 %d 원 \t 열량 %.1lf kcal\n", s1.price, s1.calories);
	
}