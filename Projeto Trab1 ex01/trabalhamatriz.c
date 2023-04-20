#include "trabalhamatriz.h"

void preenchematriz(Diagonal* diag) {
	int i = 0, j = 0;

	diag->v = (int*)malloc(diag->ordem * sizeof(int));

	if (diag->v == NULL) {
		printf("\nErro na alocacao de memoria\n");
		system("pause");
		exit(1);
	}

	for (i = 0; i < diag->ordem; i++) {
		for (j = 0; j < diag->ordem; j++) {
			if (i == j) {
				printf("\nDigite o numero que sera atribuido: ");
				scanf("%d", &diag->v[i]);
				if (diag->v[i] == 0) {
					printf("Digite um numero nao nulo (!=0)");
					exit (0);
				}
			}
		}
	}
}

void mostramatriz(Diagonal* diag) {
	int i = 0, j = 0;
	for (i = 0; i < diag->ordem; i++) {
		for (j = 0; j < diag->ordem; j++) {
			if (i == j) {
				printf("%d ", diag->v[i]);
			}
			else {
				printf("0 ");
			}
			if (j == diag->ordem - 1) {
				printf("\n");
			}
		}
	}
}

void procuraelemento(Diagonal* diag) {
	int i = 0, j = 0;

	printf("Digite a linha do elemento que deseja procurar na matriz: ");
	scanf("%d", &j);

	printf("Digite a coluna: ");
	scanf("%d", &i);

	if (i != j) {
		printf("Numero nulo.");
	}
	if (i == j) {
			printf("Numero encontrado.");
		}
	}

void liberamemoria(Diagonal* diag) {
	free(diag);
}
