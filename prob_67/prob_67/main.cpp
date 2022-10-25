#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define input_num 100
#define average 0
#define Standard_Deviation 1

void input_rand(double* num1, double* num2, int Size);
void print_Vertical(double* num, int Size);
void print_Horizon(double* num, int Size);
void Vvalue_Vertical(double* num1, double* num2, int Size);
void Vvalue_Horizon(double* num1, double* num2, int Size);
void ZKvalue_Vertical(double* Z, double* K, double* Vv, double* Verti, int Size);
void ZKvalue_Horizon(double* Z, double* K, double* Vv, double* Hori, int Size);
void PrintZKvalue_Vertical(double* Z, double* K, int Size);
void PrintZKvalue_Horizon(double* Z, double* K, int Size);
void X_V(double* Xv, double* NZ_v, int Size);
void X_H(double* Xh, double* NZ_h, int Size);
void print_Xv(double* Xv, int Size);
void print_Xh(double* Xh, int Size);

int main(void)
{
	double page[20][20] = {};

	double result1;
	result1 = exp(1.0);
	double random;

	srand(time(NULL));

	double Vertical[100] = {};
	double Horizon[100] = {};
	double ReVerti[100] = {};
	double ReHoriz[100] = {};
	double Vvalue_v[100] = {};
	double Vvalue_h[100] = {};
	double Z_v[100] = {};
	double K_h[100] = {};
	double Z_h[100] = {};
	double K_v[100] = {};
	double nomalZ_v[100] = {};
	double nomalZ_h[100] = {};
	double Standard_Zv[] = { 0 };
	double Standard_Zh[] = { 0 };
	double X_v[100] = {};
	double X_h[100] = {};

	input_rand(Vertical, Horizon, input_num);
	printf("Horizon 수정 전\n\n");
	for (int i = 0; i < input_num; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", Vertical[i]);
	}
	printf("\n\nHorizon 수정 전\n\n");
	for (int i = 0; i < input_num; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", Horizon[i]);
	}

	Vvalue_Vertical(Vvalue_v, Vertical, input_num);

	Vvalue_Horizon(Vvalue_h, Horizon, input_num);

	ZKvalue_Vertical(Z_v, K_v, Vvalue_v, Vertical, input_num);

	ZKvalue_Horizon(Z_h, K_h, Vvalue_h, Horizon, input_num);

	while (1)
	{
		Vvalue_Vertical(Vvalue_v, Vertical, input_num);

		Vvalue_Horizon(Vvalue_h, Horizon, input_num);

		ZKvalue_Vertical(Z_v, K_v, Vvalue_v, Vertical, input_num);

		ZKvalue_Horizon(Z_h, K_h, Vvalue_h, Horizon, input_num);

		for (int i = 0; i < input_num;)
		{
			if (K_v[i] < 1 - Vertical[i])
			{
				nomalZ_v[i] = Z_v[i];
				ReVerti[i] = Vertical[i];
				break;
			}
		}
		for (int i = 0; i < input_num;)
		{
			if ((K_v[i] > (log10(Vertical[i]))) && (K_v[i] >= (0.259 / Vertical[i]) + 0.35))
			{
				Vertical[i] = (double)rand() / (RAND_MAX);
				Vvalue_v[i] = ((sqrt(2 / exp(1.0))) * (2 * Vertical[i] - 1));
				Z_v[i] = Vvalue_v[i] / Vertical[i];
				K_v[i] = 0.25 * Z_v[i];
				break;
			}
		}
		if ((sizeof(nomalZ_v)) / (sizeof(double)) == 99)
		{
			printf("\n\n수정된 Horizon\n\n");
			for (int i = 0; i < input_num; i++)
			{
				if (i % 10 == 0)
				{
					printf("\n");
				}
				printf("%.2lf", ReVerti[i]);
				break;
			}
			break;
		}
	}

	while (1)
	{
		for (int i = 0; i < input_num;)
		{
			if (K_h[i] < 1 - Horizon[i])
			{
				nomalZ_h[i] = Z_h[i];
				ReHoriz[i] = Horizon[i];
				break;
			}
		}
		for (int i = 0; i < input_num;)
		{
			if ((K_h[i] > (log10(Horizon[i]))) && (K_v[i] >= (0.259 / Vertical[i]) + 0.35))
			{
				Horizon[i] = (double)rand() / (RAND_MAX * 2);
				Vvalue_h[i] = ((sqrt(2 / exp(1.0))) * (2 * Horizon[i] - 1));
				Z_h[i] = Vvalue_h[i] / Horizon[i];
				K_h[i] = 0.25 * Z_h[i];
				break;;
			}
		}
		if ((sizeof(nomalZ_h)) / (sizeof(double)) == 99)
		{
			printf("\n\n수정된 Horizon\n\n");
			for (int i = 0; i < input_num; i++)
			{
				if (i % 10 == 0)
				{
					printf("\n");
				}
				printf("%.2lf", ReHoriz[i]);
				break;
			}
			break;
		}
		
	}
		print_Vertical(Vertical, input_num);
		print_Horizon(Horizon, input_num);
		PrintZKvalue_Vertical(Z_v,K_v,input_num);
		PrintZKvalue_Horizon(Z_h, K_h, input_num);

		printf("\n\n표준정규분표 확률변수 Z_h\n\n");
		for (int i = 0; i < input_num; i++)
		{
			if (i % 10 == 0)
			{
				printf("\n");
			}
			printf("%.2lf\t", nomalZ_h[i]);
		}
		printf("\n\n표준정규분표 확률변수 Z_v\n\n");
		for (int i = 0; i < input_num; i++)
		{
			if (i % 10 == 0)
			{
				printf("\n");
			}
			printf("%.2lf\t", nomalZ_v[i]);
		}
		X_V(X_v, nomalZ_v, input_num);
		X_H(X_h, nomalZ_h, input_num);
		print_Xv(X_v, input_num);
		print_Xh(X_h, input_num);
		
	
}


