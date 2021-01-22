struct aluno {
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct elemento* Lista;

//Cria a lista
Lista* cria_lista();

//Libera a lista
void libera_lista(Lista* li);

//Tamanho da lista
int tamanho_lista(Lista* li);

//Lista cheia
int lista_cheia(Lista* li);

//Lista vazia
int lista_vazia(Lista* li);

//Inserir na lista
int insercao_lista_inicio(Lista* li, struct aluno al);
int insercao_lista_final(Lista* li, struct aluno al);
int insercao_lista_ordenada(Lista* li, struct aluno al);

//Remover da lista
int remocao_lista_inicio(Lista* li);
int remocao_lista_final(Lista* li);
int remocao_lista_meio(Lista* li, int mat);

//Consulta na lista
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);