#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int*** aloca_matriz(int m, int n, int z) {
    int i, j;
    int ***mat = (int***) malloc(m * sizeof(int**));

    for (i = 0; i < m; i++) {
        mat[i] = (int**) malloc(n * sizeof(int*));

        for (j = 0; j < n; j++) {
            mat[i][j] = (int*) malloc(z * sizeof(int));
        }
    }

    return mat;
}

void preenche_matriz(int m, int n, int z, int ***mat) {
    int i, j, k;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < z; k++) {
                printf("Digite o elemento [%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void imprime_matriz(int m, int n, int z, int ***mat) {
    int i, j, k;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < z; k++) {
                printf("%d ", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

