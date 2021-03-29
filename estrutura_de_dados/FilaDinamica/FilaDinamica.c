#include "FilaDinamica.h"
#include <stdlib.h>

struct descritor {
  struct elemento *inicio;
  struct elemento *final;
};

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elem;


Fila* cria_Fila() {
  Fila* fi = (Fila*) malloc(sizeof(Fila));

  if (fi != NULL) {
    fi->inicio = NULL;
    fi->final = NULL;
  }

  return fi;
}

void libera_Fila(Fila* fi) {
  if (fi != NULL) {
    
    Elem* no;

    while(fi->inicio != NULL) {
      no = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(no);
    }

    free(fi);
  }
}