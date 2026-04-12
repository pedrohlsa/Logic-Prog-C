#include <stdio.h>
#include <ctype.h>

#define tam 10
#define hab 5
#define navio 3

int matriz[tam][tam] = {0};

void aplicar_efeito(int l, int c) {
    if (l >= 0 && l < tam && c >= 0 && c < tam) {
        matriz[l][c] = hab;
    }
}

void imprimirmatriz() {
    printf("\n     A B C D E F G H I J\n");
    for (int i = 0; i < tam; i++) {
        printf("%2d   ", i + 1);
        for (int j = 0; j < tam; j++) {
            if (matriz[i][j] == 0) printf("0 ");
            else if (matriz[i][j] == navio) printf("3 ");
            else if (matriz[i][j] == hab) printf("5 ");
        }
        printf("\n");
    }
    printf("\n");
}

void posicionar_navio() {
    char col_char;
    int linha, col_index, linha_idx, op1, op2;
    int error = 0;

    imprimirmatriz();
    printf("Escolha a orientacao do navio:\n");
    printf("0. Horizontal\n1. Vertical\n2. Diagonal\nEscolha: ");
    scanf("%d", &op1);

    do {
        printf("Escolha a casa inicial (ex: A5): ");
        scanf(" %c %d", &col_char, &linha);

        col_index = toupper(col_char) - 'A';
        linha_idx = linha - 1;

        error = 0;
        if (linha_idx < 0 || linha_idx >= tam || col_index < 0 || col_index >= tam) {
            printf("Erro: Fora do tabuleiro!\n");
            error = 1;
        } 
        else if ((op1 == 0 && col_index + 2 >= tam) || 
                 (op1 == 1 && linha_idx + 2 >= tam) || 
                 (op1 == 2 && (linha_idx + 2 >= tam || col_index + 2 >= tam))) {
            printf("Erro: O navio nao cabe nessa direcao!\n");
            error = 1;
        }
    } while (error);

    
    for (int i = 0; i < 3; i++) {
        if (op1 == 0) matriz[linha_idx][col_index + i] = navio;
        else if (op1 == 1) matriz[linha_idx + i][col_index] = navio;
        else if (op1 == 2) matriz[linha_idx + i][col_index + i] = navio;
    }

    imprimirmatriz();

    printf("Escolha uma habilidade:\n");
    printf("0. Cone\n1. Cruz\n2. Octaedro\nEscolha: ");
    scanf("%d", &op2);

    do {
        printf("Escolha a casa alvo para a habilidade (ex: C4): ");
        scanf(" %c %d", &col_char, &linha);
        col_index = toupper(col_char) - 'A';
        linha_idx = linha - 1;

        error = (linha_idx < 0 || linha_idx >= tam || col_index < 0 || col_index >= tam);
        if (error) printf("Erro: Alvo fora do tabuleiro!\n");
    } while (error);

    if (op2 == 0) { // CONE
        aplicar_efeito(linha_idx, col_index); 
        aplicar_efeito(linha_idx + 1, col_index - 1); 
        aplicar_efeito(linha_idx + 1, col_index);
        aplicar_efeito(linha_idx + 1, col_index + 1);
        aplicar_efeito(linha_idx + 2, col_index - 2); 
        aplicar_efeito(linha_idx + 2, col_index - 1);
        aplicar_efeito(linha_idx + 2, col_index);
        aplicar_efeito(linha_idx + 2, col_index + 1);
        aplicar_efeito(linha_idx + 2, col_index + 2);
    } 
    else if (op2 == 1) { // CRUZ
        aplicar_efeito(linha_idx, col_index - 2);
        aplicar_efeito(linha_idx, col_index - 1);
        aplicar_efeito(linha_idx, col_index);
        aplicar_efeito(linha_idx, col_index + 1);
        aplicar_efeito(linha_idx, col_index + 2);
        aplicar_efeito(linha_idx - 1, col_index);
        aplicar_efeito(linha_idx + 1, col_index);
    } 
    else if (op2 == 2) { // OCTAEDRO
        aplicar_efeito(linha_idx - 1, col_index);
        aplicar_efeito(linha_idx, col_index - 1);  
        aplicar_efeito(linha_idx, col_index);      
        aplicar_efeito(linha_idx, col_index + 1);  
        aplicar_efeito(linha_idx + 1, col_index);  
    }

    imprimirmatriz();
}

void regras() {
    printf("\n--- REGRAS ---\n");
    printf("1. Navios ocupam 3 casas.\n");
    printf("2. Habilidades (5) criam areas de efeito no mapa.\n");
    printf("3. O mapa eh 10x10 (A-J, 1-10).\n");
}

void iniciarjogo() {
    int op3 = 0;
    while (op3 != 3) {
        printf("=== BATALHA NAVAL ===\n");
        printf("1. Jogar\n2. Regras\n3. Sair\nEscolha: ");
        
   
        scanf("%d", &op3);

        switch (op3) {
            case 1: posicionar_navio(); break;
            case 2: regras(); break;
            case 3: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n"); break;
        }
    }
}

int main() {
    iniciarjogo();
    return 0;
}
