#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main() {
    int m, n, z;
    int ***mat;

    printf("Digite o número de linhas: ");
    scanf("%d", &m);
    printf("Digite o número de colunas: ");
    scanf("%d", &n);
    printf("Digite o número de profundidade: ");
    scanf("%d", &z);

    mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);

    return 0;
}

