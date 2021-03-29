#define MAX 100

struct aluno {
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct fila Fila;

Fila* cria_Fila();

void libera_Fila(Fila* fi);

int tamanho_fila(Fila* li);

int fila_cheia(Fila* fi);

int fila_vazia(Fila* fi);

int insere_fila(Fila* fi, struct aluno al);

int remove_fila(Fila* fi);

int consulta_Fila(Fila* fi, struct aluno *al);