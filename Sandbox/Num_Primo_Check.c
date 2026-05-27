#include <stdio.h>

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("Numeros menores ou iguais a 1 nao sao primos.\n");
        return 0; 
    }

    int eh_primo = 1;
    int i = 2;       

    while (i < n)
    {
        if (n % i == 0)
        {
            eh_primo = 0; 
            break;        
        }
        i++;
    }

    if (eh_primo)
    {
        printf("O numero %d eh primo.\n", n);
    }
    else
    {
        printf("O numero %d NAO é primo.\n", n);
        printf("Divisores de %d (alem de 1 e dele mesmo): ", n);
        
        for (int j = 2; j < n; j++)
        {
            if (n % j == 0)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
