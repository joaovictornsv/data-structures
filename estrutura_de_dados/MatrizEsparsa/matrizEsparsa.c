#include <stdio.h>
#include <stdlib.h>
#include "matrizEsparsa.h"

struct node{
  int data;
  int column;
  struct node* next;
};

typedef struct node Node;

typedef Node* PONT;

struct matrix{
  int columns;
  int rows;
  PONT* arrangement;
};

sparseMatrix* create(int rows, int columns){
  sparseMatrix* ptr = (sparseMatrix*) malloc(sizeof(sparseMatrix));
  if(ptr != NULL){
    ptr->rows = rows;
    ptr->columns = columns;

    ptr->arrangement = (PONT*) malloc(rows*sizeof(PONT));
    if(ptr->arrangement != NULL){
      for(int i = 0; i < rows; i++){
        ptr->arrangement[i] = NULL;
      }

    }
  }
  return ptr;
}

int assign(sparseMatrix* matrix, int row, int column, int data){
  if(row < 0 || row >= matrix->rows 
  || column < 0 || column >= matrix->columns) return 0;

  PONT previous = NULL, current = matrix->arrangement[row];
  while(current != NULL && current->column < column){
    previous = current;
    current = current->next;
  }

  // Node exists?
  if(current != NULL && current->column == column){
    if(data == 0){
      //First element?
      if(previous == NULL){
        matrix->arrangement[row] = current->next;
      }else{
        previous->next = current->next;
      }
      free(current);
    }else{
      current->data = data;
    }
  }else{
    //We need storage the node?
    if(data != 0){
      PONT newNode = (PONT) malloc(sizeof(Node));
      if(newNode == NULL) return 0;

      newNode->column = column;
      newNode->data = data;
      newNode->next = current;

      //Will the node be in the first position or the row is empty?
      if(previous == NULL){
        matrix->arrangement[row] = newNode;
      }else{
        previous->next = newNode;
      }
    }
  }
  return 1;
}

int getData(sparseMatrix* matrix, int row, int column, int* data){
  if(row < 0 || row >= matrix->rows 
  || column < 0 || column >= matrix->columns) return 0;

  PONT current = matrix->arrangement[row];
  while(current != NULL && current->column < column){
    current = current->next;
  }
  
  if(current != NULL && current->column == column){
    *data = current->data;
  }else{
    *data = 0;
  }
  return 1;
}

void release(sparseMatrix* matrix){
  if(matrix != NULL){
    PONT current, temp;
    for(int i = 0; i < matrix->rows; i++){
      current = matrix->arrangement[i];
      while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
      }
    }
    free(matrix->arrangement);
    free(matrix);
  }
}

int show(sparseMatrix* matrix){
  if(matrix == NULL) return 0;
  PONT aux;
  printf("\n=-=-=-=-=-=-=-=-=-Sparse Matrix-=-=-=-=-=-=-=-=-=\n");
  for(int i = 0; i < matrix->rows;i++){
    aux = matrix->arrangement[i];
    for(int j = 0; j < matrix->columns; j++){
      if(aux != NULL && aux->column == j){
        printf("%d\t", aux->data);
        aux = aux->next;
      }else{
        printf("0\t");
      }
    }
    printf("\n");
  }
  return 1;
}

int getPrimaryDiagonal(sparseMatrix* matrix){
  if(matrix == NULL) return 0;

  printf("The Primary Diagonal is: [");
  PONT aux;
  int value = 0;
  for(int i = 0; i < matrix->rows; i++){
    value = 0;
    aux = matrix->arrangement[i];
    while(aux != NULL && aux->column <= i){
      if(aux->column == i){
        value = aux->data;
        break;
      }
      aux = aux->next;
    }
    if(i == matrix->rows-1){
      printf("%d",value);
    }else{
      printf("%d\t",value);
    }
  }
  printf("]\n");
  return 1;
}

int getSecondaryDiagonal(sparseMatrix* matrix){
  if(matrix == NULL) return 0;
   printf("The Secondary Diagonal is: [");
  PONT aux;
  int value = 0;
  for(int i = 0; i < matrix->rows; i++){
    value = 0;
    aux = matrix->arrangement[i];
    while(aux != NULL && ((i + aux->column) <= matrix->columns-1)){
      if(aux->column + i == matrix->columns-1){
        value = aux->data;
        break;
      }
      aux = aux->next;
    }
    if(i == matrix->rows-1){
      printf("%d",value);
    }else{
      printf("%d\t",value);
    }
  }
  printf("]\n");
  return 1;
}
