#include <stdio.h>

int main(void)
{
    char ch;

    printf("input : ");
    scanf_s("%c", &ch);
    printf("%c ASCII Value is %d\n", ch, ch);
}