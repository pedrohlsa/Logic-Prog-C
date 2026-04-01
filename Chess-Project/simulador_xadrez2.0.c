#include <stdio.h>
#include <stdbool.h>

void movercasas(int casas);
void movtorre();
void movbispo();
void movrainha();
void iniciarjogo();
void menu();
void regras();

void menu() 
{
    printf("\n--- Bem vindo ao jogo ---\n");
    printf("I. Para Iniciar o jogo.\n");
    printf("R. Para as ver as Regras do jogo.\n");
    printf("S. Para sair do jogo.\n");
}

void regras() 
{
    printf("\n--- Essas sao as regras ---\n");
    printf("A torre se move em linha reta.\n");
    printf("O bispo se move na diagonal.\n");
    printf("A rainha se move em todas as direcoes.\n");
}

void movercasas(int casas) 
{
    
    if (casas > 0) 
    {
        for (int i = 1; i <= casas; i++) 
        {
            printf("%d.. ", i);
        }
        printf("\n");
    }
}

void movtorre() 
{
    char mov;
    printf("Voce escolheu a torre, (E) para esquerda (D) para direita: ");
    
    scanf(" %c", &mov);
    
    if (mov == 'D' || mov == 'd') 
    {
        printf("Voce escolheu direita.\n");
    } 
    else 
    {
        printf("Voce escolheu esquerda.\n");
    }
    movercasas(3); 
}

void movbispo() 
{
    char mov_b, mov_diag;
    printf("Voce escolheu o bispo, (D) para diagonal ou (R) para reto: ");
    scanf(" %c", &mov_b);
    
    if (mov_b == 'R' || mov_b == 'r') 
    {
        printf("Voce escolheu ir Reto.\n");
    } 
    else 
    {
        printf("Voce escolheu ir na Diagonal. (D) para direita, (E) para esquerda: ");
        scanf(" %c", &mov_diag);

        if (mov_diag == 'D' || mov_diag == 'd') 
        {
            printf("Voce escolheu ir com o Bispo para Direita.\n");
        } 
        else 
        {
            printf("Voce escolheu ir com o Bispo para Esquerda.\n");
        }
    }
    movercasas(3);
}

void movrainha() 
{
    char mov_r, mov_d, mov_l;
    printf("Rainha: (R) reto, (D) diagonal, (S) tras, (L) lado: ");
    
    scanf(" %c", &mov_r); 

    if (mov_r == 'R' || mov_r == 'r') 
    {
        printf("Voce escolheu ir reto.\n");
    } 
    else if (mov_r == 'D' || mov_r == 'd') 
    {
        printf("Diagonal: (E) esquerda ou (D) direita: ");
        scanf(" %c", &mov_d);
        if (mov_d == 'E' || mov_d == 'e') 
        {
            printf("Movendo para Esquerda.\n");
        } 
        else 
        {
            printf("Movendo para Direita.\n");
        }
    } 
    else if (mov_r == 'S' || mov_r == 's') 
    {
        printf("Voce escolheu ir para tras.\n");
    } 
    else if (mov_r == 'L' || mov_r == 'l') 
    {
        printf("Lado: (D) direita ou (E) esquerda: ");
        
        scanf(" %c", &mov_l); 
        if (mov_l == 'D' || mov_l == 'd') 
        {
            printf("Lado Direito.\n");
        } 
        else 
        {
            printf("Lado Esquerdo.\n");
        }
    } 
    else 
    {
        printf("Opcao invalida.\n");
    }
    movercasas(7);
}

void iniciarjogo() 
{
    char mov;
    printf("\n--- Voce iniciou o jogo ---\n");
    printf("T. Torre | B. Bispo | R. Rainha: ");

    scanf(" %c", &mov); 

    if (mov == 'T' || mov == 't') 
    {
        movtorre();
    } 
    else if (mov == 'B' || mov == 'b') 
    {
        movbispo();
    } 
    else if (mov == 'R' || mov == 'r') 
    {
        movrainha();
    } 
    else 
    {
        printf("Peca invalida.\n");
    }
}

int main() 
{
    bool gameOver = false;
    char op1;
    
    do 
    {
        menu();
        scanf(" %c", &op1);

        switch (op1) 
        {
            case 'I':
            case 'i': 
                iniciarjogo(); 
                break;

            case 'R':
            case 'r':
                regras();
                break;

            case 'Q':
            case 'q':
            case 'S':
            case 's':
                printf("Saindo do jogo...\n");
                gameOver = true; 
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (!gameOver);

    return 0;
}
