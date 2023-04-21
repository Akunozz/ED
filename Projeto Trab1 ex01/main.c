#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

int main() {
    Diagonal diag;
    int opcao;
    cria_matriz(&diag);
    preenche_matriz(&diag);
    mostra_matriz(&diag);

    do {
        menu();
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostra_matriz(&diag);
                break;
            case 2:
                consulta_elemento(&diag);
                break;
            case 0:
                printf("Programa encerrado\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } 
    while (opcao != 0);
    free(diag.v); //libera matriz
    return 0;
}


