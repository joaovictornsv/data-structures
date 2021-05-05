#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int *v, int N) {
  int i, continua=1, aux, fim = N;

  while(continua != 0) {
    continua = 0;
    for(i = 0; i < fim-1; i++) {
      if (v[i] > v[i+1]) {
        aux = v[i];
        v[i] = v[i+1];
        v[i+1] = aux;
        continua = 1;
      }
    }
    fim--;
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

  bubbleSort(v, 9);
  mostrarLista(v, 9);
  

  return 0;
}