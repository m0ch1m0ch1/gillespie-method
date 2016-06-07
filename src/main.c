#include "main.h"

extern int main(void){

	char   fname[150];
	int    rep  = 0;
	double exp_rand;
	_parameter  par;

	//initialize Mersenne-twister
	init_genrand((unsigned int)time(NULL));

	for (rep = 1 ; rep <= Repeat ; rep++){

		double Time        = 0.0;
		double sigma_react = 0.0;
		int    CalcuCount  =   0;

		sprintf(fname,"./Data/Data_n=%d.csv", rep);

		//---Prameter_decision
		Initial_Para_conc(&par);
		Initial_Para_rapi(&par);

		//---Output_Table_Initial_Parameter
		table_Ini(&par, fname);

		//generate random number
		exp_rand = -1 * log(genrand_real2());

		printf("\n>>>Report: Calculation n = %d start\n", rep);

		//main_calculation...
		while(1){

			Time += dt;

			//---Gillspie
			Stochastic(&par,&Time,&sigma_react,&exp_rand);

			CalcuCount++;
			if(CalcuCount >= PlotCount ){
				table(&Time, &par, fname);
				CalcuCount = 0;
			}

			if(Time >= T_End){
				break;
			}
		}
		printf(">>>Report: Calculation n = %d end\n", rep);

	}
	Graph(fname);

	return 0;
}
