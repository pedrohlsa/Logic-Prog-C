#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *pont_arq;
    char name[20];

    pont_arq = fopen("txt/arquivo_palavra.txt", "a");

    if (pont_arq == NULL)
    {
        printf("Erro ao acessar ao arquivo.");
        return 1;
    }

    printf("Digite o que voce quer inserir na pasta:\n");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';

    fprintf(pont_arq, "%s \n", name);
    fclose(pont_arq);

    printf("Arquivo salvo com sucesso!");

    system("explorer .");
}
