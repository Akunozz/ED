struct lista
{
int linha; 
int coluna; 
int info; 
struct lista* prox; 
};
typedef struct lista Lista;


struct identidade
{
int ordem; 
struct lista* diagonal; 
struct lista* foraDiagonal;
};
typedef struct identidade Identidade;


Identidade* scan_infos ();
Lista* AlocacaoDaMatriz (Identidade* matriz, int *continuarLinha, int *continuarColuna);
void impressao_da_matriz(Identidade* matriz);
void mostra_nao_diagonais(Identidade* matriz);
void menu (Identidade* matriz);
