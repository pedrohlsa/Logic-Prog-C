#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char* nome;
    float* notas;
    int  qtdNotas;
} Estudante;

void addAlunos(Estudante** lista, int* totalAlunos) {
    int novos;
    printf("Quantos alunos adicionar? ");
    scanf("%d", &novos);
    getchar(); 

    
    *lista = (Estudante*) realloc(*lista, (*totalAlunos + novos) * sizeof(Estudante));

    for(int i = 0; i < novos; i++) {
        int index = *totalAlunos + i;
        
        
        (*lista)[index].nome = (char*) malloc(50 * sizeof(char));
        printf("Nome: ");
        fgets((*lista)[index].nome, 50, stdin);
        (*lista)[index].nome[strcspn((*lista)[index].nome, "\n")] = '\0';

        (*lista)[index].notas = NULL; 
        (*lista)[index].qtdNotas = 0;
    }
    *totalAlunos += novos;
}

void addNota(Estudante* lista, int totalAlunos) {
    char busca[50];
    printf("Nome do aluno: ");
    fgets(busca, 50, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for(int i = 0; i < totalAlunos; i++) {
        if(strcmp(lista[i].nome, busca) == 0) {
          
            lista[i].notas = (float*) realloc(lista[i].notas, (lista[i].qtdNotas + 1) * sizeof(float));
            
            printf("Digite a nota: ");
            scanf("%f", &lista[i].notas[lista[i].qtdNotas]);
            lista[i].qtdNotas++;
            return;
        }
    }
    printf("Aluno nao encontrado!\n");
}

void mostrarAlunos(Estudante* lista, int totalAlunos) {
    if (totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalAlunos; i++) {
        printf("\nAluno: %s | Notas: ", lista[i].nome);
        
        if (lista[i].qtdNotas == 0) {
            printf("Sem notas.");
        } else {
            for (int j = 0; j < lista[i].qtdNotas; j++) {
                printf("%.2f ", lista[i].notas[j]);
            }
        }
    }
    printf("\n");
}

void limparMemoria(Estudante* lista, int totalAlunos) {
    for (int i = 0; i < totalAlunos; i++) {
        free(lista[i].nome);  
        if (lista[i].notas != NULL) {
            free(lista[i].notas);
        }
    }
    free(lista); 
    printf("\nMemoria limpa com sucesso!\n");
}

int main() {
    Estudante* lista = NULL;
    int total = 0;
    int opcao;

    do {
        printf("\n1. Add Alunos\n2. Add Nota\n3. Mostrar\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) addAlunos(&lista, &total);
        else if (opcao == 2) addNota(lista, total);
        else if (opcao == 3) mostrarAlunos(lista, total);

    } while (opcao != 0);

    limparMemoria(lista, total);
    return 0;
}
