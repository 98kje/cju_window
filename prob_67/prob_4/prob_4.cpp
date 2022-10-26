#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void random_input(int* num, int size);

int main(void)
{
    int i, j, k;
    int l, n, m;
    int result[3] = {};
    int selct_1, selct_2;

    srand(time(NULL));

    random_input(result, 3);

    printf("정렬 전 : [% d, % d, % d] \n\n", result[0], result[1], result[2]);
    while (1)
    {
        for (i = 0; i < 3; i++) {
            for (j = i + 1; j < 4; j++)
                if (result[i] < result[j]) {
                    selct_1 = result[i];
                    result[i] = result[j];
                    result[j] = selct_1;

                }
        }
        printf("오른차순 정렬 후 : ");
        for (k = 0; k < 3; k++)
        {
            printf("[ %d ]\n", result[k]);

        }
       int exit;
       printf("next input 'z'\n" );
       scanf_s("%d", &exit);
       if (exit == 3); break;
    }


    printf("내림차순 정렬 후 : ");
    for (m = 2; m >= 0; m--)
    {
        printf("[ %d ]\n", result[m]);
    }
}

void random_input(int* num, int size)
{
    for (int i = 0; i < size; i++)
    {
        num[i] = rand() % 100;
    }
}