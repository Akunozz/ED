#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Esparsa* scan_infos ()
{
Esparsa *novo = malloc(sizeof(Esparsa));
int linhas,colunas;
    printf("\nQual o numero de linhas do caca-palavras?\n");
        scanf("%d", &linhas);
        novo->linhas=linhas;
    printf("\nQual o numero de colunas do caca-palavras?\n");
        scanf("%d", &colunas);
        novo->colunas=colunas;
        novo->prim=NULL;
    return novo;
}

Lista* AlocacaoDaMatriz (Esparsa* matriz, int *continuarLinha, int *continuarColuna)
{
    int i,j,valor;

    for(i=*continuarLinha;i<matriz->linhas;i++)
    {
        for(j=*continuarColuna;j<matriz->colunas;j++)
        {
            printf("\nDigite o valor que gostaria de definir para a posicao [%d][%d]: ",i+1,j+1);
            scanf("%d",&valor);
            if(valor!=0) // vai ler e alocar somente se o valor for diferente de zero
            {
                Lista *novo = malloc(sizeof(Lista));
                novo->linha=i;
                novo->coluna=j;
                novo->info=valor;
                novo->prox=matriz->prim;
                *continuarLinha=i;
                *continuarColuna=j+1;
                if(*continuarColuna==matriz->colunas)
                    {
                        *continuarLinha=i+1;
                        *continuarColuna=0;
                        if(*continuarLinha==matriz->linhas)
                        {
                            *continuarLinha=matriz->linhas;
                            *continuarColuna=matriz->colunas;
                        }
                    }
                return novo;
            }
            else
            {
            printf("\nValores iguais a zero nao serao guardados.\n");
            *continuarLinha=i;
            *continuarColuna=j+1;
                if(*continuarColuna==matriz->colunas)
                {
                    *continuarLinha=i+1;
                    *continuarColuna=0;
                    if(*continuarLinha>matriz->linhas-1)
                    {
                        *continuarLinha=matriz->linhas;
                        *continuarColuna=matriz->colunas;
                    }
                }
                return matriz->prim;
            }
        }   
    }
return matriz->prim;
}

void impressao_da_matriz(Esparsa* matriz)
{

Lista* temp;
int i, j, contador;
printf("\n\n");

for(i=0;i<matriz->linhas;i++)
{
    for(j=0;j<matriz->colunas;j++)
    {
        for (temp = matriz->prim; temp!= NULL; temp = temp->prox)
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

void consulta_de_elemento(Esparsa* matriz)
{
Lista* temp;
int i, j, linha, coluna;
printf("\nQual a Linha que o elemento se encontra? (de 1 ateh %d)\n",matriz->linhas);
scanf("%d",&linha);
linha=linha-1; // coloquei um "-1" para reconhecer quando o usuario digita o formato usual (linha 1 at� o tam max).
printf("\nQual a coluna que o elemento se encontra? (de 1 ateh %d)\n",matriz->colunas);
scanf("%d",&coluna);
coluna=coluna-1;// coloquei um "-1" para reconhecer quando o usuario digita o formato usual (coluna 1 at� o tam max).
for(i=0;i<matriz->linhas;i++)
{
    for(j=0;j<matriz->colunas;j++)
    {
        for (temp = matriz->prim; temp!= NULL; temp = temp->prox)
        {
            if(temp->coluna==coluna&&temp->linha==linha)
            {
            printf("O elemento que se localiza na posicao \"[%d][%d]\" eh: %d",linha+1, coluna+1, temp->info);
            return;
            }
        }
    }
}
printf("\nO elemento eh \"NULL\"\n");
}

void somatorio_linha(Esparsa* matriz)
{
Lista* temp;
int i, linha, soma=0;
printf("\nQual a Linha que gostaria de somar os elementos? (de 1 ateh %d)\n",matriz->linhas);
scanf("%d",&linha);
linha=linha-1; // coloquei um "-1" para reconhecer quando o usuario digita o formato usual (linha 1 at� o tam max).
for(i=0;i<matriz->linhas;i++)
{
    if(i==linha)
    {
        for (temp = matriz->prim; temp!= NULL; temp = temp->prox)
        {
            if(temp->linha==linha)
            {
            soma=soma+temp->info;
            }
        }
        if(soma!=0)
        {
        printf("\n\nA soma dos valores da linha %d fica %d\n",linha+1,soma);
        return;
        }
    }
}
printf("\na linha soh contem valores nulos\n");
}


 void percentual_nao_nulos(Esparsa* matriz)
 {
    float porcentagem, quantidadeMaiores;
    Lista* temp;

    for (temp = matriz->prim; temp!= NULL; temp = temp->prox)
        {
            quantidadeMaiores=quantidadeMaiores+1;
        }
    porcentagem=(quantidadeMaiores*100/(matriz->colunas*matriz->linhas));
    printf("\nA porcentagem de numeros nao nulos eh %f%%\n",porcentagem);
 }


void menu (Esparsa* matriz)
{
int escolha;
    while(escolha != 10)
	{
        printf("\n\n Selecione alguma das opcoes a seguir:\n\n  \"1\" para imprimir a matriz\n  \"2\" para consultar um determinado elemento na matriz\n  \"3\" para imprimir o somatorio de uma linha\n");
		printf("  \"4\" para imprimir o percentual de elementos nao nulos da matriz\n  \"10\" para encerrar o programa\n  ");
        scanf("%d",&escolha);
        switch (escolha)
		{
        case 1:
            impressao_da_matriz(matriz);
            break;
        case 2:
            consulta_de_elemento(matriz);
            break;
        case 3:
          somatorio_linha(matriz);
            break;
        case 4:
          percentual_nao_nulos(matriz);
            break;
        case 10:
            free(matriz);
            printf("\n\nPrograma encerrado\n\n");
            exit(0);
        }
    }
}
