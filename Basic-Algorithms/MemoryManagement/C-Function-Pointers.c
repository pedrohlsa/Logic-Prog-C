#include <stdio.h>
#include <stdlib.h>

void Saudacao(){
    printf("Olá mundo!");
}

int main(){
    void (*ptr)() = Saudacao;
    
    ptr();
}
