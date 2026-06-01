#include <stdio.h>

int main()
{
    int a = 5;
    int b = 10;

    int *p1 = &a;
    int *p2 = &b;

    printf("Antes:\n");
    printf("p1: %d | p2: %d\n", *p1, *p2);

    // Trocando os valores usando ponteiros
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("\nDepois de inverter:\n");
    printf("p1: %d | p2: %d\n", *p1, *p2);

    return 0;
}
