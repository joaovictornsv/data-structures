<div align="center">
  <h1>Estrutura de Dados em <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg"  alt="c" height=30/></h1>
  
  #### Repositório criado para auxiliar nos meus estudos em C e na disciplina de Estrutura de Dados.
  *Conteúdo retirado do canal [Linguagem C Programação Descomplicada](https://www.youtube.com/channel/UCUc6UwvpQfOLDE7e52-OCMw)*
</div>

<hr>

## Meu progresso:
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
- [ ] Pilhas
- [ ] Fila Estática
- [ ] Fila Dinâmica

### Árvores:
- [ ] Conceitos básicos
- [ ] Implementação de árvores binárias
- [ ] Percurso
- [ ] Matriz esparsa

#### Classificação e pesquisa de dados:
- [ ] Bubble
- [ ] Inserção
- [ ] Seleção
- [ ] Shell
- [ ] Quick
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

## Básico sobre Estrutura de Dados
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

## Listas
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

**Alocação estática:**
- O espaço de memória é alocado no momento da compilação.
- Exige a definição do número máximo de elementos da "Lista".
- Acesso sequencial: elementos consecutivos na memória.

**Alocação dinâmica:**
- O espaço de memória é alocado em tempo de execução.
- A "Lista" crescre à medida que novos elementos são armazenados, e diminui à medida que elementos são removidos.
- Acesso encadeado: cada elemento pode estar em uma área distinta da memória. Para acessar um elemento, é preciso percorrer todos os seus antecessores na "Lista".

**👉 Listas Implementadas:**
- [Lista Sequencial](./estrutura_de_dados/ListaSequencial)
- [Lista Simplesmente Encadeada](./estrutura_de_dados/ListaSimpEncad)
- [Lista Duplamente Encadeada](./estrutura_de_dados/ListaDuplaEncad)
<hr>

## Programa de cadastro
Esse projeto realiza as seguintes funções:

:white_check_mark: Cadastrar uma pessoa <br/>
:white_check_mark: Listar pessoas cadastradas<br/>
:white_check_mark: Deletar uma pessoa<br/>

Para acessar o código [clique aqui](./projeto_cadastro/main.c).
<div align="center">
  
  ### Prévia:
  
  <img src="./projeto_cadastro/gif.gif" width=600>
</div>
