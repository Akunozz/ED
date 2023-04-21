#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

void menu() {
    printf("\n");
    printf("1 - Mostrar novamente a matriz\n");
    printf("2 - Consultar elemento\n");
    printf("0 - Fechar programa\n");
    printf("\n");
}

void cria_matriz(Diagonal* diag) {
    printf("Informe a ordem da matriz: ");
    scanf("%d", &(diag->ordem));

    diag->v = (int*) malloc(diag->ordem * sizeof(int));
    if (diag->v == NULL) {
        printf("Erro ao alocar memoria!\n");
        system("pause");
        exit(1);
    }
}

void preenche_matriz(Diagonal* diag) {
    int i;

    printf("Informe os valores da diagonal principal:\n");
    for (i = 0; i < diag->ordem; i++) {
        scanf("%d", &(diag->v[i]));
    }
}

void mostra_matriz(Diagonal* diag) {
    int i, j;

    printf("Matriz diagonal:\n\n");
    for (i = 0; i < diag->ordem; i++) {
        for (j = 0; j < diag->ordem; j++) {
            if (i == j) {
                printf("%d ", diag->v[i]);
            } 
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void consulta_elemento(Diagonal* diag) {
    int linha, coluna;

    printf("Informe a linha do elemento a ser consultado:\n");
    scanf("%d", &linha);
    printf("Informe a coluna do elemento a ser consultado:\n");
    scanf("%d", &coluna);

    if (linha < 1 || linha > diag->ordem || coluna < 1 || coluna > diag->ordem) {
        printf("Linha ou coluna invalida!\n");
    } 
    else if (linha == coluna) {
        printf("Elemento: %d\n", diag->v[linha - 1]);
    } 
    else {
        printf("Elemento: 0\n");
    }
}

