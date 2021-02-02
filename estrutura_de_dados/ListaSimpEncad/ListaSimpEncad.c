#include "ListaSimpEncad.h"
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
  if(li != NULL) {
    Elem* no;
    while((*li )!= NULL) {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }

    free(li);
  }
}

int tamanho_lista(Lista* li) {
  if (li == NULL) {
    return 0;
  }

  int i=0;
  Elem* no = *li;

  while(no != NULL) {
    i++;
    no = no->prox;
  }

  return i;
}

int lista_cheia(Lista* li) {
  return 0;
}

int lista_vazia(Lista* li) {
  if (li == NULL || *li == NULL)
    return 1;

  else
    return 0;
}

int insercao_lista_inicio(Lista* li, struct aluno al) {
  if (li == NULL) {
    return 0;
  }

  Elem* no = (Elem*) malloc(sizeof(Elem));
  
  if(no == NULL) 
    return 0;

  no->dados = al;
  no->prox = *li;
  *li = no;
  
  return 1;
}

int insercao_lista_final(Lista* li, struct aluno al) {
  if (li == NULL) {
    return 0;
  }

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;

  no->dados = al;
  no->prox = NULL;

  if ((*li) == NULL) {
    *li = no;
  }
  else {
    Elem *el = *li;
    while(el->prox != NULL)
      el = el->prox;

    el->prox = no;
  }
  
  return 1;
}

int insercao_lista_ordenada(Lista* li, struct aluno al) {
  if (li == NULL) {
    return 0;
  }

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) {
    return 0;
  }

  no->dados = al;

  if ((*li) == NULL) { //Insere na lista vazia
    no->prox = (*li);
    *li = no;
    return 1;
  }
  else { //Busca um local para ser inserido
    Elem *ant, *atual = *li;
    while(atual != NULL && atual->dados.matricula < al.matricula) {
      ant = atual;
      atual = atual->prox;
    }

    if (atual == *li) { //Insere no início
      no->prox = *li;
      *li = no;
    }
    else {
      ant->prox = no;
      no->prox = atual;
    }

    return 1;
  }
}

int remocao_lista_inicio(Lista *li) {
  if (li == NULL || *li == NULL)
    return 0;
  
  Elem *no = *li;
  *li = no->prox;
  free(no);
  return 1;
}

int remocao_lista_final(Lista* li) {
  if (li == NULL || *li == NULL)
    return 0;

  Elem *ant, *atual = *li;

  while(atual->prox != NULL) {
    ant = atual;
    atual = atual->prox;
  }
  if (atual == (*li)) //remover primeiro elemento
    *li = atual->prox;

  else 
    ant->prox = atual->prox;
  
  free(atual);
  return 1;
}

int remocao_lista_meio(Lista* li, int mat) {
  if (li == NULL || *li == NULL)
    return 0;

  Elem *ant, *atual = *li;
  while(atual != NULL && atual->dados.matricula != mat) {
    ant = atual;
    atual= atual->prox;
  }

  if (atual == NULL) //elemento nao encontrado
    return 0;

  if(atual == *li)
    *li = atual->prox;

  else
    ant->prox = atual->prox;
  free(atual);
  return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al) {
  if (li == NULL || *li == NULL || pos <= 0)
    return 0;


  int cont = 1;
  Elem* no = *li;
  while(no != NULL && cont < pos)
    cont++;
    no = no->prox;

  if(no == NULL) //elemento nao encontrado
    return 0;
  else {
    *al = no->dados;
    return 1;
  } 
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al) {
  if (li == NULL || *li == NULL)
    return 0;

  Elem* no = *li;
  while (no != NULL && no->dados.matricula != mat)
    no = no->prox;

  if (no == NULL) //elemento nao encontrado
    return 0;

  else {
    *al = no->dados;
    return 1;
  }
}