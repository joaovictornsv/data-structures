#include <stdlib.h>
#include <stdio.h>

void quickSort(int *v, int N) {
  int i=0, j, aux, pivo, pos_pivo, continua=1, passou = 0, fim = N;

  
  while(1) {
    if (i == fim) {
      break;
    }
    if (passou == 1) {
      i++;
    }
    pivo = v[i];
    pos_pivo = i;
    continua = 1;

    while(continua) {
      continua = 0;
      passou = 1;

      for(j=fim-1; j>pos_pivo; j--) {
        if (v[pos_pivo] > v[j]) {
          aux = v[pos_pivo];
          v[pos_pivo] = v[j];
          v[j] = aux;
          pivo = v[j];
          pos_pivo = j;
          continua = 1;
          passou = 0;
          break;
        }      
      }
      continua = 0;
      for (j = 0; j < pos_pivo; j++) {
        if (v[j] > v[pos_pivo]) {
          aux = v[pos_pivo];
          v[pos_pivo] = v[j];
          v[j] = aux;
          pivo = v[j];
          pos_pivo = j;
          continua = 1;
          passou = 0;
          break;
        }
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

  quickSort(v, 9);
  mostrarLista(v, 9);
  

  return 0;
}