#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main (){

Esparsa *matriz=NULL;
int continuarLinha=0,continuarColuna=0;
matriz=scan_infos();
do{
matriz->prim=AlocacaoDaMatriz(matriz, &continuarLinha, &continuarColuna);
}while((continuarLinha!=matriz->linhas)&&(continuarColuna!=matriz->colunas));
menu(matriz);
}
