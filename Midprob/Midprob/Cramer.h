/*
* this.h file's name is "Cramer.h"
* made KimJaeEun
*/


#ifndef __CRAMER_H__
#define __CRAMER_H__

#include <stdio.h>
#include <stdlib.h>

void cramer_input(void);

void cramer_output(void);

void delta_result(void);

void delx_result(void);

void dely_result(void);

void delz_result(void);

void cramer_result(void);



extern double FirstForm[4];
extern double SecondForm[4];
extern double ThirdForm[4];
extern double delta;
extern double delx, dely, delz;
extern double x, y, z;

#endif