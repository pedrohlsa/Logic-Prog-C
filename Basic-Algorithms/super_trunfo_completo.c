#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char pais[30], pais2[30];
    int populacao, pontos, populacao2, pontos2, opcao, opcao2, opcao3;
    int placar = 0, placar2 = 0; 
    float area, pib, densidade, pibpercapita, area2, pib2, densidade2, pibpercapita2;

    printf("--- Bem vindo ao jogo Super-Trunfo! ---\n");
    printf("1. Iniciar o jogo / 2. Regras / 3. Sair\n");
    scanf("%d", &opcao);

    if(opcao == 1) {
        // Cadastro País 1
        printf("Nome do País 1: "); scanf(" %[^\n]", pais);
        printf("Populacao: "); scanf("%d", &populacao);
        printf("Area: "); scanf("%f", &area);
        printf("PIB: "); scanf("%f", &pib);
        printf("Pontos Turisticos: "); scanf("%d", &pontos);

        // Cadastro País 2
        printf("\nNome do País Rival: "); scanf(" %[^\n]", pais2);
        printf("Populacao: "); scanf("%d", &populacao2);
        printf("Area: "); scanf("%f", &area2);
        printf("PIB: "); scanf("%f", &pib2);
        printf("Pontos Turisticos: "); scanf("%d", &pontos2);

        densidade = (float)populacao / area;
        pibpercapita = pib / (float)populacao;
        densidade2 = (float)populacao2 / area2;
        pibpercapita2 = pib2 / (float)populacao2;

        printf("\n1. Duelo Geral\n");
        scanf("%d", &opcao2);

        if(opcao2 == 1) {
            if (populacao > populacao2) placar++; else placar2++;
            if (area > area2) placar++; else placar2++;
            if (pib > pib2) placar++; else placar2++;
            if (densidade < densidade2) placar++; else placar2++; // Menor vence

            printf("\nRESULTADO FINAL:\n%s: %d | %s: %d\n", pais, placar, pais2, placar2);
            if(placar > placar2) printf("Vitoria do %s!\n", pais); else printf("Vitoria do %s!\n", pais2);
        }
    }
    return 0;
}
