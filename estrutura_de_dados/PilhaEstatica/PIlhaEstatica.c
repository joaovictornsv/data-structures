#include "PilhaEstatica.h"
#include <stdlib.h>

struct pilha {
  int qtd;
  struct aluno dados[MAX];
};

Pilha* cria_Pilha() {
  Pilha* pi = (Pilha*) malloc(sizeof(Pilha));

  if (pi != NULL) {
    pi->qtd = 0;
  }

  return pi;
}

void libera_pilha(Pilha* pi) {
  free(pi);
}