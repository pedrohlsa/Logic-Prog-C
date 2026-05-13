#include <stdio.h>
#include <string.h>

void inverter_string(char str[]){
    
    printf("Original: %s\n", str);
    
    strrev(str);

    printf("Invertida: %s", str);
}
int main(){
    char nome[] = "Billy da Silva";
    inverter_string(nome);
}
