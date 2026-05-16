#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverter(char *str)
{   
    int pali = 1;
    char *inicio = str;
    char *fim = str + strlen(str) - 1;

    while (inicio < fim)
    {
        if(*inicio != *fim){
            pali = 0; // se algum caracterer for diferente ja deixa 0;
        }
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }

    return pali;
}

int main()
{
    char *str;

    str = (char *)malloc(50 * sizeof(char));

    printf("Digite a string q deseja inverter: ");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';

    int pali = inverter(str);
    printf("Palavra invertida: %s | pali? %s", str, pali ? "eh pali" : "nao eh pali");

    free(str);
    return 0;
}
