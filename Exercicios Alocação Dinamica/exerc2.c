#include <stdio.h>
#include <stdlib.h>

int negativos(int n, int* vet) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (vet[i] < 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int tamanho, *vetor, i, num_negativos;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // aloca memória para o vetor
    vetor = (int*) malloc(tamanho * sizeof(int));

    printf("Digite os valores do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    num_negativos = negativos(tamanho, vetor);
    printf("Quantidade de numeros negativos: %d\n", num_negativos);

    free(vetor); // libera a memória alocada para o vetor
    return 0;
}
