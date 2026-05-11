#include <stdio.h>

void resto(int decimal, int base)
{
    int resto[32];
    int i = 0;
    char hex_letras[] = "0123456789ABCDEF";

    if (decimal == 0)
    {
        printf("0");
    }

    while (decimal > 0)
    {
        resto[i] = decimal % base;
        decimal = decimal / base;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        if (base == 16)
            printf("%c", hex_letras[resto[j]]);
        else
            printf("%d ", resto[j]);
    }
}

int main()
{

    int decimal;
    printf("Insert your decimal number: ");
    scanf("%d", &decimal);

    printf("\nBinario ");
    resto(decimal, 2);
    printf("\nOctal ");
    resto(decimal, 8);
    printf("\nHexadecimal ");
    resto(decimal, 16);

    printf("\n");
}
