//17932040 김재은 2주차 과제

#include <stdio.h>

int main(void)
{
    int kor = 3, eng = 5, mat = 4;
    int credits;
    credits = kor + eng + mat; //total credits
    double kscore = 3.8, escore = 4.4, mscore = 3.9;
    double grade;
    grade = kscore * kor + escore * eng + mscore * mat;
    double res; // res = result
    res = grade / credits;

    if (credits >= 10 && res > 4.0)
    {
        printf("credits = %d\nres = %lf\n", credits, res);
    }

    return 0;

}