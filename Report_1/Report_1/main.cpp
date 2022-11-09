#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[] = "C:/Document/Github/Test1/test.txt";
	char* ptr = str;
	char* ptrF[1000] = { NULL, };
	char str2[] = "test2";

	char* ptrsplit = strtok(str, "/");
	int counter = 0;
	while (ptrsplit != NULL)
	{
		ptrF[counter] = ptrsplit;
		counter++;
		ptrsplit = strtok(NULL, "/");
	}
	for (int i = 0; i < counter; i++)
	{
		printf("%d, %s\n", i, ptrF[i]);
	}
	printf("\n\n\============ º¯°æÈÄ ========= \n\n");
	ptrF[3] = { str2 };


	for (int i = 0; i < counter; i++)
	{
		printf("%d, %s\n", i, ptrF[i]);
	}
}