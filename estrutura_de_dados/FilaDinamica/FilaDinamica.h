struct aluno {
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct descritor Fila;

Fila* cria_fila();

void libera_Fila(Fila* fi);

int tamanho_Fila(Fila* fi);

int fila_cheia(Fila* fi);

int fila_vazia(Fila* fi);

int insere_Fila(Fila* fi, struct aluno al);

int remove_Fila(Fila* fi);

int consulta_Fila(Fila* fi, struct aluno *al);