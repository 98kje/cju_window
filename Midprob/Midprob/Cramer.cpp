#include "Cramer.h"

double FirstForm[4] = {};
double SecondForm[4] = {};
double ThirdForm[4] = {};
double delta;
double delx, dely, delz;
double x, y, z;



void cramer_input(void)
{   
	printf("ax + by + cz = X >> ");
	for (int i = 0; i < 4; i++)
	{
		scanf_s("%lf", &FirstForm[i]);
	}
	printf("dx + ey + fz = Y >> ");
	for (int i = 0; i < 4; i++)
	{
		scanf_s("%lf", &SecondForm[i]);
	}
	printf("gx + hy + yz = Z >> ");
	for (int i = 0; i < 4; i++)
	{
		scanf_s("%lf", &ThirdForm[i]);
	}
	
	
}


void cramer_output(void)
{
	printf("\n\n");
	printf("-------------------- 방정식 출력 --------------------\n\n");
	printf("l %lfx\t%lfy\t%lfz\t= %lf\tl\n", FirstForm[0], FirstForm[1], FirstForm[2], FirstForm[3]);
	printf("l %lfx\t%lfy\t%lfz\t= %lf\tl\n", SecondForm[0], SecondForm[1], SecondForm[2], SecondForm[3]);
	printf("l %lfx\t%lfy\t%lfz\t= %lf\tl\n", ThirdForm[0], ThirdForm[1], ThirdForm[2], ThirdForm[3]);
	printf("\n\n------------------- delta value & delx,y,z -------------\n\n ");

}

void delta_result(void)
{
	delta = ((FirstForm[0] * SecondForm[1] * ThirdForm[2]) + (FirstForm[1] * SecondForm[2] * ThirdForm[0]) + (FirstForm[2] * SecondForm[0] * ThirdForm[1])) - ((FirstForm[1] * SecondForm[0] * ThirdForm[2]) - (FirstForm[0] * SecondForm[2] * ThirdForm[1]) - (FirstForm[2] * SecondForm[1] * ThirdForm[0]));
	printf("delta = %lf\n", delta);
}

void delx_result(void)
{
	delx = ((FirstForm[3] * SecondForm[1] * ThirdForm[2]) + (FirstForm[1] * SecondForm[2] * ThirdForm[3]) + (FirstForm[2] * SecondForm[3] * ThirdForm[1])) - ((FirstForm[1] * SecondForm[3] * ThirdForm[2]) - (FirstForm[3] * SecondForm[2] * ThirdForm[1]) - (FirstForm[2] * SecondForm[1] * ThirdForm[3]));
	printf("delx = %lf\n", delx);
}

void dely_result(void)
{
	dely = ((FirstForm[0] * SecondForm[3] * ThirdForm[2]) + (FirstForm[3] * SecondForm[2] * ThirdForm[0]) + (FirstForm[2] * SecondForm[0] * ThirdForm[3])) - ((FirstForm[3] * SecondForm[0] * ThirdForm[2]) - (FirstForm[0] * SecondForm[2] * ThirdForm[3]) - (FirstForm[2] * SecondForm[3] * ThirdForm[0]));
	printf("dely = %lf\n", dely);
}

void delz_result(void)
{
	delz = ((FirstForm[0] * SecondForm[1] * ThirdForm[3]) + (FirstForm[1] * SecondForm[3] * ThirdForm[0]) + (FirstForm[3] * SecondForm[0] * ThirdForm[1])) - ((FirstForm[1] * SecondForm[0] * ThirdForm[3]) - (FirstForm[0] * SecondForm[3] * ThirdForm[1]) - (FirstForm[3] * SecondForm[1] * ThirdForm[0]));
	printf("dlez = %lf\n", delz);
}

void cramer_result(void)
{
	x = (delx / delta);
	y = (dely / delta);
	z = (delz / delta);

	printf("\n\n");
	printf("=================Solution for each Coordinate ===================");
	printf("\n\n x = %.2lf\t y = %.2lf\t z = %.2lf\t\n", x, y, z);
}
