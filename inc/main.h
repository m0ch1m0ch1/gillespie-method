#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Mersenne-twister Coded by Takuji Nishimura and Makoto Matsumoto.
#include "mt19937ar.h"

//Number of Stochasric Variable
#define  Sto_conc_Num      2
//Number of Stochastic Reaction
#define  Sto_rapi_Num      2

//END time
#define  T_End        1.0E+06

//Repeat
#define  Repeat            10

#define  dt           1.0E-03
#define  PlotCount    1.0E+07

typedef struct {
		double Sto_conc[Sto_conc_Num];
		double Sto_rapi[Sto_rapi_Num];
}_parameter;

extern void Initial_Para_conc(_parameter *par);
extern void Initial_Para_rapi(_parameter *par);
extern void table_Ini(_parameter *par, char fname[150]);
extern void table(double *Time, _parameter *par, char fname[150]);
extern void Stochastic(_parameter *par, double *Time, double *sigma_react,double *exp_rand);
extern void Graph(char fname[150]);
