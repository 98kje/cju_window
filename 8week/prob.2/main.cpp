
#include <stdio.h>
#include <string.h>

#define MAXNUM 15    //max Length

int main(void)
{
	char str1[80] = {};
	char str2[80] = {};
	char str3[80] = {};
	char str4[80] = {};

	printf("Please enter a word : ");
	scanf_s("%s", str1, 80);
	

	for (int i = 5; i < MAXNUM; i++)
	{
		if (strlen(str1) > i)
		{
			strcat_s(str2, "*");
		}
		else if (strlen(str1) == i)
		{
			break;
		}
	}
	strncpy_s(str4, str1, 5);  // Copy only 5 characters and discard the rest
	strcpy_s(str3, str4);      // Put the copied character str3 into it
	strcat_s(str3, str2);      // Put a star on str3.
	
	printf("words entered : %s, \t an omitted word: %s", str1, str3);
	

}