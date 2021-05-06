#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void merge(int *v, int inicio, int meio, int fim) {
  int *temp, pos_v1, pos_v2, v1_vazio, v2_vazio, i, j, k;
  int tamanho = (fim-inicio)+1;
  pos_v1 = inicio;
  pos_v2 = meio + 1;

  v1_vazio = 0;
  v2_vazio = 0;
  temp = (int*) malloc(tamanho*sizeof(int));
  if (temp != NULL) {
    for (i = 0; i < tamanho; i++) {
      if (!v1_vazio && !v2_vazio) {
        if (v[pos_v1] < v[pos_v2]) {
          temp[i] = v[pos_v1];
          pos_v1++;
        }
        else {
          temp[i] = v[pos_v2];
          pos_v2++;
        }

        if (pos_v1 > meio) v1_vazio = 1;
        if (pos_v2 > fim) v2_vazio = 1;
      }
      else {
        if (!v1_vazio) {
          temp[i] = v[pos_v1];
          pos_v1++;
        }
        if (!v2_vazio) {
          temp[i] = v[pos_v2];
          pos_v2++;
        }
      }
    }
  }

  for (j = 0, k = inicio; j < tamanho; j++, k++) {
    v[k] = temp[j];
  }
  free(temp);
};

void mergeSort(int *v, int inicio, int fim) {
  int meio;
  if (inicio < fim) {
    meio = floor((fim+inicio)/2);
    mergeSort(v, inicio, meio);
    mergeSort(v, meio+1, fim);
    merge(v, inicio, meio, fim);
  }
}

void mostrarLista(int *v, int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }

  printf("\n");
}


int main() {

  int vetor[] = {9, 8, 7, 6, 5, 4 ,3, 2, 1};
  mostrarLista(vetor, 9);

  mergeSort(vetor, 0, 8);
  mostrarLista(vetor, 9);
  

  return 0;
}