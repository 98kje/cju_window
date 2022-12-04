//중간고사 전 과제 제출

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LENGTH 5

void random_array(int* num, int size);
void Add_value(double* A, double B);
void addXtotal(double* A, double* B);


int main(void)
{
	int array[LENGTH];
	double average = 0.0;
	int total = 0;
	double X[LENGTH];
	double Xtotal[LENGTH];
	double Xtotalvalue = 0;


	srand(time(NULL));

	random_array(array, LENGTH);

	for (int j = 0; j < LENGTH; j++)
	{
		total += array[j];
	}

	for (int k = 0; k < LENGTH; k++)
	{
		printf("[X%d] = %d \n", k, array[k]);

	}
	average = total / LENGTH;
	printf("\n\naverage : %lf\n\n", average);
	for (int l = 0; l < LENGTH; l++)
	{
		X[l] = array[l] - average;

		printf("\n\nEach deviation is X%d = %lf\n",l, X[l]);
	}
	printf("\n\n");
	addXtotal(X, Xtotal);

	Add_value(Xtotal, Xtotalvalue);

	return 0;

}
void random_array(int* num, int size)
{

	for (int i = 0; i < size; i++)
	{
		int total[LENGTH] = {};
		num[i] = rand() % 100;
		total[i] += num[i];

	}

}
void addXtotal(double* A, double* B)
{
	printf(" X total = X^2\n\n");
	for (int i = 0; i < LENGTH; i++)
	{
		B[i] = A[i] * A[i];
		printf("Xtotal = %lf\t", B[i]);
	}

}

void Add_value(double* A, double B)
{
	double variance = 0;
	for (int i = 0; i < LENGTH; i++) {
		B += A[i];
	}

	printf("\n\nXtotalvalule = %lf\t", B);
	variance = B / LENGTH;
	printf("Variance Value : %lf\n\n", variance);

	printf("Standard Deviation : %lf\n\n", sqrt(variance));

}