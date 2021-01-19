#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 50
#define ANSI_COLOR_RED     "\x1b[31m"
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
  system("cls");
  struct pessoa usuario;
  printf(ANSI_COLOR_WHITE"CADASTRO"ANSI_COLOR_RESET"\n\n");

  printf("Nome: ");
  fgets(usuario.nome, MAX, stdin);
  fgets(usuario.nome, MAX, stdin);
  strtok(usuario.nome, "\n");

  printf("Idade: ");
  scanf("%d", &usuario.idade);

  printf("Peso: ");
  scanf("%f", &usuario.peso);

  printf("\nEndereco: \n");
  printf("> Rua: ");
  fgets(usuario.endereco.rua, MAX, stdin);
  fgets(usuario.endereco.rua, MAX, stdin);
  strtok(usuario.endereco.rua, "\n");


  printf("> Numero: ");
  scanf("%d", &usuario.endereco.numero);


  return usuario;
}

void ver(struct pessoa *lista, int len) {
  int i;
  system("cls");
  printf(ANSI_COLOR_WHITE"LISTA DE CADASTRADOS"ANSI_COLOR_RESET"\n");

  //FORMATO DE LISTA

  for(i = 0; i < len; i++) {
    printf("\n"ANSI_COLOR_WHITE"==== PESSOA %d ===="ANSI_COLOR_RESET"\n", i+1);
    printf("%-10s %s\n","Nome:", lista[i].nome);
    printf("%-10s %d\n","Idade:", lista[i].idade);
    printf("%-10s %.1f\n","Peso:", lista[i].peso);
    printf("\nEndereco:\n");
    printf("%-10s %s\n", "> Rua:", lista[i].endereco.rua);
    printf("%-10s %d\n", "> Numero:", lista[i].endereco.numero);
  }

  //FORMATO DE TABELA

  // printf("%-7s| %-20s| %-6s| %-5s| %-15s| %-7s\n", "Pessoa", "Nome", "Idade", "Peso", "Rua", "Numero");
  // for (int l = 0; l < 79; l++ ) {
  //   printf("=");
  // }
  // printf("\n");
  // for(i = 0; i < len; i++) {
  //   printf("%-7d| ", i+1);
  //   printf("%-20s| ", lista[i].nome);
  //   printf("%-6d| ", lista[i].idade);
  //   printf("%-5.1f| ", lista[i].peso);
  //   printf("%-15s| ", lista[i].endereco.rua);
  //   printf("%-7d\n", lista[i].endereco.numero);
  // }

  char menu[1];
  printf("\nInsira"ANSI_COLOR_WHITE" qualquer tecla "ANSI_COLOR_RESET"para retornar ao menu.\n");
  scanf("%s",&menu);

}

int main() {
  struct pessoa pessoas[MAX];
  int size = 0;

 for (;;) {
    menu();
    int opcao, i, usuario;
    
    escolherOpcao:
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        pessoas[size] = criar();
        printf("\n" ANSI_COLOR_GREEN "Usuario cadastrado!" ANSI_COLOR_RESET "\n" );
        size++;
        break;

      case 2:
        ver(pessoas, size);
        break;

      case 3:
        system("cls");
        printf(ANSI_COLOR_WHITE"QUAL USUARIO DESEJA DELETAR?"ANSI_COLOR_RESET"\n\n");
        
        for(i = 0; i < size; i++) {
          printf("[%d] %s\n", i, pessoas[i].nome);
        }
        printf("\n");

        printf("Numero do usuario: ");
        while(1) {
          scanf("%d", &usuario);
          if (usuario > size || usuario < 0) {
            printf("Opcao invalida!\n");
          }
          else {
            break;
          }
        }

        for (i = 0; i < size; i++) {
          if (i == usuario) {
            pessoas[i] = pessoas[i + 1];
          }
        }
        printf("\n"ANSI_COLOR_RED "Usuario removido!" ANSI_COLOR_RESET "\n" );
        size--;
        break;

      case 4: printf("Saindo..."); Sleep(1000); goto exit;

      default: printf("Opcao Invalida. ");goto escolherOpcao;
    }

    printf("Retornando ao menu...");
    Sleep(2000);
  }
  

  exit:
  return 0;
}
