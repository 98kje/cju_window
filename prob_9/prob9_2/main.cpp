#include <stdio.h>


struct Book
{
	char title[30];
	char author[30];
	int page;
	int price;

};

int main(void)
{
	struct Book s1 = {"아버지의 해방일지","정지아",268,12000},
				s2 = {"불편한 편의점2", "김호연",320,12600},
			    s3 = {"하얼빈","김훈",308,14400};

	printf("첫번째 책\n 이름 : %s \n 저자 : %s \n 가격 : %d원 \n 페이지 : %d \n\n", s1.title,s1.author, s1.price, s1.page);
	printf("두번째 책\n 이름 : %s \n 저자 : %s \n 가격 : %d원 \n 페이지 : %d \n\n", s2.title, s2.author, s2.price, s2.page);
	printf("세번째 책\n 이름 : %s \n 저자 : %s \n 가격 : %d원 \n 페이지 : %d \n\n", s3.title, s3.author, s3.price, s3.page);
}