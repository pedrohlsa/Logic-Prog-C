#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define TAM 30
#define COR 10
#define MAX 5

struct Territorio {
    char nome[TAM];
    char cor[COR];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void jogo() {
    int op;
    int total = 0;
    struct Territorio territorio[MAX];

    printf("Bem vindo ao jogo War!\n");
    
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Para inserir as 5 tropas\n2. Para ver as tropas inseridas\n0. Para sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        limparBufferEntrada();
    
        switch (op) {
           case 1:
                if (total < MAX) {
                    printf("\n--- Cadastro do %do Territorio ---\n", total + 1);
                    
                    printf("Nome: ");
                    fgets(territorio[total].nome, TAM, stdin);
                
                    printf("Cor: ");
                    fgets(territorio[total].cor, COR, stdin);
                   
                    territorio[total].nome[strcspn(territorio[total].nome, "\n")] = '\0'; 
                    territorio[total].cor[strcspn(territorio[total].cor, "\n")] = '\0';

                    printf("Quantidade de tropas: ");
                    scanf("%d", &territorio[total].tropas);
                    limparBufferEntrada();
                    
                    total++; 
                    printf("\nCadastrado com sucesso!\n");
                } else {
                    printf("\nO limite de %d territorios ja foi atingido!\n", MAX);
                }
                printf("Pressione enter para continuar...");
                getchar();
                break;

            case 2:
                if (total > 0) {
                    printf("\n--- Lista de Territorios ---\n");
                    for (int i = 0; i < total; i++) {
                        printf("\nTerritório #%d\n", i + 1);
                        printf("Nome Do Território: %s\n", territorio[i].nome);
                        printf("Cor do Território: %s\n", territorio[i].cor);
                        printf("Tropas do Território: %d\n", territorio[i].tropas);
                    }
                } else {
                    printf("\nNenhum territorio cadastrado ainda!\n");
                }
                printf("Pressione enter para continuar...");
                getchar();
                break;

            case 0:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (op != 0);
}

int main () {
    jogo();
    return 0;
}
