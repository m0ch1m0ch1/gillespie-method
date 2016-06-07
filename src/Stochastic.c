#include "main.h"

static void func1(double p[Sto_rapi_Num], double Sto_rapi[Sto_rapi_Num], double Sto_conc[Sto_conc_Num],double *Time){

		p[0]	=					Sto_rapi[0]  * Sto_conc[0] ;
		p[1]	= p[0]  + Sto_rapi[1]  * Sto_conc[1] ;
}

static void func2(double z[Sto_rapi_Num], double Sto_conc[Sto_conc_Num]){

	 Sto_conc[0]  =  Sto_conc[0]  - 1.0 * z[0]  + 1.0 * z[1];
	 Sto_conc[1]  =  Sto_conc[1]  + 1.0 * z[0]  - 1.0 * z[1];
}

extern void Stochastic(_parameter *par, double *Time, double *sigma_react, double *exp_rand){

	int    j,fire;
	double z[Sto_rapi_Num], p[Sto_rapi_Num]={0};
	double random;

	//generate random number
	func1(p,par->Sto_rapi,par->Sto_conc,&(*Time));
	*sigma_react = *sigma_react + dt * p[Sto_rapi_Num-1];

	//initilize the change of molecules
	if (*sigma_react >= *exp_rand){

		for(j=0; j < Sto_rapi_Num ; j++)z[j] = 0;
		fire = 0;

		//generate random variable
		random = p[Sto_rapi_Num-1] * genrand_real2();

		//choose fired reaction
		if(random < p[0]){ z[0] = 1 ; fire = 1 ; }
		else{
		  for(j = 1 ; j < Sto_rapi_Num ; j++){
		    if(fire == 1)break;
	    	    if(( p[j-1] <= random) && (random < p[j] )){
		      z[j] = 1 ;
		      fire = 1 ;
		    }
		  }
		}
		*sigma_react = 0.0;
		func2(z, par->Sto_conc);
		*exp_rand = -1*log(genrand_real2());
	}
}
