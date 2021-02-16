#include "ListaCircular.h"
#include <stdlib.h>

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista() {
  Lista* li = (Lista*) malloc(sizeof(Lista));
  if (li != NULL) {
    *li == NULL;
  }

  return li;
}

void libera_lista(Lista* li) {
  if ((*li) != NULL) {
    Elem* no;

    while (no != NULL) {
      no = *li;
      *li == (*li)->prox;
      free(no);
    }

    free(li);
  }
}

int tamanho_lista(Lista* li) {
  if (li == NULL || (*li) == NULL) {
    return 0;
  }

  Elem* no = *li;
  int cont = 0;
  while(no != NULL) {
    no = no->prox;
    cont++;
  }

  return cont;
}

int lista_cheia(Lista* li) {
  return 0;
}

int lista_vazia(Lista* li) {
  if (li == NULL || (*li) == NULL)
    return 1;

  else
    return 0;
}
