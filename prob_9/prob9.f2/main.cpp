#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h><p>

int main(void)
{
	FILE* fp;
	FILE* fp2;
	char buff[100];
	char buff2[100];
	int x = 0;
	fp = fopen("C:\\programing\\yolo_label_data.txt", "r"); //���� ���� �� �������
	fp2 = fopen("C:\\programing\\yolo_bbox_data.txt", "r");
	if (fp == NULL) 
	{
		if (fp2 == NULL)
		{
			printf("�Է������� ���� �����ϴ�.");

		}
	}
	while(1)
	{
		if (fp != NULL)
		{
			fgets(buff, 100, fp);
			printf("%s", buff);
			if (fp2 != NULL)
			{
				fgets(buff2, 100, fp2);
				printf("%s",buff2);

			}
		}
		x++;
		if (x == 5)
		{
			break;
		}
		
	}
	system("pause");
	return 0;
}