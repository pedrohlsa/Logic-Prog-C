#include <stdio.h>

void soma(int n, int m)
{
    int r = n + m;
    printf("O resultado da soma de [%d] + [%d] é: %d\n", n, m, r);
}

void subtracao(int n, int m)
{
    int r = n - m;
    printf("O resultado da subtração de [%d] - [%d] é: %d\n", n, m, r);
}

void multiplicacao(int n, int m)
{
    int r = n * m;
    printf("O resultado da multiplicação de [%d] * [%d] é: %d\n", n, m, r);
}

void divisao(int n, int m)
{
    if (m == 0) {
        printf("Erro: Não existe divisão por zero!\n");
    } else {
        int r = n / m;
        printf("O resultado da divisão de [%d] / [%d] é: %d\n", n, m, r);
    }
}

int main()
{
    printf("\n=========================================\n");
    printf("Bem vindo ao jogo Calculadora com Menu");
    printf("\n=========================================\n");
    
    int op;
    do
    {
        printf("\n=========================================");
        printf("\n1. + | 2. - | 3. * | 4. / | 0. Sair\nEscolha: ");
        scanf("%d", &op);
        printf("=========================================\n");

        if (op == 0) {
            printf("Saindo do programa... Até mais!\n");
            break;
        }

        if (op < 1 || op > 4) {
            printf("Opção inválida! Tente novamente.\n");
            continue; 
        }

        int num1 = 0, num2 = 0;

        printf("Num 1: ");
        scanf("%d", &num1);
        printf("Num 2: ");
        scanf("%d", &num2);

        if (op == 1)
            soma(num1, num2);
        else if (op == 2)
            subtracao(num1, num2);
        else if (op == 3)
            multiplicacao(num1, num2);
        else if (op == 4)
            divisao(num1, num2);

    } while (op != 0);

    return 0;
}
