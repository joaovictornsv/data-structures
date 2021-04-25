#include "novasFuncoes.h"
#include <stdlib.h>
#include <stdio.h>


void mostrarErro(char *messagem) {
  printf("ERRO: %s\n",messagem);
}

int contaValor(TListaDupEnc* lista, int valor) {
  if (lista == NULL) {
    mostrarErro("Lista inválida.");
    return -1;
  }

  // Lista vazia
  if (*lista == NULL) {
    mostrarErro("Impossível realizar contagem em uma lista vazia");
    return 0;
  }

  else {
    No* no = *lista;

    int qtd = 0;

    while(no != NULL) {
      if (no->dado == valor) {
        qtd++;
      }
      no = no->prox;
    }

    return qtd;
  }
}

int inserirNoInicio(TListaDupEnc* lista, int valor) {
  if (lista == NULL) {
    mostrarErro("Lista inválida.");
    return 0;
  }

  No* no = (No*) malloc(sizeof(No));
  
  if(no == NULL) {
    mostrarErro('Erro ao inserir elemento.');
    return 0;
  }

  no->dado = valor;
  no->prox = *lista;
  no->ant = NULL;

  //Caso a lista não esteja vazia
  if (*lista != NULL) {
    (*lista)->ant = no;
  }
 
  *lista = no;
  return 1;
}

int inserirNoFinal(TListaDupEnc* lista, int valor) {
  if (lista == NULL) {
    mostrarErro("Lista inválida.");
    return 0;
  }

  No* no = (No*) malloc(sizeof(No));
  
  if (no == NULL) {
    mostrarErro('Erro ao inserir elemento.');
    return 0;
  }

  no->dado = valor;
  no->prox = NULL;

  //Caso a lista esteja vazia
  if (*lista == NULL) {
    *lista = no;
    no->ant = NULL;
  }

  else {
    No* aux = *lista;

    while(aux->prox != NULL) {
      aux = aux->prox;
    }

    aux->prox = no;
    no->ant = aux;
  }

  return 1;
}

int removerPrimeiro(TListaDupEnc* lista) {
  if (lista == NULL) {
    mostrarErro("Lista inválida.");
    return 0;
  }

  // Lista vazia
  if (*lista == NULL) {
    mostrarErro("Impossível inserir em lista vazia");
    return 0;
  }

  No* no = *lista;
  *lista = (*lista)->prox;

  // Caso a lista não fique vazia após remoção
  if (*lista != NULL) {
    (*lista)->ant = NULL;
  }

  free(no);
  return 1;
}

int removerUltimo(TListaDupEnc* lista) {
  if (lista == NULL) {
    mostrarErro("Lista inválida.");
    return 0;
  }

  if (*lista == NULL) {
    mostrarErro("Impossível inserir em lista vazia");
    return 0;
  }

  No* no = *lista;

  while(no->prox != NULL) {
    no = no->prox;
  }

  if (no->ant == NULL) {
    *lista = NULL;
  }
  else {
    No* penultimo = no->ant;
    penultimo->prox = no->prox;
  }
  
  free(no);
  return 1;
}

TListaDupEnc* merge(TListaDupEnc* lista1, TListaDupEnc* lista2) {
  if (lista1 == NULL || lista2 == NULL) {
    mostrarErro("Lista(s) Inválida(s).");
    return;
  }

  TListaDupEnc* novaLista = (TListaDupEnc*) malloc(sizeof(TListaDupEnc));

  if(novaLista == NULL) {
    mostrarErro("Ocorreu um erro durante a criação da lista.");
    return;
  }

  //Duas listas vazias => nova lista vazia
  if (*lista1 == NULL && *lista2 == NULL) {
    *novaLista = NULL;
  }

  else {
    No *noLista1 = *lista1, *noLista2 = *lista2;

    while(noLista1 != NULL) {
      inserirNoFinal(novaLista, noLista1->dado);
      inserirNoFinal(novaLista, noLista2->dado);
      noLista1 = noLista1->prox;
      noLista2 = noLista2->prox;
    }
  }

  return novaLista;
}