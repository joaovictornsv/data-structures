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

int insere_pilha(Pilha* pi, struct aluno al) {
  if (pi == NULL || pi->qtd == MAX) {
    return 0;
  }

  pi->dados[pi->qtd] = al;
  pi->qtd++;

  return 1;
}

int remove_pilha(Pilha* pi) {
  if (pi == NULL || pi->qtd == 0) {
    return 0;
  }

  pi->qtd--;
  return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *al) {
  if (pi == NULL || pi->qtd == 0) {
    return 0;
  }

  *al = pi->dados[pi->qtd-1];

  return 1;
}