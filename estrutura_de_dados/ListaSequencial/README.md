# Lista Sequencial
[Arquivo.h](./ListaSequencial.h)<br/>
[Arquivo.c](./ListaSequencial.c)
<hr>

## ✏ Definição:
"Lista Sequencial Estática" ou "Lista Linear Estática":
Tipo de "Lista" onde o sucessor de um elemento ocupa a posição física seguinte do mesmo (uso de "array").
<hr>

## ✅ Vantagens do uso de arrays:
- Acesso rápido e direto aos elementos (índice)
- Tempo constante para acessar um elemento
- Facilidade em modificar informações.
<hr>

## ❌ Desvantagens do uso de arrays:
- Definição prévia do tamanho do array.
- Dificuldade para inserir e remover um elemento entre outros dois: é necessário deslocar os elementos.
<hr>

## 💡 Quando utilizar essa "Lista"?
- Listas pequenas
- Inserção/remoção apenas no final da lista
- Tamanho máximo bem definido
- A busca é a operação mais frequente
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

### 🔍 Consulta:
- pela posição (acesso direto)
- pelo conteúdo (necessidade de busca)
