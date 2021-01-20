#define MAX 100

struct aluno {
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct lista Lista;

//Criar lista
Lista* cria_lista();

//Liberar lista
void libera_lista(Lista* li);

//Tamanho da lista
int tamanho_lista(Lista* li);

//Lista cheia
int lista_cheia(Lista* li);

//Lista vazia
int lista_vazia(Lista* li);

//Insercao na lista
int inserir_lista_final(Lista* li, struct aluno x);
int inserir_lista_inicio(Lista* li, struct aluno x);
int inserir_lista_ordenada(Lista* li, struct aluno x);

//Remocao da lista
int remover_lista_final(Lista* li);
int remover_lista_inicio(Lista* li);
int remover_lista_meio(Lista* li, int matricula);

//Consulta na lista
int consultar_lista_pos(Lista* li, int pos, struct aluno *x);
int consultar_lista_mat(Lista* li, int mat, struct aluno *x);