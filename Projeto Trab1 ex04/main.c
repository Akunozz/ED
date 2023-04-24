#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main() {
    int x, y, z;
    int ***mat;

    printf("Digite o numero de linhas(i): ");
    scanf("%d", &x);
    printf("Digite o numero de colunas(j): ");
    scanf("%d", &y);
    printf("Digite o numero de profundidade(k): ");
    scanf("%d", &z);

    mat = aloca_matriz(x, y, z);
    preenche_matriz(x, y, z, mat);
    imprime_matriz(x, y, z, mat);

    return 0;
}

