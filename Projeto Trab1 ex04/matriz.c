#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int*** aloca_matriz(int x, int y, int z) {
    int i, j;
    int ***mat = (int***) malloc(x * sizeof(int**));

    for (i = 0; i < x; i++) {
        mat[i] = (int**) malloc(y * sizeof(int*));

        for (j = 0; j < y; j++) {
            mat[i][j] = (int*) malloc(z * sizeof(int));
        }
    }

    return mat;
}

void preenche_matriz(int x, int y, int z, int ***mat) {
    int i, j, k;

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("Digite o elemento [%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void imprime_matriz(int x, int y, int z, int ***mat) {
    int i, j, k;

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            for (k = 0; k < z; k++) {
                printf("%d ", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

