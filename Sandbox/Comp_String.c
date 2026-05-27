#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* sujo;
    char* limpo;
} Sujo;

int main() {
    int total;
    int countLimpo = 0;

    printf("Quantos nomes vai digitar? ");
    scanf("%d", &total);
    getchar(); 

    Sujo *s = malloc(total * sizeof(Sujo));

    for (int i = 0; i < total; i++) {
        s[i].sujo = malloc(50 * sizeof(char));
        s[i].limpo = NULL;

        printf("Nome %d: ", i + 1);
        fgets(s[i].sujo, 50, stdin);
        s[i].sujo[strcspn(s[i].sujo, "\n")] = '\0';

        
        int repetido = 0;
        for (int j = 0; j < countLimpo; j++) {
            
            if (strcmp(s[i].sujo, s[j].limpo) == 0) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            
            s[countLimpo].limpo = malloc(50 * sizeof(char));
            strcpy(s[countLimpo].limpo, s[i].sujo);
            countLimpo++;
        }
    }

    printf("\n--- NOMES ÚNICOS (LIMPOS) ---\n");
    for (int i = 0; i < countLimpo; i++) {
        printf("%d: %s\n", i + 1, s[i].limpo);
    }

    
    for (int i = 0; i < total; i++) {
        free(s[i].sujo);
        if (i < countLimpo) free(s[i].limpo);
    }
    free(s);

    return 0;
}
