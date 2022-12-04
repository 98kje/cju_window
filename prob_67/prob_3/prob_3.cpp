//중간고사 전 과제 제출


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INPUT_LENGTH1 6
#define INPUT_LENGTH2 6
#define TWO 2
#define THREE 3
#define NMCOLUMN 3
#define MNCOLUMN 2
#define CROW 3
//void A_result(int* A,int* B,int* C, int size);

void input(int* num1, int* num2, int size); //ㅇ

int main()
{   
	
	int A[TWO][THREE] = {}; //ㅇ
	int B[THREE][TWO] = {}; //ㅇ
	int C[TWO][TWO] = {};
	int D[THREE][THREE] = {};

	int(*pointerA)[NMCOLUMN];  //ㅇ
	int(*pointerB)[MNCOLUMN];  //ㅇ 

	
	pointerA = A; //ㅇ
	pointerB = B;// ㅇ
	

	srand(time(NULL));

	input(* pointerA, * pointerB, INPUT_LENGTH1);

	
	printf("\tA Matrix Output\n\n");
	printf("\t| %d, %d, %d |\n", A[0][0], A[0][1], A[0][2]);
	printf("\t| %d, %d, %d |\n", A[1][0], A[1][1], A[1][2]);
	
	
		
	printf("\n\n\tB Matrix Output\n\n");
	printf("\t| %d, %d |\n", B[0][0], B[0][1]);
	printf("\t| %d, %d |\n", B[1][0], B[1][1]);
	printf("\t| %d, %d |\n", B[2][0], B[2][1]);


	//A_result(pointerA, pointerB, C, THREE);

	for (int i = 0; i < THREE; i++)
	{
		C[0][0] += A[0][i] * B[i][0];
	}
	for (int i = 0; i < THREE; i++)
	{
		C[0][1] += A[0][i] * B[i][1];
	}
	for (int j = 0; j < THREE; j++)
	{
		C[1][0] += A[1][j] * B[j][0];
	}
	for (int j = 0; j < THREE; j++)
	{
		C[1][1] += A[1][j] * B[j][1];
	}
	printf("\n\n\tAXB Matrix Output\n\n");
	printf("\t| %d, %d |\n", C[0][0], C[0][1]);
	printf("\t| %d, %d |\n", C[1][0], C[1][1]);
	
	
	for (int j = 0; j < TWO; j++)
	{
		D[0][0] += B[0][j] * A[j][0];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[0][1] += B[0][j] * A[j][1];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[0][2] += B[0][j] * A[j][2];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[1][0] += B[1][j] * A[j][0];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[1][1] += B[1][j] * A[j][1];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[1][2] += B[1][j] * A[j][2];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[2][0] += B[2][j] * A[j][0];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[2][1] += B[2][j] * A[j][1];
	}
	for (int j = 0; j < TWO; j++)
	{
		D[2][2] += B[2][j] * A[j][2];
	}


	printf("\n\n\tBXA Matrix Output\n\n");
	printf("\t| %d, %d ,%d |\n", D[0][0], D[0][1], D[0][2]);
	printf("\t| %d, %d ,%d |\n", D[1][0], D[1][1], D[1][2]);
	printf("\t| %d, %d ,%d |\n", D[2][0], D[2][1], D[2][2]);
	

	return 0;
}

void input(int* num1, int*num2 , int size)
{
	
	for (int i = 0; i < size; i++)
	{
		num1[i] = rand() % 100;
	}
	for (int j = 0; j < size; j++)
	{
		num2[j] = rand() % 100;
	}
}