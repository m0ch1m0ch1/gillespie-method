#include "main.h"

extern void Graph(char fname[150]){

  FILE *gp;
  char wa[100000]     = "";
  char hensa[100000]  = "";
  char buffer[100000] = "";
  int i,rep;

  printf(">>>Report: Start Gnuplot\n");

  gp = popen("gnuplot", "w");
  fprintf(gp, "set term jpeg\n");
  fprintf(gp, "set datafile separator \",\"\n");

  for(i = 0 ; i < Sto_conc_Num ; i++){

    fprintf(gp, "set output \"./Graph/Graph_conc[%d].jpeg\"\n", i);
    fprintf(gp, "plot \"< paste -d ',' ");

    sprintf(wa,"");
    for (rep = 1 ; rep <= Repeat ; rep++){
      fprintf(gp, " ./Data/Data_n=%d.csv ", rep);
      sprintf(buffer, "$%d",(rep -1) * ( Sto_conc_Num + 1 ) + ( i + 2 ) );
      strcat(wa, buffer);
      if ( rep != Repeat ){
        strcat(wa, "+");
      }
    }

    sprintf(hensa,"");
    for (rep = 1 ; rep <= Repeat ; rep++){
      sprintf(buffer, "($%d - ((%s)/%d))**2", (rep -1) * ( Sto_conc_Num + 1 )+ ( i + 2 ), wa, Repeat);
      strcat(hensa, buffer);
      if ( rep != Repeat ){
        strcat(hensa, "+");
      }
    }

    fprintf(gp, "\" using 1:((%s)/%d):(sqrt((%s)/%d)) title \"conc[%d]\" w e pt 6", wa, Repeat, hensa, Repeat, i);
    fprintf(gp,"\n");
  }

  fflush(gp);
  pclose(gp);

  printf(">>>Report: End Gnuplot\n");
}
