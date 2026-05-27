#include <stdio.h>
#include <ctype.h>
#include <string.h>

int matriz[3][3];

void impressMatriz()
{
    printf("    A B C\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d   ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void resetMatriz()
{
    memset(matriz, 0, sizeof(matriz));
}

int main()
{

    char letra;
    int op, num;

    do
    {
        impressMatriz();
        printf("\n1. X | 2. Bola | 3. Resetar | 0. Sair | Escolha: ");
        scanf(" %d", &op);
        if (op == 0)
            break;
        if (op == 3)
        {
            resetMatriz();
            impressMatriz();
            printf("\n");
        }

        printf("Onde voce quer colocar ? (EX: A2)\n");
        scanf(" %c %d", &letra, &num);

        int coluna = toupper(letra) - 'A';
        int linha = num - 1;

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3)
        {
            if (matriz[linha][coluna] == 0)

                matriz[linha][coluna] = op;

            else

                printf("Lugar ja ocupado\n");
        }
        else
            printf("Posicao invalida! Excede os limites!\n");

        int ganhou = 0;

        for (int i = 0; i < 3; i++)
        {
            if (matriz[i][0] != 0 && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2])
            {
                ganhou = matriz[i][0]; // n preciso fazer 1 pra coluna e 1 pra linha
            }
            if (matriz[0][i] != 0 && matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i])
            {
                ganhou = matriz[0][i];
            }
        }

        if (matriz[0][0] != 0 && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2])
        {
            ganhou = matriz[1][1];
        }
        if (matriz[0][2] != 0 && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])
        {
            ganhou = matriz[1][1];
        }

        if (ganhou == 1)
        {
            printf("\n--- JOGADOR X GANHOU! ---\n");
            op = 0; // para o jogo
        }
        else if (ganhou == 2)
        {
            printf("\n--- JOGADOR BOLA GANHOU! ---\n");
            op = 0;
        }
    } while (op != 0);
}
