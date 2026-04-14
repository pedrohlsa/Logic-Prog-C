#include <stdio.h>
#include <stdlib.h>

void vetor(){
    // o melhor, basicamente voce pede ao sistema a quantidade que voce precisa 
    // e QUANDO precisa.
    // tres ferramentas principais.

    // malloc()memory allocation // aloca quantia de memoria que pedir em bytes.
    int *v1 =(int*)malloc(5 *sizeof(int)); 
    // sizeof basicamente os bytes de um inteiro certinho
    // te aluga um ponteiro de acordo com o tamanho que pediu
    // te da o espaco, mas nao limpa oq tem

    //calloc() clear allocation
    // auto explicativo, te da um espaco limpo
    int *v2 =(int*)calloc(5, sizeof(int));
    if (v2 == NULL) return;
    // com uma vantagem, limpa o espaco pra mim, iniciando os bytes com 0
    // te da o espaco, e garante que ESTA LIMPO e vazio.
    // mais seguro caso queira que os dados comecem com o valor 0.

    //free(liberacao de memoria)
    // depois q terminar de usar a memoria q pediu emprestada
    // a funcao free limpa o armario pra mandar de volta para o sistema
    // EXTREMAMENTE NECESSARIO! Caso nao seja usado para devolver
    // trava o programa, porque vai ficar ocupando um "lixo" na memoria
    free(v1);
    free(v2);

    int *a, b;
    b =10;

    a = (int*)malloc(sizeof(int)); // reservando espaco!
    *a = 20; // endereco de mem A recebe valor 20;

    a = &b; // referencia do espaco alocado perdida.
    free(a); // ta limpando o que ? nada, ja que agora o endereco de A é o mesmo da B.
    //***jeito certo***// 
    free(a); // limpando o espaco alocado
    a = &b; // agora sim, espaco A ja limpo, recebe o mesmo endereco de B.

    // tomar cuidado com isso, possivel vazamento de memoria, lentidao e instabilidade no programa.
}

void teste()
{
    int *a, b;

    a = (int*)malloc(sizeof (int));

    b = 20;
    *a = 10;

    free(a);
    a = &b;

    printf("end de b %p\n", (void*)&b);
    printf("end de a %p\n", (void*)a);
    printf("Valor de A atual: %d", *a);
}

int main()
{
    teste();
}
