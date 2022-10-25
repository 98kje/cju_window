#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "Cramer.h"


int main(void)
{

	while (1)
	{
		printf("calculator program\n");
		printf("input '^' close\n");
		calculator_input();
		calculator();
		char exit;
		scanf_s("%c", &exit, 50);
		if (exit == '^')break;

	}

		printf("----------------------------------------------------------\n\n");
		printf("[Cramer's Rule]\n");
		printf("made KimJaeEun\n");
		printf("Start!!\n\n");
		printf("-------아래의 형식으로 입력해주세요-------\n\n");
		printf("ax + by + cz = X  >> a b c X \n");
		printf("dx + ey + fz = Y  >> d e f Y \n");
		printf("gx + hy + y = Z  >> g h y Z \n\n");
		

		cramer_input();

		cramer_output();

		delta_result();

		delx_result();
		
		dely_result();

		delz_result();
		
		cramer_result();

	
}