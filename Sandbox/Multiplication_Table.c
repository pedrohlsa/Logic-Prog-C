#include <stdio.h>

void multiplicationTable() {
    int num, limit;
    
    printf("Enter the number for the table: ");
    scanf("%d", &num);

    printf("Enter the limit (how far it should go): ");
    scanf("%d", &limit);

    printf("\n=== MULTIPLICATION TABLE FOR %d (Up to %d) ===\n", num, limit);
  
    for (int i = 1; i <= limit; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int main() {
    multiplicationTable();
    return 0;
}
