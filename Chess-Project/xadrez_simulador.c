#include <stdio.h>

int main() {
    int opcao1, op2;
    char opcao2, direcao, direcao2, direcao3;

    do {
        printf("\n--- Bem vindo ao jogo de Xadrez ---\n");
        printf("1. Para iniciar o jogo.\n");
        printf("2. Para ler as regras.\n");
        printf("3. Para Sair do jogo.\n");
        printf("O que deseja fazer? ");
        scanf(" %d", &opcao1);

        switch (opcao1) {
            case 1:
                printf("\n--- Escolha sua peca ---\n");
                printf("T. Para Torre\nB. Para Bispo\nR. Para Rainha\n");
                printf("Opcao: ");
                scanf(" %c", &opcao2);

                switch (opcao2) {
                    case 'T': case 't':
                        printf("Voce escolheu a Torre. (R) Reto ou (V) Vertical: ");
                        scanf(" %c", &direcao);
                        if (direcao == 'R' || direcao == 'r'){
                            for (int i = 1; i <= 5; i++) printf("Torre andando para frente %d\n", i);
                        } else {
                            for (int i = 1; i <= 5; i++) printf("Torre andando vertical %d\n", i);
                        }
                        break;
                    case 'B': case 'b':
                        printf("Voce escolheu o Bispo. Movendo em diagonal:\n");
                        for (int i = 1; i <= 5; i++) printf("Bispo na casa %d\n", i);
                        break;
                    case 'R': case 'r':
                        printf("Voce escolheu a Rainha. Movendo em todas as direcoes:\n");
                        for (int i = 1; i <= 5; i++) printf("Rainha na casa %d\n", i);
                        break;
                    default:
                        printf("Peca invalida!\n");
                }
                break;
            case 2:
                printf("\n--- REGRAS ---\nTorre: Reta/Vertical.\nBispo: Diagonais.\nRainha: Todas as direcoes.\n");
                break;
            case 3:
                printf("Fechando o jogo. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao1 != 3);

    return 0;
}
