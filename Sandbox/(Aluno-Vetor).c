#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CARACTERES 100
#define MAX_ALUNOS 3

typedef struct
{
    char nomeAluno[CARACTERES];
    int nota, nota2, nota3;
    float media;
} Aluno;

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void inserirAluno(Aluno *list)
{
    printf("\n--- REGISTRATION PAGE ---\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("\nStudent #%d\n", i + 1);
        printf("Name: ");
        fgets(list[i].nomeAluno, CARACTERES, stdin);
        list[i].nomeAluno[strcspn(list[i].nomeAluno, "\n")] = '\0';

        printf("Note 1: ");
        scanf("%d", &list[i].nota);
        cleanBuffer();

        printf("Note 2: ");
        scanf("%d", &list[i].nota2);
        cleanBuffer();

        printf("Note 3: ");
        scanf("%d", &list[i].nota3);
        cleanBuffer();

        list[i].media = (list[i].nota + list[i].nota2 + list[i].nota3) / 3.0;
    }
    printf("\n[SUCCESS] All students registered!\n");
}

void showStudents(Aluno *list)
{
    printf("\n--- STUDENT LIST ---\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strlen(list[i].nomeAluno) > 0)
        {
            printf("ID: %d | Name: %-15s | Media: %.2f\n", i + 1, list[i].nomeAluno, list[i].media);
        }
    }
}

void biggerNote(Aluno *list)
{
    int best = 0;
    for (int i = 1; i < MAX_ALUNOS; i++)
    {
        if (list[i].media > list[best].media)
            best = i;
    }
    printf("\nTOP STUDENT: %s (Media: %.2f)\n", list[best].nomeAluno, list[best].media);
}

void worstNote(Aluno *list)
{
    int worst = 0;
    for (int i = 1; i < MAX_ALUNOS; i++)
    {
        if (list[i].media < list[worst].media && strlen(list[i].nomeAluno) > 0)
            worst = i;
    }
    printf("\nLOWEST PERFORMANCE: %s (Media: %.2f)\n", list[worst].nomeAluno, list[worst].media);
}

void averageNote(Aluno *list)
{
    float soma = 0;
    int cont = 0;
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strlen(list[i].nomeAluno) > 0)
        {
            soma += list[i].media;
            cont++;
        }
    }
    printf("\nCLASS GENERAL AVERAGE: %.2f\n", (cont > 0) ? soma / cont : 0);
}

void studentStatus(Aluno *list, int passed)
{
    printf(passed ? "\n--- PASSED STUDENTS ---\n" : "\n--- FAILED STUDENTS ---\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strlen(list[i].nomeAluno) > 0)
        {
            if (passed && list[i].media >= 7)
            {
                printf("Name: %-15s | Media: %.2f\n", list[i].nomeAluno, list[i].media);
            }
            else if (!passed && list[i].media < 7)
                printf("Name: %-15s | Media: %.2f\n", list[i].nomeAluno, list[i].media);
        }
    }
}

void status(Aluno *list)
{
    int Pass = 0;
    int NotPass = 0;
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strlen(list[i].nomeAluno) > 0)
        {
            if (list[i].media >= 7)
                Pass++;
            else
                NotPass++;
        }
    }
    printf("\n-> Pass: %d | Not: %d\n", Pass, NotPass);
}

int main()
{
    // inicializa a lista com zeros para evitar lixo de memória
    Aluno list[MAX_ALUNOS] = {0};
    int op;

    do
    {
        printf("\n======================================\n");
        printf("          ACADEMIC SYSTEM            \n");
        printf("======================================\n");
        printf("1. Insert | 2. Show All | 3. Best | 4. Worst\n");
        printf("5. Average | 6. Passed | 7. Failed | 8. Status | 0. Exit\n");
        printf("Choose: ");

        if (scanf("%d", &op) != 1)
        {
            cleanBuffer();
            continue;
        }
        cleanBuffer();

        switch (op)
        {
        case 1:
            inserirAluno(list);
            break;
        case 2:
            showStudents(list);
            break;
        case 3:
            biggerNote(list);
            break;
        case 4:
            worstNote(list);
            break;
        case 5:
            averageNote(list);
            break;
        case 6:
            studentStatus(list, 1);
            break;
        case 7:
            studentStatus(list, 0);
            break;
        case 8:
            status(list);
            break;
        case 0:
            printf("Bye bye!\n");
            break;
        default:
            printf("Invalid option!\n");
        }
    } while (op != 0);

    return 0;
}
