#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h><p>

int main(void)
{
	FILE* fp;
	char buff[100];

	fp = fopen("C:\\programing\\kimjaeeun.txt", "w+"); //파일 쓰기 및 생성모드
	if (fp == NULL) {
		printf("입력파일을 열수 없습니다.");
	}
	if (fp != NULL) {

		fputs("12324\n", fp);
		fputs("123.424121\n", fp);
		fputs("A\n", fp);
		fputs("Helloword\n", fp);
		
		fclose(fp);
	}

	fp = fopen("C:\\programing\\kimjaeeun.txt", "r");

	if (fp != NULL) {
		while (!feof(fp)) {
			fgets(buff, 100, fp);
			printf(buff);
		}
		fclose(fp);
	}
	system("pause");
	return 0;
}