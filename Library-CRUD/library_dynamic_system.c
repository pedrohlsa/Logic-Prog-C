#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ML 50
#define EM 100
#define TAM_STRING 100

typedef struct {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
} Livro;

typedef struct {
    char usuario[TAM_STRING];
    int indiceLivro;
} Emprestimo;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    
    Livro *biblioteca = (Livro*) calloc(ML, sizeof(Livro));
    Emprestimo *emprestimos = (Emprestimo*) malloc(EM * sizeof(Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro fatal: memória insuficiente.\n");
        return 1;
    }

    int opcao, totallivros = 0, totalemprestimos = 0;

    do {
        printf("\n--- MENU BIBLIOTECA ---\n");
        printf("1. Cadastrar Livro\n2. Listar Livros\n3. Emprestar\n4. Relatorio\n0. Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) opcao = -1; 
        limparBufferEntrada(); 

        switch (opcao) {
            case 1:
                if (totallivros < ML) {
                    printf("Nome: ");
                    fgets(biblioteca[totallivros].nome, TAM_STRING, stdin);
                    biblioteca[totallivros].nome[strcspn(biblioteca[totallivros].nome, "\n")] = '\0';

                    printf("Autor: ");
                    fgets(biblioteca[totallivros].autor, TAM_STRING, stdin);
                    biblioteca[totallivros].autor[strcspn(biblioteca[totallivros].autor, "\n")] = '\0';

                    printf("Editora: "); 
                    fgets(biblioteca[totallivros].editora, TAM_STRING, stdin);
                    biblioteca[totallivros].editora[strcspn(biblioteca[totallivros].editora, "\n")] = '\0';

                    printf("Edicao: ");
                    scanf("%d", &biblioteca[totallivros].edicao);
                    limparBufferEntrada();

                    biblioteca[totallivros].disponivel = 1;
                    totallivros++; 
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia!\n");
                }
                break;

            case 2:
                printf("\n--- Livros Cadastrados ---\n");
                for (int i = 0; i < totallivros; i++) {
                    printf("Nome : %s\n", biblioteca[i].nome);
                    printf("Autor : %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edição: %d\n", biblioteca[i].edicao);
                    printf("Disponibilidade: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
                }
                break;

            case 3:
                if (totalemprestimos < EM && totallivros > 0) {
                    int numLivro;

                    for (int i = 0; i <totallivros; i++)
                    {
                        printf("Livro #%d\n", i + 1);
                        printf("Livro: %s\n", biblioteca[i].nome);
                        printf("Disponibilidade: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
                    }
                    printf("Digite o numero do livro para alugar: \n");
                    scanf("%d", &numLivro);
                    limparBufferEntrada();
                    
                    int idx = numLivro - 1;

    
                    if (idx >= 0 && idx < totallivros && biblioteca[idx].disponivel) {
                        printf("Digite o seu usuario: ");
                        fgets(emprestimos[totalemprestimos].usuario, TAM_STRING, stdin);
                        emprestimos[totalemprestimos].usuario[strcspn(emprestimos[totalemprestimos].usuario, "\n")] = '\0';

                        emprestimos[totalemprestimos].indiceLivro = idx;                        
                        biblioteca[idx].disponivel = 0;
                        totalemprestimos++;
                        printf("Emprestimo realizado!\n");
                    } else {
                        printf("Livro indisponivel ou ID inexistente!\n");
                    }
                } else {
                    printf("Nao ha livros para emprestar ou limite de emprestimos atingido.\n");
                }
                break;

            case 4: 
                printf("\n--- Relatorio de Emprestimos ---\n");
                for (int i = 0; i < totalemprestimos; i++) {
                    int pos = emprestimos[i].indiceLivro; // transformando um "dado" pra inserir no outro. tipo um banco de dado relacional.
                    printf("Usuario: %s | Livro: %s\n", emprestimos[i].usuario, biblioteca[pos].nome);
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default: 
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    // Liberar mem
    free(biblioteca);
    free(emprestimos);

    return 0;
}
