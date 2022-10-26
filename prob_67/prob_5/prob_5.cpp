#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define input_num 100
#define average 0
#define Standard_Deviation 1


void input_random(double* num1, double* num2, int Size);
void print_Verti(double* num, int Size);
void print_Horiz(double* num, int Size);
void Vvalue_Verti(double* num1, double* num2, int Size);
void Vvalue_Horiz(double* num1, double* num2, int Size);
void print_Vv(double* num, int Size);
void print_Vh(double* num, int Size);
void Zvalue_Verti(double* Z, double* Vv, double* V, int Size);
void Zvalue_Horiz(double* Z, double* Vh, double* H, int Size);
void Kvalue_Verti(double* K, double* Z_v, int Size);
void Kvalue_Horiz(double* K, double* Z_h, int Size);
void printZK_V(double* Z, double* K, int Size);
void printZK_H(double* Z, double* K, int Size);
void Xv(double* Xv, double* SZ_v, int Size);
void Xh(double* Xh, double* SZ_h, int Size);
void print_XV(double* Xv, int Size);
void print_XH(double* Xh, int Size);

int v = 1;
int z = 1;
int count = 0;


int main(void)
{
	double Vertical[input_num] = {};
	double Horizon[input_num] = {};
	double Vvalue_v[input_num] = {};
	double Vvalue_h[input_num] = {};
	double Z_v[input_num] = {};
	double Z_h[input_num] = {};
	double K_v[input_num] = {};
	double K_h[input_num] = {};
	double ReVerti[input_num] = {};
	double ReHoriz[input_num] = {};
	double StandardZv[input_num] = {};
	double StandardZh[input_num] = {};
	double X_v[input_num] = {};
	double X_h[input_num] = {};

		input_random(Vertical, Horizon, input_num);
		print_Verti(Vertical, input_num);
		print_Horiz(Horizon, input_num);
		Vvalue_Verti(Vvalue_v, Vertical, input_num);
		Vvalue_Horiz(Vvalue_h, Horizon, input_num);
		print_Vv(Vvalue_v, input_num);
		print_Vh(Vvalue_h, input_num);
		Zvalue_Verti(Z_v, Vvalue_v, Vertical, input_num);
		Zvalue_Horiz(Z_h, Vvalue_h, Horizon, input_num);
		Kvalue_Verti(K_v, Z_v, input_num);
		Kvalue_Horiz(K_h, Z_h, input_num);
		printZK_V(Z_v, K_v, input_num);
		printZK_H(Z_h, K_h, input_num);
		v = sizeof(ReVerti) / sizeof(double);   //Reverti count where Reverti is the new value
		z = sizeof(ReHoriz) / sizeof(double);   //ReHoriz count where ReHoriz is the new value

		while (1)
		{
			for (int i = 0; i < input_num;i++)
			{
				if (K_v[i] < 1 - Vertical[i])
				{
					ReVerti[i] = Vertical[i];
					StandardZv[i] = Vvalue_v[i] / ReVerti[i];
					continue;
				}
				else if ((K_v[i] >= (0.259 / Vertical[i] + 0.35)) && (K_v[i] > log10(Vertical[i])))
				{
					Vertical[i] = (double)rand() / (RAND_MAX / 1);
					Vvalue_v[i] = ((sqrt(2 / exp(1.0))) * (2 * Vertical[i] - 1));
					Z_v[i] = Vvalue_v[i] / Vertical[i];
					K_v[i] = 0.25 * Z_v[i];
					continue;
				}
				else if (v == 99)
				{
					break;
				}
			}break;
		}
		printf("%d", v);
				
	
	printf("\n\n========== ReVerti ==========\n\n");
	for (int i = 0; i < input_num; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", ReVerti[i]);
	}
	printf("\n\n========== StandardZv ==========\n\n");
	for (int i = 0; i < input_num; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", StandardZv[i]);
	}
	while (1)
	{
		for (int i = 0; i < input_num;i++)
		{
			if (K_h[i] < 1 - Horizon[i])
			{
				ReHoriz[i] = Horizon[i];
				StandardZh[i] = Vvalue_h[i] / ReHoriz[i];
				continue;
			}
			else if ((K_h[i] >= (0.259 / Horizon[i] + 0.35)) && (K_h[i] > log10(Horizon[i])))
			{
				Horizon[i] = (double)rand() / (RAND_MAX / 1);
				Vvalue_h[i] = ((sqrt(2 / exp(1.0))) * (2 * Horizon[i] - 1));
				Z_h[i] = Vvalue_h[i] / Horizon[i];
				K_h[i] = 0.25 * Z_h[i];
				continue;
			}
			else if (z == 99)
			{
				break;
			}
		}break;
	}
	printf("%d", z);

	printf("\n\n========== ReHoriz ==========\n\n");
	for (int i = 0; i < input_num; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", ReHoriz[i]);
	}
	printf("\n\n========== StandardZh ==========\n\n");
	for (int i = 0; i < input_num; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", StandardZh[i]);
	}
	
	Xv(X_v,StandardZv,input_num);
	Xh(X_h,StandardZh,input_num);
	print_XV(X_v, input_num);
	print_XH(X_h, input_num);
	for (int i = 0; i < input_num; i++)
	{
		if ((X_v[i] >= -1 && X_v[i] <= 1)&&(X_h[i] >= -1 && X_h[i] <= 1))
		{
			count++;
		}
	}
	printf("\n\n ========== %dcount of 100 hits ==========\n\n",count);
	printf("\n\n ========== Probability of success : %.2lf ==========\n\n", (double)count / input_num);
	return 0;
	
}

