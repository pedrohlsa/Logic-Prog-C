#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char* nome;
    char* tipo;
    int quantidade;
    struct Item* proximo;
} Item;

// --- FUNÇÕES DE MANIPULAÇÃO ---

Item* inserirItem(Item* list, const char* nomeItem, const char* tipoItem, int numbers) {
    Item* novoNode = (Item*)malloc(sizeof(Item));
    if (novoNode == NULL) return list;

    novoNode->nome = (char*)malloc(strlen(nomeItem) + 1);
    strcpy(novoNode->nome, nomeItem);

    novoNode->tipo = (char*)malloc(strlen(tipoItem) + 1);
    strcpy(novoNode->tipo, tipoItem);

    novoNode->quantidade = numbers;
    novoNode->proximo = list;

    return novoNode;
}

Item* removerItem(Item* list, char* nomeItem) {
    Item* current = list;
    Item* before = NULL;

    while (current != NULL && strcmp(current->nome, nomeItem) != 0) {
        before = current;
        current = current->proximo;
    }

    if (current == NULL) {
        printf("\n[ERRO]: Item '%s' nao encontrado!\n", nomeItem);
        return list;
    }

    if (before == NULL) {
        list = current->proximo;
    } else {
        before->proximo = current->proximo;
    }

    free(current->nome);
    free(current->tipo);
    free(current);
    return list;
}

void buscarItemUnico(Item *list, char* nomeItem) {
    Item* head = list;
    int achou = 0;

    while (head != NULL) {
        if (strcmp(head->nome, nomeItem) == 0) {
            printf("\n--- ITEM ENCONTRADO ---");
            printf("\nNome: %s\nTipo: %s\nQuantidade: %d\n", head->nome, head->tipo, head->quantidade);
            achou = 1;
        }
        head = head->proximo;
    }
    if (!achou) printf("\nItem nao localizado.\n");
}

void buscarTodosItens(Item* list) {
    Item* head = list;
    printf("\n======= MOCHILA COMPLETA =======\n");
    while (head != NULL) {
        printf("Item: %-15s | Tipo: %-10s | Qtd: %d\n", head->nome, head->tipo, head->quantidade);
        head = head->proximo;
    }
    printf("================================\n");
}

// --- UTILITÁRIOS ---

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void freeTotal(Item* list) {
    while (list != NULL) {
        Item* prox = list->proximo;
        free(list->nome);
        free(list->tipo);
        free(list);
        list = prox;
    }
}

int contarElementos(Item* list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->proximo;
    }
    return count;
}

// --- MENUS ---

#define ITENS_MAX 10
#define BUFFER_TAM 100

void menuIniciar() {
    Item* list = NULL;
    int op;
    int items = 0;

    do {
        printf("\n---------- MENU GERENCIAR ----------\n");
        printf("1. Inserir Novo Item\n");
        printf("2. Remover Item\n");
        printf("3. Consultar Item Unico\n");
        printf("4. Listar Todos os Itens\n");
        printf("0. Sair para o Menu Principal\n");
        printf("Escolha: ");
        
        if (scanf("%d", &op) != 1) {
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();

        switch (op) {
            case 1:
                if (items < ITENS_MAX) {
                    char nomeItem[BUFFER_TAM], tipoItem[BUFFER_TAM];
                    int quantiaItem;

                    printf("\nNome do item: ");
                    fgets(nomeItem, BUFFER_TAM, stdin);
                    nomeItem[strcspn(nomeItem, "\n")] = '\0';

                    printf("Tipo do Item: ");
                    fgets(tipoItem, BUFFER_TAM, stdin);
                    tipoItem[strcspn(tipoItem, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &quantiaItem);
                    limparBufferEntrada();

                    list = inserirItem(list, nomeItem, tipoItem, quantiaItem);
                    items++;
                    printf("\n[SUCESSO]: Item adicionado!\n");
                } else {
                    printf("\n[AVISO]: Mochila cheia! Remova algo antes.\n");
                }
                break;

            case 2:
                if (list == NULL) {
                    printf("\n[AVISO]: A mochila ja esta vazia!\n");
                } else {
                    char buffer[BUFFER_TAM];
                    printf("\nNome do item para remover: ");
                    fgets(buffer, BUFFER_TAM, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    int antes = contarElementos(list);
                    list = removerItem(list, buffer);
                    int depois = contarElementos(list);

                    if (antes > depois) {
                        items--;
                        printf("\n[SUCESSO]: Item removido!\n");
                    }
                }
                break;

            case 3:
                if (list == NULL) {
                    printf("\n[AVISO]: Mochila vazia.\n");
                } else {
                    char buffer[BUFFER_TAM];
                    printf("\nNome para busca: ");
                    fgets(buffer, BUFFER_TAM, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    buscarItemUnico(list, buffer);
                }
                break;

            case 4:
                if (list == NULL) {
                    printf("\n[AVISO]: Mochila vazia.\n");
                } else {
                    buscarTodosItens(list);
                }
                break;

            case 0:
                printf("\nLimpando memoria e voltando...\n");
                freeTotal(list);
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 0);
}

int main() {
    int op;
    
    printf("====================================\n");
    printf("   BEM VINDO AO SISTEMA DE INVENTARIO\n");
    printf("====================================\n");

    do {
        printf("\n1. Gerenciar Mochila\n2. Sair do Jogo\nEscolha: ");
        
        if (scanf("%d", &op) != 1) {
            printf("\n[ERRO]: Digite apenas numeros!\n");
            limparBufferEntrada();
            continue;
        }
        limparBufferEntrada();

        switch (op) {
            case 1:
                menuIniciar();
                break;

            case 2:
                printf("\nSaindo do jogo... Ate logo!\n");
                break;

            default:
                printf("\n[AVISO]: Opcao %d invalida! Tente novamente.\n", op);
                break;
        }
        
    } while (op != 2);

    return 0;
}
