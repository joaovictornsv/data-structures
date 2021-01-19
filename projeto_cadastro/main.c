#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 50
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_WHITE   "\x1b[1;37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct endereco {
  char rua[MAX];
  int numero;
};

struct pessoa {
  char nome[MAX];
  int idade;
  float peso;
  struct endereco endereco;
};

void menu() {
  system("cls");
  printf(ANSI_COLOR_WHITE "=== CADASTRO DE USUARIOS ===" ANSI_COLOR_RESET"\n\n");
  printf("[1] Criar uma pessoa\n[2] Ver pessoas criadas\n[3] Deletar uma pessoa\n[4] Sair\n");
};

struct pessoa criar() {
  struct pessoa usuario;
  char deseja_endereco[2];

  system("cls");
  printf(ANSI_COLOR_WHITE"CADASTRO"ANSI_COLOR_RESET"\n\n");

  printf("Nome: ");
  fgets(usuario.nome, MAX, stdin);
  fgets(usuario.nome, MAX, stdin);
  strtok(usuario.nome, "\n");

  printf("Idade: ");
  scanf("%d", &usuario.idade);

  printf("Peso: ");
  scanf("%f", &usuario.peso);

  printf("Deseja cadastrar endereco [S/N]? ");
    
  while(1) {
    fgets(deseja_endereco, 2, stdin);
    fgets(deseja_endereco, 2, stdin);
    if (*deseja_endereco != 's' &&
        *deseja_endereco != 'S' &&
        *deseja_endereco != 'n' &&
        *deseja_endereco != 'N')
    {
      printf(ANSI_COLOR_YELLOW"Opcao invalida!"ANSI_COLOR_RESET"\n");
    }
    else {
      break;
    }
  }

  if (*deseja_endereco == 's' || *deseja_endereco == 'S') {
    goto cadastrar_endereco;
  }
  else if (*deseja_endereco == 'n' || *deseja_endereco == 'N') {
    strcpy(usuario.endereco.rua, "Sem rua");
    usuario.endereco.numero = 0;
    goto end;
  }


  cadastrar_endereco:
  printf("\nEndereco: \n");
  printf("> Rua: ");
  fgets(usuario.endereco.rua, MAX, stdin);
  fgets(usuario.endereco.rua, MAX, stdin);
  strtok(usuario.endereco.rua, "\n");


  printf("> Numero: ");
  scanf("%d", &usuario.endereco.numero);

  end:
  printf("\n" ANSI_COLOR_GREEN "Usuario cadastrado!" ANSI_COLOR_RESET "\n" );
  return usuario;
}

void ver(struct pessoa *lista, int len) {
  while (1) {
    int i, usuario;
    char deseja_lista[2];
    system("cls");
    printf(ANSI_COLOR_WHITE"LISTA DE CADASTRADOS"ANSI_COLOR_RESET"\n\n");

    if (len == 0) {
      printf("Sem usuarios para listar!\n");
      return;
    }

    for(i = 0; i < len; i++) {
      printf("[%d] %s\n", i, lista[i].nome);
    }
    printf("\n");

    printf("Deseja ver os dados de qual usuario? [99 para retornar ao menu]\n");
    printf("> ");
  
    while(1) {
      scanf("%d", &usuario);

      if ((usuario > len && usuario != 99) || usuario < 0) {
        printf(ANSI_COLOR_YELLOW"Opcao invalida! Tente novamente: "ANSI_COLOR_RESET"\n");
      }
      else if (usuario == 99) {
        return;
      }
      else {
        break;
      }
    }

    system("cls");
    printf("\n"ANSI_COLOR_WHITE"==== DADOS DE %s ===="ANSI_COLOR_RESET"\n", (lista[usuario].nome));
    printf("%-10s %s\n","Nome:", lista[usuario].nome);
    printf("%-10s %d\n","Idade:", lista[usuario].idade);
    printf("%-10s %.1f\n","Peso:", lista[usuario].peso);
    if (lista[usuario].endereco.numero == 0) {
      printf("%-10s\n", "\n> Endereco nao cadastrado\n");
    } else {
      printf("\nEndereco:\n");
      printf("%-10s %s\n", "> Rua:", lista[usuario].endereco.rua);
      printf("%-10s %d\n", "> Numero:", lista[usuario].endereco.numero);
    }

    char menu[1];
    printf("Deseja voltar a lista de usuarios [S/N]? ");
    while(1) {
      fgets(deseja_lista, 2, stdin);
      fgets(deseja_lista, 2, stdin);
      if (*deseja_lista != 's' &&
          *deseja_lista != 'S' &&
          *deseja_lista != 'n' &&
          *deseja_lista != 'N')
      {
        printf(ANSI_COLOR_YELLOW"Opcao invalida!"ANSI_COLOR_RESET"\n");
      }
      else {
        break;
      }
    }

    if (*deseja_lista == 's' || *deseja_lista == 'S') {
      printf("Voltando a lista...");
      Sleep(1000);
      continue;
    }
    else if (*deseja_lista == 'n' || *deseja_lista == 'N') {
      return;
    }
  }
}

void deletar(struct pessoa *lista, int len) {
  int i, usuario;

  system("cls");
  printf(ANSI_COLOR_WHITE"QUAL USUARIO DESEJA DELETAR?"ANSI_COLOR_RESET"\n\n");
  
  if (len == 0) {
    printf("Sem usuarios para remover!\n");
    return;
  }

  for(i = 0; i < len; i++) {
    printf("[%d] %s\n", i, lista[i].nome);
  }
  printf("\n");

  printf("Numero do usuario: ");
  while(1) {
    scanf("%d", &usuario);

    if (usuario > len || usuario < 0) {
      printf(ANSI_COLOR_YELLOW"Opcao invalida! Tente novamente: "ANSI_COLOR_RESET"\n");
    }
    else {
      break;
    }
  }

  for (i = 0; i < len; i++) {
    if (i == usuario) {
      *(lista+i) = lista[i + 1];
    }
  }

  printf("\n"ANSI_COLOR_RED "Usuario removido!" ANSI_COLOR_RESET "\n" );
  if (len <= 0) {
    len = 0;
  }
}

int main() {
  struct pessoa pessoas[MAX];
  int size = 0;

 for (;;) {
    menu();
    int opcao, i;
    
    escolherOpcao:
    printf("Escolha uma opcao: ", size);
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        pessoas[size] = criar();
        size++;
        break;

      case 2:
        ver(pessoas, size);
        break;

      case 3:
        deletar(pessoas, size);
        size--;
        if (size <= 0) {
          size = 0;
        }
        break;

      case 4: printf("\nSaindo..."); Sleep(1000); goto exit;

      default: printf("Opcao Invalida. Tente novamente: ");goto escolherOpcao;
    }

    printf("Retornando ao menu...");
    Sleep(2000);
  }
  

  exit:
  return 0;
}
