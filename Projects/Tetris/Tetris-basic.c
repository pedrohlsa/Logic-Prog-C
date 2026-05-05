#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define QNT_MAX 4
#define MAX_PECAS 5

typedef struct {
    char pecas[QNT_MAX];
    int id[QNT_MAX];
} Pecas;

typedef struct {
    Pecas itens[MAX_PECAS];
    int start, end, total;
} Fila;

void cleanBufferEntry() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void startqueue(Fila* f) {
    f->start = 0;
    f->end = 0;
    f->total = 0;
}

int emptyqueue(Fila *f) {
    return f->total == 0;
}

void insertnewPecas(Fila* f, Pecas p) {
    if (f->total == MAX_PECAS) {
        printf("[!] Fila Cheia!\n");
        return;
    }
    f->itens[f->end] = p;
    f->end = (f->end + 1) % MAX_PECAS;
    f->total++;
}

void randompeca(Fila* f) {
    char pieces[] = {'I', 'O', 'T', 'L'};
    
    printf("\n========================\n");
    printf("Inserir Pecas Aleatorias");
    printf("\n========================\n");

    int new_qty;
    printf("Quantas pecas quer add? ");
    if (scanf("%d", &new_qty) != 1) {
        printf("[!] Erro: Numeros apenas.\n");
        cleanBufferEntry();
        return;
    } cleanBufferEntry();

    for (int i = 0; i < new_qty; i++) {
        if (f->total < MAX_PECAS) {
            int r = rand() % 4;
            Pecas newP;
            newP.pecas[0] = pieces[r];
            newP.id[0] = r; 
            insertnewPecas(f, newP);
        } else {
            printf("[!] Limite atingido na peca %d\n", i + 1);
            break;
        }
    }
}

void removequeue(Fila *f, Pecas *p) {
    if (emptyqueue(f)) {
        printf("[!] Fila Vazia.\n");
        return;
    }
    *p = f->itens[f->start];
    f->start = (f->start + 1) % MAX_PECAS;
    f->total--;
    printf("Peca removida: %c\n", p->pecas[0]);
}

void peekqueue(Fila *f) {
    if (emptyqueue(f)) {
        printf("Fila vazia.\n");
        return;
    }
    
    printf("Fila atual: ");
    int idx = f->start;
    for (int i = 0; i < f->total; i++) {
        printf("[%c | ID:%d] ", f->itens[idx].pecas[0], f->itens[idx].id[0]);
        idx = (idx + 1) % MAX_PECAS;
    }
    printf("\nTotal: %d/%d\n", f->total, MAX_PECAS);
}

int main() {
    srand(time(NULL));
    Pecas p;
    Fila f;
    startqueue(&f);
    int op;
    
    do {
        printf("\n--- MENU TETRIS ---\n");
        printf("1. Inserir | 2. Remover | 3. Listar | 0. Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &op) != 1) {
            printf("[!] Digite um numero!\n");
            cleanBufferEntry();
            continue;
        } cleanBufferEntry();

        switch (op) {
            case 1: randompeca(&f); peekqueue(&f); break;
            case 2: removequeue(&f, &p); break;
            case 3: peekqueue(&f); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}
