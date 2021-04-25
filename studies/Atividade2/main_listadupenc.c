/*****************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba			 
 * Campus Campina Grande													 
 * Curso Superior em Engenharia da Computação								 
 * Professor: Cesar Vasconcelos												 
 * 																			 
 * Copyright - Cesar Vasconcelos											 
 * Este marerial foi elaborado apenas para ser utilizado pelos alunos da 	 
 * disciplina Estruturas de Dados, do curso de Eng. da Computação do IFPB.	 
 * 																			 
 * Nenhuma parte deste material pode ser reproduzida ou transmitida			 
 * de qualquer modo ou por qualquer meio sem prévia autorização do 			 
 * autor e sem lhe ser dado o devido crédito.								 
 * **************************************************************************/

#include "listadupenc.h"
#include <stdio.h>

int main (void) {

  printf("---\n");
	TListaDupEnc lista1;
	TListaDupEnc lista2;

  //Criação da lista 1 e lista 2
  criarLista( &lista1 );
  criarLista( &lista2 );


  printf("Lista1:\n");
  if( listaVazia( lista1 ) ) printf( "Esta vazia!" );

  printf("\nLista2:\n");
  if( listaVazia( lista1 ) ) printf( "Esta vazia!" );

  //Inserção de elementos na lista 1
  printf("\n\n==== Inserção de elementos na Lista 1 ====\n");

  printf("Adicionado elemento 2 no INÍCIO da Lista 1!\n");
  inserirNoInicio(&lista1, 2); // Lista ( 2 )

  printf("Adicionado elemento 5 no INÍCIO da Lista 1!\n");
  inserirNoInicio(&lista1, 5); // Lista ( 5, 2 )

  printf("Adicionado elemento 2 no FINAL da Lista 1!\n");
  inserirNoFinal(&lista1, 2); // Lista ( 5, 2, 2 )

  printf("Adicionado elemento 4 no FINAL da Lista 1!\n");
  inserirNoFinal(&lista1, 4); // Lista ( 5, 2, 2, 4 )
  
  printf("\nLista 1:");
  imprimir(lista1);

  //Inserção de elementos na lista 1
  printf("\n\n\n==== Inserção de elementos na Lista 2 ====\n");

  printf("Adicionado elemento 1 no INÍCIO da Lista 2!\n");
  inserirNoInicio(&lista2, 1); // Lista ( 1 )

  printf("Adicionado elemento 7 no INÍCIO da Lista 2!\n");
  inserirNoInicio(&lista2, 7); // Lista ( 7, 1 )

  printf("Adicionado elemento 3 no FINAL da Lista 2!\n");
  inserirNoFinal(&lista2, 3); // Lista ( 7, 1, 3 )

  printf("Adicionado elemento 9 no FINAL da Lista 2!\n");
  inserirNoFinal(&lista2, 9); // Lista ( 7, 1, 3, 9 )

  printf("Adicionado elemento 6 no FINAL da Lista 9!\n");
  inserirNoFinal(&lista2, 9); // Lista ( 7, 1, 3, 9, 9 )

  printf("Adicionado elemento 4 no INÍCIO da Lista 2!\n");
  inserirNoInicio(&lista2, 4); // Lista ( 4, 7, 1, 3, 9, 9 )

  printf("Adicionado elemento 2 no FINAL da Lista 2!\n");
  inserirNoFinal(&lista2, 2); // Lista ( 4, 7, 1, 3, 9, 9, 2 )
  
  printf("\nLista 2:");
  imprimir(lista2);


  printf("\n\n\n==== Unindo listas 1 e 2 para formar a lista 3 ====\n");

  // Criação da lista 3
  TListaDupEnc lista3;

  lista3 = merge(&lista1, &lista2);
  printf("Lista 3:");
  imprimir(lista3); // Lista (5, 0, 2, 7, 2, 1, 4, 3, 9, 9, 2)


  printf("\n\n\n==== Verificando a quantidade de ocorrências nas listas ====\n");
  printf("Ocorrências do valor 2 na lista 1: %d\n", contaValor(&lista1, 2));
  printf("Ocorrências do valor 5 na lista 1: %d\n", contaValor(&lista1, 5));
  printf("\n");
  printf("Ocorrências do valor 3 na lista 2: %d\n", contaValor(&lista2, 3));
  printf("Ocorrências do valor 9 na lista 2: %d\n", contaValor(&lista2, 9));
  printf("\n");
  printf("Ocorrências do valor 2 na lista 3: %d\n", contaValor(&lista3, 2));
  printf("Ocorrências do valor 4 na lista 3: %d\n", contaValor(&lista3, 4));


  printf("\n\n==== Remoção de elementos da Lista 1 ====\n");

  printf("Lista 1 antes da remoção:");
  imprimir(lista1);// Lista ( 5, 2, 2, 4 )

  printf("\nRemovendo elemento 5 do INÍCIO da Lista 1!\n");
  removerPrimeiro(&lista1); // Lista ( 2, 2, 4 )

  printf("Removendo elemento 2 do INÍCIO da Lista 1!\n");
  removerPrimeiro(&lista1); // Lista ( 2, 4 )

  printf("Removendo elemento 4 do FINAL da Lista 1!\n");
  removerUltimo(&lista1); // Lista ( 2 )

  printf("Removendo elemento 2 do FINAL da Lista 1!\n");
  removerUltimo(&lista1); // Lista (  )
  
  printf("\nLista 1:");
  imprimir(lista1);

  printf("\n\nTeste de remoção em lista vazia:\n");
  removerUltimo(&lista1);

  printf("\n---\n");
  return 0;
}