//17932040 김재은 5주차과제

#include <stdio.h>


int main(void)
{
    int input;
    int i, j;
    int ex;
    int Enter = 0;

    printf("2이상의 정수를 입력하세요 : ");
    scanf_s("%d", &input);

    for (i = 2; i <= input; i++)
    {
        ex = 1;
        for (j = 2; j < i; j++)
        {
            if ((i % j) == 0)
            {
                ex = 0;
                break;
            }
        }
        if (ex == 1)
        {
            printf("%d\t", i);
            Enter++;
            if ((Enter % 5) == 0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}