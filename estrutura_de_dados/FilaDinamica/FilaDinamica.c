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

int tamanho_Fila(Fila* fi) {
  if (fi == NULL) {
    return 0;
  }
  
  Elem* no = fi->inicio;
  int qtd = 0;

  while(no != NULL) {
    qtd++;
    no = no->prox;
  }

  return qtd;
}

int fila_cheia(Fila* fi) {
  return 0;
}

int fila_vazia(Fila* fi) {
  if (fi == NULL || fi->inicio == NULL) {
    return 1;
  }

  return 0;
}

int insere_Fila(Fila* fi, struct aluno al) {
  if (fi == NULL) {
    return 0;
  }

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) {
    return 0;
  }

  no->dados = al;
  no->prox = NULL;

  if (fi->final == NULL) { //fila vazia
    fi->inicio = no;
  }

  else {
    fi->final->prox = no;
  }

  fi->final = no;
  return 1;
}

int remove_Fila(Fila* fi) {
  if (fi == NULL || fi->inicio == NULL) {
    return 0;
  }

  Elem* no = fi->inicio;
  fi->inicio = fi->inicio->prox;

  if(fi->inicio == NULL) { //fila ficou vazia
    fi->final = NULL;
  }

  free(no);

  return 1;
}

int consulta_Fila(Fila* fi, struct aluno *al) {
  if (fi == NULL || fi->inicio == NULL) {
    return 0;
  }

  *al = fi->inicio->dados;
  return 1;
}