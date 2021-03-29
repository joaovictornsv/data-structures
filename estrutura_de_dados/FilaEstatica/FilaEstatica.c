#include "FilaEstatica.h"
#include <stdlib.h>

struct fila {
  int qtd, inicio, final;
  struct aluno dados[MAX];
};

Fila* cria_Fila() {
  Fila* fi = (Fila*) malloc(sizeof(Fila));

  if(fi != NULL) {
    fi->inicio = 0;
    fi->final = 0;
    fi->qtd = 0;
  }

  return fi;
}

void libera_Fila(Fila* fi) {
  free(fi);
}