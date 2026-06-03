#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    int ValorA = **(int **)a;
    int ValorB = **(int **)b;

    return (ValorA - ValorB);
}

int main()
{
    int valores[] = {50, 30, 10, 20, 40};
    int n = 5;

    int *ptr[n];

    for (int i = 0; i < n; i++)
    {
        ptr[i] = &valores[i];
    }

    qsort(ptr, n, sizeof(int *), comp);

    printf("Originais: ");
    for (int i = 0; i < n; i++)
        printf("%d ", valores[i]);

    printf("\nOrdenado via Pointers: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *ptr[i]);

    return 0;
}
