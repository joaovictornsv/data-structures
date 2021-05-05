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


int main() {

  int v[] = {9, 8, 7, 6, 5, 4 ,3, 2, 1};

  for (int i = 0; i < 9; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");


  bubbleSort(v, 9);
  for (int i = 0; i < 9; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  

  return 0;
}