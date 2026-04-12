#include <stdio.h>

#define tam 10
#define navio 3
#define agua 0

int matriz[tam][tam] = {0};

void imprimirmatriz() {
    printf("\n    A B C D E F G H I J\n");
    for (int i = 0; i < tam; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < tam; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void aplicarhabilidade() {
    int op1;
    
    printf("--- Bem-vindo ao Batalha Naval ---\n");
    printf("Mapa atual:");
    imprimirmatriz();
    
    printf("\nEscolha a habilidade:\n0. Cone\n1. Cruz\n2. Octaedro\nEscolha: ");
    scanf("%d", &op1);

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            
            if (op1 == 0) { // Lógica do Cone
                if (i == 0 && j == 5) matriz[i][j] = navio;
                else if (i == 1 && (j >= 4 && j <= 6)) matriz[i][j] = navio;
                else if (i == 2 && (j >= 3 && j <= 7)) matriz[i][j] = navio;
            } 
            else if (op1 == 1) { // Lógica da Cruz
                if ( i == 0 && j == 5) matriz [i][j] = navio;
                else if (i == 1 && (j >= 4 && j <= 6)) matriz[i][j] = navio;
                else if (i == 2 && j == 5) matriz[i][j] = navio;
            } 
            else if (op1 == 2) { // Lógica do Octaedro 
                if (i == 0 && j == 4) matriz[i][j] = navio;
                else if (i == 1 && (j >= 3 && j <= 5)) matriz[i][j] = navio;
                else if (i == 2 && j == 4) matriz[i][j] = navio;
            }
        }
    }
    
    printf("\nMapa após habilidade:");
    imprimirmatriz();
}

int main() {
    aplicarhabilidade();
    return 0;
}
