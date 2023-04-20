#include <stdio.h>
#include <stdlib.h>

struct lista
{
int linha; 
int coluna; 
int info; 
struct lista* prox; 
};
typedef struct lista Lista;


struct esparsa
{
int linhas; 
int colunas; 
struct lista* prim; 
};
typedef struct esparsa Esparsa;



Esparsa* scan_infos ();
Lista* AlocacaoDaMatriz (Esparsa* matriz, int *continuarLinha, int *continuarColuna);
void impressao_da_matriz(Esparsa* matriz);
void consulta_de_elemento(Esparsa* matriz);
void somatorio_linha(Esparsa* matriz);
void percentual_nao_nulos(Esparsa* matriz);
void menu (Esparsa* matriz);
