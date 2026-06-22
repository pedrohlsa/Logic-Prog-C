#include <stdio.h>
#include <string.h>

int main()
{
    int cont = 0;

    char str[] = "OIIIIIIIIIII";

    int tamanho = strlen(str);

    for (int i = 0; i < tamanho; i++)
    {
        if (str[i] == 'I')
            cont++;
    }

    printf("A quantia de I é: %d", cont);

    return 0;
}
