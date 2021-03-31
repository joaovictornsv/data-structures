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