void input_rand(double* num1,double* num2, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		num1[i] = (double)rand() / (RAND_MAX ) ;
		num2[i] = (double)rand() / (RAND_MAX ) ;
	}
}

void print_Vertical(double* num, int Size)
{
	printf("\n\n수정 후 수직\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf, ", num[i]);
	}
}

void print_Horizon(double* num, int Size)
{
	printf("\n\n수정 후 수평\n\n");
	for (int j = 0; j < Size; j++)
	{
		if (j % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf, ", num[j]);
	}
}

void Vvalue_Vertical(double* num1, double* num2, int Size)
{
	for (int k = 0; k < Size; k++)
	{

		num1[k] = ((sqrt(2 / exp(1.0))) * (2 * num2[k] - 1));
	}

	printf("\n\nV_v값은 \n\n");
	for (int j = 0; j < Size; j++)
	{
		if (j % 10 == 0)
		{
			printf("\n");
		}
		printf("%lf , ", num1[j]);
	}
}

void Vvalue_Horizon(double* num1, double* num2, int Size)
{
	for (int k = 0; k < Size; k++)
	{

		num1[k] = ((sqrt(2 / exp(1.0))) * (2 * num2[k] - 1));
	}
	printf("\n\n V_h의 값은 \n\n");
	for (int j = 0; j < Size; j++)
	{
		if (j % 10 == 0)
		{
			printf("\n");
		}
		printf("%lf , ", num1[j]);
	}
}

void ZKvalue_Vertical(double* Z, double* K, double* Vv, double* Verti, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Z[i] = Vv[i] / Verti[i];
		K[i] = 0.25 * Z[i];
		//if (K[i] < 1 - Verti[i])
		//{
		//	Z_V[i] = Z[i];
		//}
	}
	
}

void ZKvalue_Horizon(double* Z, double* K, double* Vh, double* Hori, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Z[i] = Vh[i] / Hori[i];
		K[i] = 0.25 * Z[i];
		//if (K[i] < 1 - Hori[i])
		//{
		//	Z_H[i] = Z[i];
		//}
	}
	
}

void PrintZKvalue_Vertical(double* Z, double* K, int Size)
{
	printf("\n\n Z_v값\n\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", Z[i]);

	}
	printf("\n K_v값\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", K[i]);

	}
}

void PrintZKvalue_Horizon(double* Z, double* K, int Size)
{
	printf("\n\n Z_h값\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", Z[i]);

	}
	printf("\n\n K_h값\n\n");
	for (int j = 0; j < Size; j++)
	{
		if (j % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", K[j]);

	}
}

void X_V(double* Xv, double* NZ_v, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Xv[i] = average + NZ_v[i] * 1;
	}
}

void X_H(double* Xh, double* NZ_h, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Xh[i] = average + NZ_h[i] * 1.2;
	}
}

void print_Xv(double* Xv, int Size)
{
	printf("\n\n====X1(Vertical)====\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", Xv[i]);
	}
}

void print_Xh(double* Xh, int Size)
{
	printf("\n\n====X2(Horizon)====\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", Xh[i]);
	}
}



