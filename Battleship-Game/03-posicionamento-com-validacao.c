#include <stdio.h>
#include <ctype.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0

int matriz[TAM][TAM] = {0};

void regras() {
    printf("\n--- As regras do jogo sao ---\n");
    printf("1- 0 representa agua e 3 representa os navios.\n");
    printf("2- Cada navio ocupa 3 casas.\n");
    printf("3- Voce pode posicionar na horizontal, vertical ou diagonal.\n");
    printf("4- Tabuleiro 10x10: 1-10 (Vertical) e A-J (Horizontal).\n");
}

void imprimirxadrez() {
    printf("\n    A B C D E F G H I J\n");
    for(int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // 
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void posicionar_navio() {
    char col_char;
    int direcao, linha_idx;
    int tamanho = 3;
    
    printf("\n--- Vamos Posicionar os Navios! ---\n");
    printf("[0] Horizontal | [1] Vertical | [2] Diagonal\nEscolha: ");
    scanf("%d", &direcao);
    
    printf("Escolha a coordenada (Ex: A 5): ");
    
    scanf(" %c %d", &col_char, &linha_idx);

    int c = toupper(col_char) - 'A'; 
    int l = linha_idx - 1;          

    int error = 0;

 
    for(int i = 0; i < tamanho; i++) {
        int nl = l, nc = c;

        if (direcao == 0)      { nc = c + i; }
        else if (direcao == 1) { nl = l + i; }
        else if (direcao == 2) { nl = l + i; nc = c + i; } 


        if (nl < 0 || nl >= TAM || nc < 0 || nc >= TAM || matriz[nl][nc] != AGUA) {
            error = 1;
            break; 
        }
    }
    
    if (!error) {
        for(int i = 0; i < tamanho; i++) {
            int nl = l, nc = c;

            if (direcao == 0)      { nc = c + i; }
            else if (direcao == 1) { nl = l + i; }
            else if (direcao == 2) { nl = l + i; nc = c + i; }

            matriz[nl][nc] = NAVIO; 
        }
        printf("\nNavio posicionado com sucesso!\n");
        imprimirxadrez();
    } else {
        printf("\nERRO: Posicao invalida ou ocupada!\n");
    }
}

void iniciarjogo() {
    int opcao, sair = 0; 
    do {
        printf("\n--- BATALHA NAVAL ---\n1. Jogar\n2. Regras\n3. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirxadrez();
                posicionar_navio();
                break;
            case 2:
                regras();
                break; 
            case 3:
                printf("Saindo...\n");
                sair = 1;
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (sair == 0);
}

int main() {
    iniciarjogo();
    return 0;
}
