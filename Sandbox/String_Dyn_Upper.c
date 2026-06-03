#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char *string = (char *)malloc(50 * sizeof(char));

    printf("Digite sua string\n");
    fgets(string, 50, stdin);
    string[strcspn(string,"\n")] = '\0';

    int tamanho = strlen(string);

    for(int i = 0; i < tamanho; i++){
        string[i] = toupper((unsigned char)string[i]);
    }    

    printf("\n%s", string);

    free(string);
    
    return 0;
}
