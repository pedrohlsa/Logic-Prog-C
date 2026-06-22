#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu(char** mail, int* password, int* token) {
    char buffer[255];

    printf("Insert your email: ");
    fgets(buffer, 255, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    int size = strlen(buffer);
    *mail = (char*) malloc((size + 1) * sizeof(char));
    strcpy(*mail, buffer);
    
    printf("Insert your password: ");
    scanf("%d", password);
    cleanBuffer();

    printf("If you are admin, insert your token, otherwise insert 0: ");
    scanf("%d", token);
    cleanBuffer();
}

bool check(int token) {
    if (token == 12345) {
        return true;
    }
    return false;
}

void welcome(bool isAdmin) {
    printf("\n=== LOGIN SYSTEM ===\n");
    if (isAdmin) {
        printf("Welcome, admin!\n");
    } else {
        printf("Welcome, user!\n");
    }
}

int main() {
    char* mail = NULL;
    int senha = 0;
    int token = 0;

    bool isAdmin = false;

    menu(&mail, &senha, &token);
    
    if (token != 0) {
        isAdmin = check(token);
    }
    
    welcome(isAdmin);

    if (mail != NULL) {
        free(mail);
    }

    return 0;
}
