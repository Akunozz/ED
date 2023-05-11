#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    int *vetor;

    // Leitura do tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Alocação dinâmica do vetor
    vetor = (int *)malloc(tamanho * sizeof(int));

    // Verificação se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1; // Encerra o programa com status de erro
    }

    // Leitura dos elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    // Impressão dos elementos do vetor
    printf("Vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberação da memória alocada
    free(vetor);

    return 0;
}
