//17932040 김재은 2주차 과제

#include <stdio.h>

int main(void)
{
    double weight;
    double height_s;
    double bmi;

    double height_m;
    double height_squared;

    printf("weight(kg) and height(cm) input : ");
    scanf_s("%lf", &weight);
    scanf_s("%lf", &height_s);

    height_m = height_s / 100;
    height_squared = height_m * height_m;

    bmi = weight / height_squared;

    if (bmi > 40)
    {
        printf("Severely obese \n");
    }
    else if (bmi >= 30.0 && bmi < 40)
    {
        printf("Obese \n");
    }
    else if (bmi >= 25 && bmi < 30)
    {
        printf("Overweight \n");
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        printf("Healthy/normal \n");
    }
    else if (bmi < 18.5)
    {
        printf("Underweight \n");
    }

    return 0;
}