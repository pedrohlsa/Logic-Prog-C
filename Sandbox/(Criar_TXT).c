#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pont_arq;
    char palavra[20];

    pont_arq = fopen("txt/arquivo_palavra.txt", "w");

    if (pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    printf("Escreva uma palavra para testar gravacao de arquivo: ");
    scanf("%s", palavra);

    fprintf(pont_arq, "%s", palavra);
    fclose(pont_arq);

    printf("Arquivo salvo com sucesso!");

    system("explorer .");
}
