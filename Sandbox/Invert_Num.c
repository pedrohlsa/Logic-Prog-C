#include <stdio.h>
#include <string.h>

int main()
{

    char str[100];

    printf("Num: ");
    scanf("%s", str); // como é uma string n precisa de &
    
    int ini = 0;
    int fim = strlen(str) - 1; // tira o \0
    char temp;

    while (ini < fim)
    {
        temp = str[ini];
        str[ini] = str[fim];
        str[fim] = temp;

        ini++;
        fim--;
    }

    printf("\nInvertido: %s\n", str);

    return 0;
}
