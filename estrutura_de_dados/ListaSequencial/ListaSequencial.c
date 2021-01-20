#include "ListaSequencial.h"
#include <stdlib.h>

struct lista {
  int qtd;
  struct aluno dados[MAX]
};

//Criar lista
Lista* cria_lista() {
  Lista *li;
  li = (Lista*) malloc(sizeof(struct lista));

  if (li != NULL)
    li->qtd = 0;
  
  return li;

};


//Liberar lista
void libera_lista(Lista* li) {
  free(li);
}


//Tamanho da lista
int tamanho_lista(Lista* li) {
  if (li == NULL)
    return -1;
  
  else
    return li->qtd;
}


//Lista Cheia
int lista_cheia(Lista* li) {
  if (li == NULL)
    return -1;

  return (li->qtd == MAX);
}


//Lista Vazia
int lista_vazia(Lista* li) {
  if (li == NULL)
    return -1;
  
  return (li->qtd == 0);
}


//Insercao na lista
int inserir_lista_final(Lista* li, struct aluno x) {
  if (li == NULL || li->qtd == MAX)
    return 0;

  else {
    li->dados[li->qtd] = x;
    li->qtd++;
    return 1;
  }
}

int inserir_lista_inicio(Lista* li, struct aluno x) {
  if (li == NULL || li->qtd == MAX) {
    return 0;
  }

  int i;
  for (i = li->qtd - 1; i >= 0; i--) {
    li->dados[i+1] = li->dados[i];
  }

  li->dados[0] = x;
  li->qtd++;
  return 1;
}

int inserir_lista_ordenada(Lista* li, struct aluno x) {
  if (li == NULL || li->qtd == MAX)
    return 0;

  int i=0, k;

  while(i < li->qtd && li->dados[i].matricula < x.matricula) {
    i++;
  }

  for(k = li->qtd-1; k >= i; k--) {
    li->dados[k+1] = li->dados[k];
  }

  li->dados[i] = x;
  li->qtd++;
  return 1;

}


//Remocao da lista
int remover_lista_final(Lista* li) {
  if (li == NULL || li->qtd == 0) {
    return 0;
  }

  li->qtd--;
  return 1;
};

int remover_lista_inicio(Lista* li) {
  if (li == NULL || li->qtd == 0) {
    return 0;
  }

  int i;

  for(i = 0; i < li->qtd-1; i++) {
    li->dados[i] = li->dados[i+1];
  }

  li->qtd--;
  return 1;
}

int remover_lista_meio(Lista* li, int mat) {
  if (li == NULL || li->qtd == 0) {
    return 0;
  }

  int i=0, k;

  while(i < li->qtd && li->dados[i].matricula != mat)
    i++;

  if (i == li->qtd) //elemento nao encontrado
    return 0;


  for (k = i; k < li->qtd-1; k++){
    li->dados[k] = li->dados[k+1];
  }
  li->qtd--;
  return 1;
}


//Consulta na lista
int consulta_lista_pos(Lista* li, int pos, struct aluno *x) {
  if (li == NULL || li->qtd == 0)
    return 0;

  if (pos > li->qtd || pos <= 0) { //indice fora da lista
    return 0;
  }

  *x = li->dados[pos-1];
  return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *x) {
  if (li == NULL || li->qtd == 0) {
    return 0;
  }

  int i=0;
  while(i < li->qtd && li->dados[i].matricula != mat)
    i++;

  if (i == li->qtd) //elemento nao encontrado
    return 0;
  
  *x = li->dados[i];
  return 1;
}