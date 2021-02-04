# Lista Duplamente Encadeada
[Arquivo.h](./ListaDuplaEncad.h)<br/>
[Arquivo.c](./ListaDuplaEncad.c)
<hr>

## ✏ Definição:
"Lista Dinâmica Duplamente Encadeada":
Tipo de "Lista" onde cada elemento aponta para o seu sucessor na e antecessor na "lista". Usa um ponteiro especial para o primeiro elemento da lista e uma indicação de final de lista, nos dois sentidos.
<br/>
- Cada elemento é tratado como um ponteiro que é **alocado dinamicamente** a medida que os dados são inseridos.
- Para guardar o primeiro elemento, utilizamos um **"ponteiro para ponteiro".**
- Um "ponteiro para ponteiro" pode guardar um endereço de um "ponteiro".
- Assim, fica fácil mudar quem está no início da lista mudando o "conteúdo" do "ponteiro para ponteiro".
<hr>

## ✅ Vantagens:
- Melhor utilização dos recursos de memória.
- Não precisa movimentar os elementos nas operações de inserção e remoção.
<hr>

## ❌ Desvantagens do uso de arrays:
- Acesso indireto aos elementos.
- Necessidade de percorrer a lista para acessar um elemento.
<hr>

## 💡 Quando utilizar essa "Lista"?
- Não há necessidade de garantir um espaço mínimo para a execução do aplicativo.
- Inserção/remoção em lista ordenada são as operações mais frequente.
- Necessidade de acessar informação de um elemento antecessor.
<hr>

## 🛠 Implementação:
### ⚠ Algumas informações básicas sobre a lista:
- Tamanho?
- Está cheia?
- Está vazia?

### ⚠ Funções iniciais:
- criar a lista (alocar memória)
- destruiir a lista (liberar memória)

### ➕ Inserção:
- Início
- Meio (ordenada)
- Fim

### ➖ Remoção:
- Início
- Meio (remove item pelo valor e não pela posição)
- Fim

Os 3 tipos de remoção trabalham juntos. A remoção sempre remove um elemento específico da lista, o qual pode estar no início, no meio ou no final da lista.

**⚠ Cuidado**:
- Não se pode remover de uma lista vazia.
- Removendo o último nó, a lista fica vazia.

### 🔍 Consulta:
- pela posição (necessidade de busca)
- pelo conteúdo (necessidade de busca)