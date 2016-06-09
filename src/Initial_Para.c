#include "main.h"

extern void Initial_Para_conc(_parameter *par){
  //--stochastic__(Count)
  par->Sto_conc[0]  = 100;
  par->Sto_conc[1]  =   0;
}

extern void Initial_Para_rapi(_parameter *par){

  par->Sto_rapi[0]  = 1.0;
  par->Sto_rapi[1]  = 1.0;
}
