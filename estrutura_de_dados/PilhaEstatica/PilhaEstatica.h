#define MAX 100

struct aluno {
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct pilha Pilha;

Pilha* cria_Pilha();

void libera_Pilha();

int tamanho_pilha(Pilha* pi);

int pilha_cheia(Pilha* pi);

int pilha_vazia(Pilha* pi);