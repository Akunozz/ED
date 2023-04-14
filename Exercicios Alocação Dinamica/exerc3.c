#include <stdio.h>
#include <stdlib.h>

void inverte(int n, int* vet) {
    int i, temp;
    for (i = 0; i < n/2; i++) {
        temp = vet[i];
        vet[i] = vet[n-i-1];
        vet[n-i-1] = temp;
    }
}

int main() {
    int tamanho, *vetor, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // aloca memória para o vetor
    vetor = (int*) malloc(tamanho * sizeof(int));

    printf("Digite os valores do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    inverte(tamanho, vetor);

    printf("Vetor invertido: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); // libera a memória alocada para o vetor
    return 0;
}
