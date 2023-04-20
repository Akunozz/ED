#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Identidade* scan_infos () 
{
Identidade *novo = malloc(sizeof(Identidade));
int ordem;
    printf("\nQual a ordem da matriz?\n");
        scanf("%d", &ordem);
        novo->ordem=ordem;
        novo->diagonal=NULL;
        novo->foraDiagonal=NULL;

    return novo;
}

Lista* AlocacaoDaMatriz (Identidade* matriz, int *continuarLinha, int *continuarColuna)
{
    int i,j,valor;

    for(i=*continuarLinha;i<matriz->ordem;i++)
    {
        for(j=*continuarColuna;j<matriz->ordem;j++)
        {
            printf("\nDigite o valor que gostaria de definir para a posicao [%d][%d]: ",i+1,j+1);
            scanf("%d",&valor);
            if(valor!=0) // vai ler e alocar somente se o valor for diferente de zero
            {
                Lista *novo = malloc(sizeof(Lista));
                novo->linha=i;
                novo->coluna=j;
                novo->info=valor;
                if(novo->linha!=novo->coluna)
                novo->prox=matriz->foraDiagonal;
                else
                novo->prox=matriz->diagonal;
                *continuarLinha=i;
                *continuarColuna=j+1;
                if(*continuarColuna==matriz->ordem)
                    {
                        *continuarLinha=i+1;
                        *continuarColuna=0;
                        if(*continuarLinha==matriz->ordem)
                        {
                            *continuarLinha=matriz->ordem;
                            *continuarColuna=matriz->ordem;
                        }
                    }
                return novo;
            }
            else
            {
            printf("\nValores iguais a zero nao serao guardados.\n");
            *continuarLinha=i;
            *continuarColuna=j+1;
                if(*continuarColuna==matriz->ordem)
                {
                    *continuarLinha=i+1;
                    *continuarColuna=0;
                    if(*continuarLinha>matriz->ordem-1)
                    {
                        *continuarLinha=matriz->ordem;
                        *continuarColuna=matriz->ordem;
                    }
                }
            return NULL;
            }
        }   
    }
return NULL;
}

void impressao_da_matriz(Identidade* matriz)
{

Lista* temp;
int i, j, contador;
printf("\n\n");

for(i=0;i<matriz->ordem;i++)
{
    for(j=0;j<matriz->ordem;j++)
    {
        for (temp = matriz->diagonal; temp!= NULL; temp = temp->prox)
        {
            if(temp->coluna==j&&temp->linha==i)
            {
            printf("%4d", temp->info);
            contador=1;
            }
        }
        for (temp = matriz->foraDiagonal; temp!= NULL; temp = temp->prox)
        {
            if(temp->coluna==j&&temp->linha==i)
            {
            printf("%4d", temp->info);
            contador=1;
            }
        }
        if(contador!=1)
        {
        printf("   0");
        }
        contador=0;
    }
    printf("\n");
}
}

void mostra_nao_diagonais(Identidade* matriz)
{

Lista* temp;
int i, j, contador=0, contador2=0, contador3=0; // contadores sao para quando se enquadrar em algum dos elementos anteriores, nao entrar no if. 
printf("\n\n");

for(i=0;i<matriz->ordem;i++)
{
    for(j=0;j<matriz->ordem;j++)
    {
        for (temp = matriz->diagonal; temp!= NULL; temp = temp->prox)
        {
            if((temp->coluna==j&&temp->linha==i)&&(temp->info!=1))
            {
            printf("\n O elemento \"%d\" de posicao: [%d][%d] (diagonal) viola a propriedade da matriz identidade, pois eh diferente de \"1\"\n", temp->info,temp->linha+1, temp->coluna+1);
            contador=1;
            contador2=1;
            }
            else if((temp->coluna==j&&temp->linha==i)&&(temp->info==1))
            contador3=1;
        }
        if(i==j&&contador2==0&&contador3==0)
        {
            printf("\n O elemento \"0\" de posicao: [%d][%d] (diagonal) viola a propriedade da matriz identidade, pois eh diferente de \"1\"\n", i+1, j+1);
            contador=1;
            contador2=0;
        }
        contador3=0;
        for (temp = matriz->foraDiagonal; temp!= NULL; temp = temp->prox)
        {
            if((temp->coluna==j&&temp->linha==i))
            {
            printf("\n O elemento \"%d\" de posicao: [%d][%d] viola a propriedade da matriz identidade\n", temp->info,temp->linha+1, temp->coluna+1);
            contador=1;
            }
        }
        contador2=0;

    }
}
if(contador==0)
printf("\nNenhum elemento viola a propriedade da matriz identidade.\n");
}


void menu (Identidade* matriz)
{
int escolha;
    while(escolha != 10)
	{
        printf("\n\n Selecione alguma das opcoes a seguir:\n\n  \"1\" para imprimir a matriz\n  \"2\" Para mostrar os elementos que violam a propriedade da matriz identidade\n  \"10\" para encerrar o programa\n  ");
        scanf("%d",&escolha);
        switch (escolha)
		{
        case 1:
            impressao_da_matriz(matriz);
            break;
        case 2:
            mostra_nao_diagonais(matriz);
            break;
        case 10:
            free(matriz);
            printf("\n\nPrograma encerrado\n\n");
            exit(0);
        }
    }
}
