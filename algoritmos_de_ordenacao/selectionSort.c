#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *v, int N) {
  int i, j, aux, fim = N;

  for(i = 0; i < fim; i++) {
    for(j=i+1; j < fim; j++) {
      if (v[i] > v[j]) {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        i--;
        break;
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

  selectionSort(v, 9);
  mostrarLista(v, 9);
  

  return 0;
}