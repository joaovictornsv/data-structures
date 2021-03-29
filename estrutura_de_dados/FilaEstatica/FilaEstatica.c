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

int tamanho_fila(Fila* fi) {
  if (fi == NULL) {
    return -1;
  }

  return fi->qtd;
}

int fila_cheia(Fila* fi) {
  if (fi == NULL) {
    return -1;
  }

  if (fi->qtd == MAX) {
    return 1;
  }

  return 0;
}

int fila_vazia(Fila* fi) {
  if (fi == NULL) {
    return -1;
  }

  if (fi->qtd == 0) {
    return 1;
  }

  return 0;
}

int insere_fila(Fila* fi, struct aluno al) {
  if (fi == NULL) {
    return 0;
  }

  if (fi->qtd == MAX) {
    return 0;
  }

  fi->dados[fi->final] = al;
  fi->final = (fi->final+1) % MAX;
  fi->qtd++;
  return 1;
}

int remove_fila(Fila* fi) {
  if (fi == NULL || fi->qtd == 0) {
    return 0;
  }

  fi->inicio = (fi->inicio + 1) % MAX;
  fi->qtd--;
  return 1;
}

int consulta_fila(Fila* fi, struct aluno *al){
  if (fi == NULL || fi->qtd == 0) {
    return 0;
  }

  *al = fi->dados[fi->inicio];
  return 1;
}