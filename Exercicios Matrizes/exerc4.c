#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;
    int **matriz;

    // Leitura do número de linhas e colunas
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    // Alocação dinâmica da matriz
    matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1; // Encerra o programa com status de erro
    }

    // Alocação dinâmica das colunas da matriz
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Falha na alocação de memória.\n");
            return 1; // Encerra o programa com status de erro
        }
    }

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Impressão dos elementos da matriz
    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória alocada
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
