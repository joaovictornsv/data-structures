#include <stdlib.h>
#include <stdio.h>

void insertionSort(int *v, int N) {
  int i, j, aux, fim = N;

  for(i = 1; i < fim; i++) {
    for(j = 0; j < i; j++) {
      if (v[i] < v[j]) {
        aux = v[i];
        for (int k = i; k > j; k--) {
          v[k] = v[k-1];
        }
        v[j] = aux;
      }
    }
  }
}


void mostrarLista(int *v, int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }

  printf("\n");
}


int main() {

  int v[] = {9, 8, 7, 6, 5, 4 ,3, 2, 1};
  mostrarLista(v, 9);

  insertionSort(v, 9);
  mostrarLista(v, 9);
  

  return 0;
}