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

int tamanho_pilha(Pilha* pi) {
  if (pi == NULL) {
    return -1;
  }

  return pi->qtd;
}

int pilha_cheia(Pilha* pi) {
  if (pi == NULL) {
    return -1;
  }

  if (pi->qtd == MAX) {
    return 1;
  }

  return 0;
}

int pilha_vazia(Pilha* pi) {
  if (pi == NULL) {
    return -1;
  }

  if (pi->qtd == 0) {
    return 1;
  }

  return 0;
}