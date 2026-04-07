#include <stdio.h>
#include <ctype.h>   
#include <stdbool.h> 

#define colunas 10
#define linhas 10
int matriz[linhas][colunas] = {0}; 

void imprimirmatriz(){
    char cabecario[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("   ");
    for (int i = 0; i < 10; i++){
        printf("%c ", cabecario[i]);
    }
    printf("\n");

    for (int i = 0; i < linhas; i++){
         printf("%2d ", i + 1);
        for (int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void posicionar_navio() {
    char col_char;
    int linha_usuario, col_idx, linha_idx, tamanho = 3;
    
    imprimirmatriz();
    printf("Escolha aonde quer posicionar o seu navio: EX (A 5)\n");
    scanf(" %c %d", &col_char, &linha_usuario); 

    col_idx = toupper(col_char) - 'A'; 
    linha_idx = linha_usuario - 1; 

   
    if (linha_idx >= 0 && linha_idx < 10 && col_idx >= 0 && (col_idx + tamanho) <= 10){
      
        if(matriz[linha_idx][col_idx] == 0 && matriz[linha_idx][col_idx + 1] == 0 && matriz[linha_idx][col_idx + 2] == 0){
            
            
            for(int i = 0; i < tamanho; i++){
                matriz[linha_idx][col_idx + i] = 3;
            }
            
            printf("Navio posicionado com sucesso!\n");
            imprimirmatriz(); 
        } else {
            printf("Ja existe um navio posicionado neste lugar.\n");
        }
    } else {
        printf("Opcao invalida. Coordenada fora do tabuleiro.\n");
    }
}

void regras(){
    printf("\n---As regras do jogo sao:\n");
    printf("1- 0 representa agua e 3 representa os navios.\n");
    printf("2- Cada navio ocupa 3 zeros.\n");
    printf("3- Voce pode posicionar o navio na horizontal.\n");
    printf("4- O oponente posicionara tambem, mas voce nao os vera.\n");
    printf("5- O espaço para posicionar os navios é de 10x10, seja, de 1 ate 10 na vertical, e, 'A' até 'J' na horizontal.");
}

void iniciarjogo(){
    char menu;
    bool sair = false;

    do {
        printf("---Bem vindo ao jogo Batalha Naval!---\n");
        printf("I. Para Iniciar o Jogo.\nR. Para ler as regras.\nS. Para sair do jogo!\n");
        scanf(" %c", &menu); 
        menu = toupper(menu);

        switch (menu) {
            case 'I':
                posicionar_navio(); 
                break;
            case 'R':
                regras(); 
                break;
            case 'S':
                printf("Saindo do jogo!\n");
                sair = true;
                break;
            default:
                printf("Opcao invalida.\n");
        }  
    } while (sair == false);
}

int main (){
    iniciarjogo(); 
    return 0;
}
