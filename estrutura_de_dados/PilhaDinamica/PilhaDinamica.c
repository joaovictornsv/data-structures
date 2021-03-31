#include "PilhaDinamica.h"
#include <stdlib.h>

struct elemento {
  struct aluno dados;
  struct elemento* prox;
};

typedef struct elemento Elem;

Pilha* cria_Pilha() {
  Pilha* pi = (Pilha*) malloc(sizeof(Pilha));

  if (pi != NULL) {
    *(pi) = NULL;
  }

  return pi;
}

void libera_Pilha(Pilha* pi) {
  if (pi != NULL) {
    Elem* no;
    while((*pi) != NULL) {
      no = *pi;
      *pi = (*pi)->prox;
      free(no);
    }

    free(pi);
  }
}

int tamanho_pilha(Pilha* pi) {
  if (pi == NULL) {
    return 0;
  }

  Elem* no = *pi;
  int qtd = 0;

  while(no != NULL) {
    qtd++;
    no = no->prox;
  }

  return qtd;
}

int pilha_cheia(Pilha* pi) {
  return 0;
}

int pilha_vazia(Pilha* pi) {
  if (pi == NULL || *pi == NULL) {
    return 1;
  }

  return 0;
}