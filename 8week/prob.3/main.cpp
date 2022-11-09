#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = {};
	char str2[80] = {};
	char str3[80] = {};

	char* resp1 = NULL;   //pointer init
	char* resp2 = NULL;
	char* resp3 = NULL;
	
	printf("Enter three words : ");
	scanf_s("%s%s%s", str1,80, str2,80, str3,80);
	printf("\n\nwords entered : %s %s %s", str1, str2, str3);

	// This is how the relationship is expressed

	if (strlen(str1) > strlen(str2))
		resp1 = str1;
	else
		resp1 = str2;

	if (strlen(resp1) > strlen(str3))
		{
			if (strlen(str3) > strlen(str1))
			{
				resp2 = str3;
				resp3 = str1;
			}
			else if (strlen(str3) > strlen(str2))
			{
				resp2 = str3;
				resp3 = str1;
			}
		}
		
	else if (strlen(str1) < strlen(str3))
	{
		resp1 = str3;
		if (strlen(str1) > strlen(str2))
		{
			resp2 = str1;
			resp3 = str2;
		}
		else if (strlen(str1) < strlen(str2))
		{
			resp2 = str2;
			resp3 = str1;
		}
	}
	printf("\n\nAfter the change : %s %s %s\n\n", resp1, resp2, resp3);
	


}