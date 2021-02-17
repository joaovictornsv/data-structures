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
  if (li != NULL && (*li) != NULL) {
    Elem *aux, *no = *li;

    while (*(li) != no->prox) {
      aux = no;
      no = no->prox;
      free(aux);
    }

    free(no);
    free(li);
  }
}

int tamanho_lista(Lista* li) {
  if (li == NULL || (*li) == NULL) {
    return 0;
  }

  Elem* no = *li;
  int cont = 0;
  while(no != (*li)) {
    no = no->prox;
    cont++;
  }

  return cont;
}

int lista_cheia(Lista* li) {
  return 0;
}

int lista_vazia(Lista* li) {
  if (li == NULL && (*li) == NULL)
    return 1;

  else
    return 0;
}

int insercao_lista_inicio(Lista* li, struct aluno al) {
  if (li == NULL)
    return 0;

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;

  no->dados = al;
  if ((*li) == NULL) { //Lista vazia: insere inicio
    *li = no;
    no->prox = no;
  }
    
  else {
    Elem* aux = *li;
    while (aux->prox != (*li))
      aux = aux->prox;

    aux->prox = no;
    no->prox = *li;
    *li = no;
  }

  return 1;
}

int insercao_lista_final(Lista* li, struct aluno al) {
  if (li == NULL)
    return 0;

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;

  no->dados = al;
  if ((*li) == NULL) { //Lista vaza
    *li = no;
    no->prox = no;
  }

  else {
    Elem* aux = *li;
    while(aux->prox != *li)
      aux = aux->prox;

    aux->prox = no;
    no->prox = *li;
  }

  return 1;
}

int insercao_lista_ordenada(Lista* li, struct aluno al) {
  if (li == NULL)
    return 0;

  Elem* no = (Elem*) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;

  no->dados = al;
  if ((*li) == NULL) { //Lista Vazia
    *li = no;
    no->prox = no;
    return 1;
  }

  else {
    if ((*li)->dados.matricula > al.matricula) { //insere início
      Elem* aux = *li;
      while (aux->prox != *li) //procura o úlitmo
        aux = aux->prox;
      
      no->prox = *li;
      aux->prox = no;
      *li = no;
      return 1;
    }

    Elem *ant = *li, *atual = (*li)->prox;
    while(atual != (*li) && atual->dados.matricula < al.matricula){
      ant = atual;
      atual = atual->prox;
    }

    no->prox = atual;
    ant->prox = no;

    return 1;
  }
}

int remocao_lista_inicio(Lista * li) {
  if (li == NULL || (*li) == NULL) return 0;

  if ((*li)->prox == (*li)) { // lista com 1 elemento
    free(*li);
    *li = NULL;
    return 1;
  }
  else {
    Elem* aux = *li;
    while(aux->prox != (*li))
      aux = aux->prox;

    Elem* no = *li;
    aux->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
  }
}

int remocao_lista_final(Lista* li) {
  if (li == NULL || (*li) == NULL) return 0;

  if ((*li)->prox == (*li)) { // lista com 1 elemento
    free(*li);
    *li = NULL;
    return 1;
  }

  else {
    Elem* ant = *li, *atual = (*li)->prox;

    while(atual->prox != (*li)) { //procura o último
      ant = atual;
      atual = atual->prox;  
    }

    ant->prox = atual->prox;
    free(atual);
    return 1;
  }
}

int remocao_lista_meio(Lista* li, int mat) {
  if (li == NULL || (*li) == NULL) return 0;

  Elem* no = *li;
  if(no->dados.matricula == mat) { //remove inicio
    if (no->prox == no){ // lista com 1 elemento
      free(no);
      *li = NULL;
      return 1;
    }

    else {
      Elem *aux = *li;
      while(aux->prox != no) //procura o ultimo
        aux = aux->prox;

      aux->prox = (*li)->prox;
      *li = (*li)->prox;
      free(no);
      return 1;
    }
    
  }
  else {
    Elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados.matricula != mat) {
      ant = no;
      no = no->prox;
    }

    if(no == (*li)) //elemento nao encontrado
      return 0;

    ant->prox = no->prox;
    free(no);
    return 1;
  }
}