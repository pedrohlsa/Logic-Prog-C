#include <stdio.h>

int main()
{
    int value;
    printf("Insert your number: ");
    scanf(" %d", &value);

    int nota100, nota50, nota20, nota10, nota5, nota2, moeda1, resto;

    nota100 = value / 100;
    resto = value % 100;

    nota50 = resto / 50;
    resto = resto % 50;

    nota20 = resto / 20;
    resto = resto % 20;

    nota10 = resto / 10;
    resto = resto % 10;

    nota5 = resto / 5;
    resto = resto % 5;

    nota2 = resto / 2;
    resto = resto % 2;

    moeda1 = resto / 1;
    resto = resto % 1;

    printf("\n");

    if (nota100 > 0)
        printf("%d de nota(s) de 100\n", nota100);
    if (nota50 > 0)
        printf("%d de nota(s) de 50\n", nota50);
    if (nota20 > 0)
        printf("%d de nota(s) de 20\n", nota20);
    if (nota10 > 0)
        printf("%d de nota(s) de 10\n", nota10);
    if (nota5 > 0)
        printf("%d de nota(s) de 5\n", nota5);
    if (nota2 > 0)
        printf("%d de nota(s) de 2\n", nota2);
        if (moeda1 > 0)
        printf("%d de moeda(s) de 1\n", moeda1);
}
