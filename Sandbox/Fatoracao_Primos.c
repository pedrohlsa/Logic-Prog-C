#include <stdio.h>

int main(){
    int num;
    printf("Insert num: ");
    scanf("%d", &num);

    if(num <= 1) {
    printf("Please, insert a number > 1\n"); 
    return 0; 
}

    while(num % 2 == 0){
        printf("%d\n", 2);
        num = num / 2;
    }

    for(int i = 3; i * i <= num; i += 2){
        while(num % i == 0){
            printf("%d\n", i);
            num = num / i;
        }
    }

    if(num > 2){
        printf("%d", num);
    }

    printf("\n");

}
