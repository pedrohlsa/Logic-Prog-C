#include <stdio.h>

int main (){
    int opcao;
    float nota1, nota2, nota3, media;

    do {
        printf("\n--- Sistema Escolar ---\n");
        printf("1. Inserir Notas / 2. Ver Media / 3. Sair\n");
        scanf("%d", &opcao);

        switch ( opcao ){
            case 1:
                printf("Digite as 3 notas: ");
                scanf("%f %f %f", &nota1, &nota2, &nota3);
                break;
            case 2: 
                media = (nota1 + nota2 + nota3) / 3.0f;
                printf("Media final: %.1f - %s\n", media, (media >= 6) ? "APROVADO" : "REPROVADO");
                break;
            case 3:
                printf("Saindo...");
                break;
        }
    } while (opcao != 3); 
   
    return 0;
}
