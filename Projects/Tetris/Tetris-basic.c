#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PIECES 10

typedef struct {
    char type;
    int id;
} Piece;
typedef struct {
    Piece itens[MAX_PIECES];
    int start, end, total;
} Queue;

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initQueue(Queue* q) {
    q->end = 0;
    q->start = 0;
    q->total = 0;
}

int isFull(Queue* q) { return q->total == MAX_PIECES; }
int isEmpty(Queue* q) { return q->total == 0; }

void insertQueue(Queue* q, Piece p) {
    if (isFull(q)) return;
    
    q->itens[q->end] = p;
    q->end = (q->end + 1) % MAX_PIECES;
    q->total++;
}

void removeQueue(Queue* q, Piece* p) {
    if (isEmpty(q)) return;

    *p = q->itens[q->start];
    q->start = (q->start + 1) % MAX_PIECES;
    q->total--;
}

void addRandomPiece(Queue* q) {
    if (isFull(q)) {
        printf("\n[!] ERRO: A fila esta cheia!\n");
        return;
    }
    char types[] = {'I', 'O', 'T', 'S', 'Z', 'J', 'L'};
    int r = rand() % 7;

    Piece newP;
    newP.type = types[r];
    newP.id = r;
    
    insertQueue(q, newP);
}


void showQueue(Queue* q) {
    printf("\n--- ESTADO DA FILA [%d/%d] ---\n", q->total, MAX_PIECES);
    
    if (isEmpty(q)) {
        printf("(Fila Vazia)");
    } else {
        int idx = q->start;
        for (int i = 0; i < q->total; i++) {
            printf("[%c] ", q->itens[idx].type);
            idx = (idx + 1) % MAX_PIECES;
        }
    }
    printf("\n------------------------------\n");
}

void peekNext(Queue* q) {
    if (isEmpty(q)) {
        printf("\n[!] Fila vazia.\n");
        return;
    }
    printf("\n-> PROXIMA PECA: [%c] (ID: %d)\n", 
            q->itens[q->start].type, q->itens[q->start].id);
}

void fillQueue(Queue* q) {
    printf("\n[*] Preenchendo fila...\n");
    while (!isFull(q)) {
        addRandomPiece(q);
    }
}

int main() {
    Queue q;
    Piece p;
    initQueue(&q);
    srand(time(NULL));

    int op = -1;
    
    printf("=== GERENCIADOR DE PECAS ===\n");

    do {
        printf("\n1. Iniciar/Completar | 2. Inserir | 3. Remover");
        printf("\n4. Ver Proxima       | 5. Mostrar | 0. Sair");
        printf("\nEscolha: ");
        
        if (scanf("%d", &op) != 1) {
            cleanBuffer();
            printf("\n[!] Erro: Digite um numero.\n");
            continue;
        }
        cleanBuffer();

        switch (op) {
            case 1: 
                fillQueue(&q); 
                showQueue(&q); 
                break;
            case 2: 
                addRandomPiece(&q); 
                showQueue(&q); 
                break;
            case 3: 
                if (!isEmpty(&q)) {
                    removeQueue(&q, &p);
                    printf("\n[-] Removido: [%c]\n", p.type);
                } else {
                    printf("\n[!] Nada para remover.\n");
                }
                showQueue(&q); 
                break;
            case 4: 
                peekNext(&q); 
                break;
            case 5: 
                showQueue(&q); 
                break;
            case 0: 
                printf("\nEncerrando...\n"); 
                break;
            default: 
                printf("\n[!] Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}
