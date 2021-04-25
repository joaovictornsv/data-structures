typedef struct noLista {
  int dado;
  struct noLista *ant;
  struct noLista *prox;
} No;

typedef No* TListaDupEnc;

/**
 * Recebe uma mensagem e imprime na tela na formatação de erro.
*/
void mostrarErro(char *messagem);


/**
 * Conta e retorna o número de ocorrências do valor informado na lista.
*/
int contaValor(TListaDupEnc* lista, int valor);


/**
 * Insere o valor informado no início da lista informada.
 * Possui dois retornos:
 * 0 => Caso ocorra algum erro durante a execução da função.
 * 1 => Nenhum erro ocorreu e a tarefa foi finalizada.
*/
int inserirNoInicio(TListaDupEnc* lista, int valor);


/**
 * Insere o valor informado no final da lista informada.
 * Possui dois retornos:
 * 0 => Caso ocorra algum erro durante a execução da função.
 * 1 => Nenhum erro ocorreu e a tarefa foi finalizada.
*/
int inserirNoFinal(TListaDupEnc* lista, int valor);


/**
 * Remove o primeiro valor da lista informada.
 * Possui dois retornos:
 * 0 => Caso ocorra algum erro durante a execução da função.
 * 1 => Nenhum erro ocorreu e a tarefa foi finalizada.
*/
int removerPrimeiro(TListaDupEnc* lista);


/**
 * Remove o último valor da lista informada.
 * Possui dois retornos:
 * 0 => Caso ocorra algum erro durante a execução da função.
 * 1 => Nenhum erro ocorreu e a tarefa foi finalizada.
*/
int removerUltitmo(TListaDupEnc* lista);


/**
 * Recebe duas listas e retorna uma nova lista formada pela junção destas.
*/
TListaDupEnc* merge(TListaDupEnc* lista1, TListaDupEnc* lista2);