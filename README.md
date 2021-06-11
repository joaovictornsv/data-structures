<div align="center">
  <h1>Estrutura de Dados em <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg"  alt="c" height=30/></h1>
  
  #### Repositório criado para auxiliar nos meus estudos em C e na disciplina de Estrutura de Dados.
  *Conteúdo retirado do canal [Linguagem C Programação Descomplicada](https://www.youtube.com/channel/UCUc6UwvpQfOLDE7e52-OCMw)*
</div>

---

<h2 id="conteudos">Conteúdos</h2>

[➜ Progresso](#purple_circle-progresso)<br>
[➜ Básico sobre Estrutura de Dados](#purple_circle-básico-sobre-estrutura-de-dados)<br>
[➜ Alocação de memória](#purple_circle-alocação-de-memória)<br>
[➜ Listas](#purple_circle-listas)<br>
[➜ Filas](#purple_circle-filas)<br>
[➜ Pilhas](#purple_circle-pilhas)<br><br>
[➜ Programa de cadastro](#purple_circle-programa-de-cadastro)<br>


---

## :purple_circle: Progresso:
<details>
  <summary>
    Conteúdos
  </summary>
  
### Básico
- [x] Tipos de dados
- [x] Modularização
- [x] Passagem de valores (por valor e por referência)
- [x] Alocação dinânima de memória

### Tipos Abstratos de Dados (TAD):
- [x] Lista Sequencial
- [x] Lista Simplesmente Encadeada
- [x] Lista Duplamente Encadeada
- [x] Lista Encadeada Circular
- [x] Fila Estática
- [x] Fila Dinâmica
- [x] Pilha Estática
- [x] Pilha Dinâmica

### Árvores:
- [ ] Conceitos básicos
- [ ] Implementação de árvores binárias
- [ ] Percurso
- [ ] Matriz esparsa

#### Classificação e pesquisa de dados:
- [x] Bubble
- [x] Inserção
- [x] Seleção
- [ ] Shell
- [x] Quick
- [ ] Busca linear
- [ ] Pesquisa binária
- [ ] Árvore binária de busca

</details>

<details>
  <summary>
    Projetos
  </summary>

- [Programa de cadastro](#programa-de-cadastro)
</details>

<hr>

## :purple_circle: Básico sobre Estrutura de Dados
### ✏ Conceitos
**Tipo de dado**: define o conjunto de valores (domínio) que uma variável pode assumir.

Ex: `int`<br/>
`
... -2, -1, 0, 1, 2, ...
`

**Estrutura de Dados**: trata-se de um relacionamento lógico entre tipos de dados.

**Tipos Abstratos de Dados**: incluem as operações para manipulação dos dados.
Ex:
- criação da estrutura
- inclusão de um elemento
- remoção de um elemento
- acesso a um elemento
- etc

### ✅ Vantagens:
- Encapsulamento e Segurança: usuário não tem acesso direto aos dados.

- Flexibilidade e Reutilização: podemos alterar o "TAD" sem alterar as aplicações que o utilizam.

### 📦 Modularização e TAD:
A convenção em linguagem C é preparar dois arquivos para implementar um "TAD":

- **Arquivo ".H"**: protótipos das funções, tipos de ponteiros, e dados globalmente acessíveis.

- **Arquivo ".C"**: declaração do tipo de dado e implementação das suas funções.

Assim separamos o "conceito" (definição do tipo) de sua "implementação".

<hr>

## :purple_circle: Alocação de memória
**Alocação estática:**
- O espaço de memória é alocado no momento da compilação.
- Exige a definição do número máximo de elementos da "Lista".
- Acesso sequencial: elementos consecutivos na memória.

**Alocação dinâmica:**
- O espaço de memória é alocado em tempo de execução.
- A "Lista" cresce à medida que novos elementos são armazenados, e diminui à medida que elementos são removidos.
- Acesso encadeado: cada elemento pode estar em uma área distinta da memória. Para acessar um elemento, é preciso percorrer todos os seus antecessores na "Lista".
<hr>

## :purple_circle: Listas
Em uma "Lista" podemos realizar as seguintes operações básicas:
- criação da lista
- inserção de um elemento
- exclusão de um elemento
- acesso a um elemento
- destruição da lista
- etc

Essas operações dependem do tipo de alocação de memória usada:
- estática
- dinâmica

**👉 Listas Implementadas:**
- [Lista Sequencial](./estrutura_de_dados/ListaSequencial)
- [Lista Simplesmente Encadeada](./estrutura_de_dados/ListaSimpEncad)
- [Lista Duplamente Encadeada](./estrutura_de_dados/ListaDuplaEncad)
- [Lista Encadeada Circular](./estrutura_de_dados/ListaCircular)
<hr>

## :purple_circle: Filas
Uma "Fila" é um tipo especial de "Lista":
- Inserções e exclusões de elementos ocorrem nas extremidades da "lista"

Em uma "Fila" podemos realizar as seguintes operações básicas:
- criação da fila
- inserção de um elemento no "final"
- exclusão de um elemento do "início"
- acesso ao elemento do "início"
- destruição da fila

Essas operações dependem do tipo de alocação de memória usada:
- estática
- dinâmica

**👉 Filas Implementadas:**
- [Fila Estática](./estrutura_de_dados/FilaEstatica)
- [Fila Dinâmica](./estrutura_de_dados/FilaDinamica)

<hr>

## :purple_circle: Pilhas
Uma "Pilha" é um tipo especial de "Lista":
- Inserções e exclusões de elementos ocorrem apenas elementos no início da "lista"

Em uma "Pilha" podemos realizar as seguintes operações básicas:
- criação da pilha
- inserção de um elemento no "início"
- exclusão de um elemento do "início"
- acesso ao elemento do "início"
- destruição da pilha

Essas operações dependem do tipo de alocação de memória usada:
- estática
- dinâmica

**👉 Pilhas Implementadas:**
- [Pilha Estática](./estrutura_de_dados/PilhaEstatica)
- [Pilha Dinâmica](./estrutura_de_dados/PilhaDinamica)

<hr>

## :purple_circle: Programa de cadastro
Esse projeto realiza as seguintes funções:

✅ Cadastrar uma pessoa <br/>
✅ Listar pessoas cadastradas<br/>
✅ Deletar uma pessoa<br/>

Para acessar o código [clique aqui](./projeto_cadastro/main.c).
<div align="center">
  
  ### Prévia:
  
  <img src="./projeto_cadastro/gif.gif" width=600>
</div>

---

<div>
  <img align="left" src="https://i.imgur.com/ufUYAFh.png" width=35 alt="Profile"/>
  <sub>Made with 💙 by <a href="https://github.com/joaovictornsv">João Victor</a></sub>
</div>
