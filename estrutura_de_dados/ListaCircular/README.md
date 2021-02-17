# Lista Circular
[Arquivo.h](./ListaCircular.h)<br/>
[Arquivo.c](./ListaCircular.c)
<hr>

## ✏ Definição:
"Lista Circular":
Tipo de "Lista" onde cada elemento aponta para o seu sucessor e o último elemento aponta para o primeira da "lista".

- Usa um ponteiro especial para o primeiro elemento da lista.
- Não existe uma indicação de final de lista

<br/>
- Cada elemento é tratado como um ponteiro que é **alocado dinamicamente** a medida que os dados são inseridos.
- Para guardar o primeiro elemento, utilizamos um **"ponteiro para ponteiro".**
- Um "ponteiro para ponteiro" pode guardar um endereço de um "ponteiro".
- Assim, fica fácil mudar quem está no início da lista mudando o "conteúdo" do "ponteiro para ponteiro".
<hr>

## ✅ Vantagens:
- Melhor utilização dos recursos de memória.
- Não precisa movimentar os elementos nas operações de inserção e remoção.
- Possibilidade de percorrer a lista diversas vezes
- Não precisamos considerar casos especiais de inclusão e remoção de elementos (primeiro e último).
<hr>

## ❌ Desvantagens do uso de arrays:
- Acesso indireto aos elementos.
- Necessidade de percorrer a lista para acessar um elemento.
- Lista não possui final definido.
<hr>

## 💡 Quando utilizar essa "Lista"?
- Não há necessidade de garantir um espaço mínimo para a execução do aplicativo.
- Inserção/remoção em lista ordenada são as operações mais frequente.
- Quando a necessidade de voltar ao primeiro item da lista depois de percorrê-la.
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
- pela posição
- pelo conteúdo

Ambos dependem de busca (percorrer os elementos) até encontrar o desejado.