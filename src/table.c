#include "main.h"

extern void table_Ini(_parameter *par, char fname[150]){

	int i;
	char buffer[256];
	FILE *output;

	output = fopen(fname, "w");

	fprintf(output, "%12s", "Time");
	for(i = 0 ; i < Sto_conc_Num ; i++){
		sprintf(buffer, "conc[%d]",i);
		fprintf(output, ",%12s",buffer);
	}
	fprintf(output, "\n");

	fprintf(output,"%E",0.0);
	for(i = 0 ; i < Sto_conc_Num ; i++){
		fprintf(output,",%E"  , par->Sto_conc[i]);
	}
	fprintf(output,"\n");

 	fclose(output);
}

extern void table(double *Time, _parameter *par, char fname[150]){

  FILE   *output;
  int i;

  output = fopen(fname, "a");

  fprintf(output,"%E",*Time);

  for(i = 0 ; i < Sto_conc_Num ; i++){
		fprintf(output,",%E", par->Sto_conc[i]);
	}
  fprintf(output, "\n");

  fclose(output);
}
