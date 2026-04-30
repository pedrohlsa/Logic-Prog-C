#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ntam 30
#define tptam 20

typedef struct {
    char nome[ntam];
    char tipo[tptam];
    int prioridade;
} Vetor;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void insertVetor(Vetor** v, int* quantidade) {
    int novo;
    printf("\n=============================================\n");
    printf("   INSERCAO DE COMPONENTES NA TORRE\n");
    printf("=============================================\n");
    printf("Digite quantos componentes deseja inserir: ");
    
    if (scanf("%d", &novo) != 1) {
        printf("\n[!] Erro: Digite um numero valido!\n");
        limparBufferEntrada();
        return;
    } 
    limparBufferEntrada();

    int antigo = *quantidade;
    *quantidade += novo;

    *v = (Vetor*)realloc(*v, (*quantidade) * sizeof(Vetor));

    for (int i = antigo; i < *quantidade; i++) {
        printf("\n--- Componente #%d ---\n", i + 1);
        
        printf("Nome: ");
        fgets((*v)[i].nome, ntam, stdin);
        (*v)[i].nome[strcspn((*v)[i].nome, "\n")] = '\0';

        printf("Tipo: ");
        fgets((*v)[i].tipo, tptam, stdin);
        (*v)[i].tipo[strcspn((*v)[i].tipo, "\n")] = '\0';

        printf("Prioridade: ");
        while (scanf("%d", &(*v)[i].prioridade) != 1) {
            printf("[!] Erro: Digite um numero para prioridade: ");
            limparBufferEntrada();
        }
        limparBufferEntrada();
    }
    printf("\n[+] Sucesso: %d itens adicionados!\n", novo);
}

void bubbleSortPorNome(Vetor* v, int n, int* comp) {
    *comp = 0;
    int i, j, trocou;
    Vetor temp;
    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

void insertSortPorTipo(Vetor* v, int n, int* comp) {
    *comp = 0;
    int i, j;
    Vetor chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0) {
            (*comp)++;
            if (strcmp(v[j].tipo, chave.tipo) > 0) {
                v[j + 1] = v[j];
                j = j - 1;
            } else break;
        }
        v[j + 1] = chave;
    }
}

void selectionSortPorPrioridade(Vetor* v, int n, int* comp) {
    *comp = 0;
    int i, j, min;
    Vetor temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            (*comp)++;
            if (v[j].prioridade < v[min].prioridade) {
                min = j;
            }
        }
        if (min != i) {
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

int buscaBinariaPorNome(Vetor v[], int n, char alvo[]) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int comp = strcmp(v[meio].nome, alvo);
        if (comp == 0) return meio;
        if (comp > 0) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

int main() {
    int op, comparacoes, quantia = 0;
    Vetor* v = NULL;
    clock_t t;

    do {
        printf("\n=======================================\n");
        printf("      MENU PRINCIPAL - TORRE\n");
        printf("=======================================\n");
        printf("1. Inserir Componentes\n");
        printf("2. Ordenar e Listar\n");
        printf("0. Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &op) != 1) {
            printf("\n[!] Erro: Opcao invalida. Use apenas numeros.\n");
            limparBufferEntrada();
            continue; // Em vez de return -1, ele volta pro começo do loop
        }
        limparBufferEntrada();

        if (op == 1) {
            insertVetor(&v, &quantia);
        } 
        else if (op == 2) {
            if (quantia == 0) {
                printf("\n[!] A torre esta vazia. Insira itens primeiro.\n");
                continue;
            }
            int subop;
            printf("\n--- OPCOES DE ORDENACAO ---\n");
            printf("1. Bubble (Nome)\n2. Insertion (Tipo)\n3. Selection (Prioridade)\nEscolha: ");
            if (scanf("%d", &subop) != 1) {
                printf("\n[!] Erro: Digite um numero!\n");
                limparBufferEntrada();
                continue;
            }
            limparBufferEntrada();

            t = clock();
            if (subop == 1) bubbleSortPorNome(v, quantia, &comparacoes);
            else if (subop == 2) insertSortPorTipo(v, quantia, &comparacoes);
            else selectionSortPorPrioridade(v, quantia, &comparacoes);
            t = clock() - t;

            printf("\n--- LISTA DE COMPONENTES ---\n");
            printf("%-20s | %-15s | %-10s\n", "Nome", "Tipo", "Prioridade");
            for (int i = 0; i < quantia; i++) {
                printf("%-20s | %-15s | P: %-10d\n", v[i].nome, v[i].tipo, v[i].prioridade);
            }

            printf("\nEstatisticas: %d comparacoes | Tempo: %f s\n", comparacoes, (double)t / CLOCKS_PER_SEC);

            if (subop == 1) {
                char busca[ntam];
                printf("\nBusca Binaria - Nome do componente: ");
                fgets(busca, ntam, stdin);
                busca[strcspn(busca, "\n")] = '\0';

                int pos = buscaBinariaPorNome(v, quantia, busca);
                if (pos != -1) printf("=> Encontrado na posicao: %d!\n", pos);
                else printf("=> Item nao encontrado!\n");
            }
        }
    } while (op != 0);

    if (v) free(v);
    printf("\nSaindo... Torre finalizada.\n");
    return 0;
}
