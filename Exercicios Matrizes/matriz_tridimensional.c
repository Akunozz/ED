#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 3, n = 3, p = 3; // dimensões da matriz tridimensional
    int ***matriz; // ponteiro para a matriz tridimensional
    int i, j, k; // variáveis de iteração

    // alocação dinâmica da matriz tridimensional
    matriz = (int***) malloc(m * sizeof(int**));
    for (i = 0; i < m; i++) {
        matriz[i] = (int**) malloc(n * sizeof(int*));
        for (j = 0; j < n; j++) {
            matriz[i][j] = (int*) malloc(p * sizeof(int));
        }
    }

    // preenchimento da matriz tridimensional com valores arbitrários
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < p; k++) {
                matriz[i][j][k] = i + j + k;
            }
        }
    }

    // impressão da matriz tridimensional
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < p; k++) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // liberação da memória alocada para a matriz tridimensional
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
