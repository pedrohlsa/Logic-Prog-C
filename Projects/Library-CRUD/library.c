#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_CARACTERES 100
#define MAX_LIVROS 50

struct Livros
{
    char nome[MAX_CARACTERES];
    char autor[MAX_CARACTERES];
    char editora[MAX_CARACTERES];
    int edicao;
};

void limparbufferentrada()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void iniciardatabase()
{
    int op, totalivros = 0;
    struct Livros biblioteca[MAX_LIVROS];

    printf("Bem vindo à database da Biblioteca.");
    do {
    printf("\n1. Para inserir novos livros.\n2. Para verificar os livros cadastrados.\n0. Para sair da database.\n");
    printf("Escolha: ");
    scanf("%d", &op);
    limparbufferentrada();

    switch (op)
    {
    case 1:
        if (totalivros < MAX_LIVROS)
        {
            printf("Bem vindo a parte de inserção de Livros!\n");
            printf("Digite o nome do Livro:\n");
            fgets(biblioteca[totalivros].nome, MAX_CARACTERES, stdin);

            printf("Digite o nome do Autor:\n");
            fgets(biblioteca[totalivros].autor, MAX_CARACTERES, stdin);

            printf("Digite a editora do Livro:\n");
            fgets(biblioteca[totalivros].editora, MAX_CARACTERES, stdin);

            biblioteca[totalivros].nome[strcspn (biblioteca[totalivros].nome, "\n")] = '\0'; 
            biblioteca[totalivros].autor[strcspn (biblioteca[totalivros].autor, "\n")] = '\0';
            biblioteca[totalivros].editora[strcspn(biblioteca[totalivros].editora, "\n")] = '\0';

            printf("Edição do Livro: (sem barras, apenas os numeros.)\n");
            scanf("%d", &biblioteca[totalivros].edicao);
            limparbufferentrada();

            totalivros++;
        } else
        {
            printf("Database lotada!");
        }
        printf("Aperte enter para continuar  ");
        getchar();
        break;
    case 2:
        if (totalivros > 0)
        {
            printf("\nBem vindo a parte de conferir os livros!\n");
            for (int i = 0; i < totalivros; i++)
            {
            printf("Livro: #%d\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao);
            }
        } else
        {
            printf("Nenhum livro cadastrado ainda!");
        }
        printf("Aperte enter para continuar  ");
        getchar();        
        break;
    case 0:
        printf("Saindo da database.\n");
        printf("Aperte enter para continuar  ");
        getchar();
        break;
        
    default:
        printf("Opção invalida! Tente novamente.");
        printf("Aperte enter para continuar  ");
        getchar();
      
    }
   } while (op != 0);
}

int main() {
    iniciardatabase();
    return 0;
}
