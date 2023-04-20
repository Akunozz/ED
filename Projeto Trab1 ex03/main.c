#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main (){

Identidade *matriz=NULL;
Lista *temporaria=NULL;

int continuarLinha=0,continuarColuna=0;
matriz=scan_infos();
do{
temporaria=AlocacaoDaMatriz(matriz, &continuarLinha, &continuarColuna);
if((temporaria!=NULL)&&(temporaria->coluna!=temporaria->linha))
matriz->foraDiagonal=temporaria;
else if((temporaria!=NULL)&&(temporaria->coluna==temporaria->linha))
matriz->diagonal=temporaria;
}while((continuarLinha!=matriz->ordem)&&(continuarColuna!=matriz->ordem));
menu(matriz);
    return 0;
}
