#include "trabalhamatriz.h"

int main() {
	
	int ordem = 0;

	printf("Digite a ordem da matriz: ");
	scanf("%d", &ordem);

	Diagonal* diag;

	diag = (Diagonal*)malloc(ordem * sizeof(Diagonal));

	diag->ordem = ordem;

	preenchematriz(diag);
	mostramatriz(diag);
	procuraelemento(diag);
	liberamemoria(diag);
}
