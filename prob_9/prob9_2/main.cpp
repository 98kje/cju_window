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
	struct Book s1 = {"�ƹ����� �ع�����","������",268,12000},
				s2 = {"������ ������2", "��ȣ��",320,12600},
			    s3 = {"�Ͼ��","����",308,14400};

	printf("ù��° å\n �̸� : %s \n ���� : %s \n ���� : %d�� \n ������ : %d \n\n", s1.title,s1.author, s1.price, s1.page);
	printf("�ι�° å\n �̸� : %s \n ���� : %s \n ���� : %d�� \n ������ : %d \n\n", s2.title, s2.author, s2.price, s2.page);
	printf("����° å\n �̸� : %s \n ���� : %s \n ���� : %d�� \n ������ : %d \n\n", s3.title, s3.author, s3.price, s3.page);
}