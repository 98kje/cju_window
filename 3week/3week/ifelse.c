#include <stdio.h>

#define MAXLIMIT 40
#define MINLIMIT 10

int main(void)
{

	int nA = 0;
	int nB = 0;

	printf("input your integer variable : ");
	scanf_s("%d\n", &nA);
	scanf_s("%d", &nB);

	int nRes = nA + nB;

	if (nRes > MAXLIMIT)
	{
		printf("your Result : %d, is over MAXLIMT ", nRes);
	}
	else if (nRes < MINLIMIT)
	{
		printf("your Result : %d, is under MINLIMT ", nRes);
	}
	else if (MINLIMIT < nRes < MAXLIMIT)
	{
		printf("your Result : %d", nRes);
	}



	return 0;

}