void input_random(double* num1, double* num2, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		num1[i] = (double)rand() / (RAND_MAX / 1);
		num2[i] = (double)rand() / (RAND_MAX / 1);
	}
}

void print_Verti(double* num, int Size)
{
	printf("\n\===========input Vertical==========\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf, ", num[i]);
	}
}

void print_Horiz(double* num, int Size)
{
	printf("\n\n==========input Horizon==========\n\n");
	for (int j = 0; j < Size; j++)
	{
		if (j % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf, ", num[j]);
	}
}

void Vvalue_Verti(double* num1, double* num2, int Size)
{
	for (int k = 0; k < Size; k++)
	{

		num1[k] = ((sqrt(2 / exp(1.0))) * (2 * num2[k] - 1));
	}
}

void Vvalue_Horiz(double* num1, double* num2, int Size)
{
	for (int k = 0; k < Size; k++)
	{

		num1[k] = ((sqrt(2 / exp(1.0))) * (2 * num2[k] - 1));
	}
}

void print_Vv(double* num, int Size)
{
	printf("\n\n========== V_v값은 ========== \n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf, \t", num[i]);
	}
}

void print_Vh(double* num, int Size)
{
	printf("\n\n========== V_h값은 ========== \n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf, \t", num[i]);
	}
}

void Zvalue_Verti(double* Z, double* Vv, double* V, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Z[i] = Vv[i] / V[i];
	}
}

void Zvalue_Horiz(double* Z, double* Vh, double* H, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Z[i] = Vh[i] / H[i];
	}
}

void printZK_V(double* Z, double* K, int Size)
{
	printf("\n\n========== Z_v값 ==========\n\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", Z[i]);

	}
	printf("\n\n========== K_v값 ===========\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", K[i]);

	}
}

void Kvalue_Verti(double* K, double* Z_v, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		K[i] = 0.25 * Z_v[i];
	}
}

void Kvalue_Horiz(double* K, double* Z_h, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		K[i] = 0.25 * Z_h[i];
	}
}

void printZK_H(double* Z, double* K, int Size)
{
	printf("\n\n========== Z_h값 ==========\n\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", Z[i]);

	}
	printf("\n\n========== K_h값 ==========\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf(" %.2lf ,  ", K[i]);

	}
}

void Xv(double* Xv, double* SZ_v, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Xv[i] = average + SZ_v[i] * 1;
	}
}

void Xh(double* Xh, double* SZ_h, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Xh[i] = average + SZ_h[i] * 1.2;
	}
}

void print_XV(double* Xv, int Size)
{
	printf("\n\n========== X1(Vertical) ==========\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", Xv[i]);
	}
}

void print_XH(double* Xh, int Size)
{
	printf("\n\n========== X2(Horizon) ==========\n\n");
	for (int i = 0; i < Size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%.2lf\t", Xh[i]);
	}
}