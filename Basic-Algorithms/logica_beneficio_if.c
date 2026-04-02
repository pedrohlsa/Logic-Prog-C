#include <stdio.h>

int main (){
    int idade, renda, dependente;

    printf("Idade: "); scanf("%d", &idade);
    printf("Renda: "); scanf("%d", &renda);
    printf("Dependentes: "); scanf("%d", &dependente);

    if(idade >= 18 && idade < 65) {
        if(renda < 3000) {
            if (dependente > 2) {
                printf("Criterio atendido! Beneficio liberado.\n");
            } else {
                printf("Negado: Poucos dependentes.\n");
            }
        } else {
            printf("Negado: Renda acima do limite.\n");
        }
    } else {
        printf("Negado: Fora da faixa de idade.\n");
    }
    return 0;
}
