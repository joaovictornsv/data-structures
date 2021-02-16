#include "ListaDuplaEncad.h"
#include <stdlib.h>

struct elemento {
  struct elemento *ant;
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista() {
  Lista* li = (Lista*) malloc(sizeof(Lista));
  if (li != NULL) {
    *li = NULL;
  }

  return li;
}

void libera_lista(Lista* li) {
  if ((*li) != NULL) {
    Elem* no;

    while ((*li) != NULL) {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    
    free(li);
  }
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

int tamanho_lista(Lista* li) {
  if (li == NULL || (*li) == NULL)
    return 0;

  Elem* no = *li;
  int i = 0;
  while(no != NULL) {
    i++;
    no = no->prox;
  }

  return i;
}

int insercao_lista_inicio(Lista* li, struct aluno al) {
  if (li == NULL) {
    return 0;
  }

  Elem* no = (Elem*) malloc(sizeof(Elem));

  if (no == NULL) {
    return 0;
  }

  no->dados = al;
  no->prox = *li;
  no->ant = NULL;

  if((*li) != NULL) {
    (*li)->ant = no;
  }
  *li = no;

  return 1;
}

int insercao_lista_final(Lista* li, struct aluno al) {
  if (li == NULL) {
    return 0;
  }

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) {
    return 0;
  }

  no->dados = al;
  no->prox = NULL;

  if (*li == NULL) { //lista_vazia
    no->ant = NULL;
    *li = no;
  }
  else {
    Elem *atual = *li;
    while(atual->prox != NULL) {
      atual = atual->prox;
    }

    atual->prox = no;
    no->ant = atual;
  }

  return 1;
}

int insercao_lista_ordenada(Lista* li, struct aluno al){
  if (li == NULL) return 0;

  Elem * no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL) return 0;

  no->dados = al;

  if (*li == NULL) { //lista vazia
    no->ant = NULL;
    no->prox = NULL;
    *li = no;
    return 1;
  }

  Elem *ant, *atual = *li;
  while(atual != NULL && atual->dados.matricula < al.matricula) {
    ant = atual;
    atual = atual->prox;
  }

  if (atual == *li) { //insere no início
    no->ant = NULL;
    no->prox = atual;
    *li = no;
  }

  else {
    no->prox = atual;
    no->ant = ant;

    ant->prox = no;
    if (atual != NULL) {
      atual->ant = no;
    }
  }

  return 1;
}

int remocao_lista_inicio(Lista* li) {
  if (li == NULL || *li == NULL) return 0;

  Elem *aux = *li, *post = (*li)->prox;

  *li = aux->prox;

  if (post != NULL)
    post->ant = NULL;
  
  free(aux);
  return 1;
}

int remocao_lista_final(Lista* li) {
  if (li == NULL || *li == NULL) return 0;

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

int remocao_lista_mat(Lista* li, int mat) {
  if (li == NULL || *li == NULL) return 0;

  Elem *ant, *atual = *li, *post;

  while(atual != NULL || atual->dados.matricula != mat) {
    ant = atual;
    atual = atual->prox;
  }

  if (atual == NULL) // elemento nao encontrado
    return 0;

  post = atual->prox;
  
  if (atual == *li) {
    *li = atual->prox;
  }

  else {
    ant->prox = post;
  }

  if (post != NULL)
    post->ant = atual->ant;

  free(atual);
  return 1;

}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al) {
  if (li == NULL || *li == NULL) return 0;

  Elem* no = *li;
  while(no != NULL && no->dados.matricula != mat) {
    no = no->prox;
  }

  if (no == NULL) return 0; //elemento nao encontrado
  else {
    *al = no->dados;
    return 1;
  }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al) {
  if (li == NULL || *li == NULL || pos <= 0) return 0;

  Elem* no = *li;
  int cont = 1;
  while(no != NULL && cont < pos) {
    cont++;
    no = no->prox;
  }

  if (no == NULL) return 0; //elemento nao encontrado
  
  else {
    *al = no->dados;
    return 1;
  }
}