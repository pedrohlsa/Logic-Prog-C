#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

Node* insertNode(Node* head, const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return head;
    newNode->data = (char*)malloc(strlen(text) + 1);
    if (newNode->data == NULL) { free(newNode); return head; }
    strcpy(newNode->data, text);
    newNode->next = head;
    return newNode;
}

Node* reverseList(Node* head) {
    Node* previous = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next; // salva o prox
        current->next = previous; // inverte dirc q ta apontando
        previous = current;       // move anterior po atual 
        current = nextNode;       // move o atual p salvar
    }
    return previous; //retorna a nova cabeça da lista
}

Node* removeNode(Node* head, const char* text) {
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL && strcmp(current->data, text) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) { printf("Node not found!\n"); return head; }
    if (previous == NULL) head = current->next;
    else previous->next = current->next;
    free(current->data);
    free(current);
    printf("Successfully removed!\n");
    return head;
}

void printList(Node* head) {
    Node* current = head;
    if (current == NULL) { printf("The list is empty.\n"); return; }
    while (current != NULL) {
        printf("- %s\n", current->data);
        current = current->next;
    }
    printf("------------------\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- MENU ---

Node* runMenu(Node* head) {   
    int choice = 0;
    char buffer[100];

    while (choice != 4) {
        printf("\n1. Insert\n2. Remove\n3. List\n4. Exit\nSelection: ");
        if (scanf("%d", &choice) != 1) break;
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter text: ");
                fgets(buffer, 100, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                head = insertNode(head, buffer);
                break;
            case 2:
                printf("Enter text to remove: ");
                fgets(buffer, 100, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                head = removeNode(head, buffer);
                break;
            case 3:
                head = reverseList(head); 
                printList(head);          
                head = reverseList(head); 
                break;
            case 4:
                printf("Exiting...\n");
                freeList(head);
                head = NULL;
                break;
            default:
                printf("Invalid option!\n");
        }
    }
    return head;
}

int main() {
    Node* list = NULL;
    int choice;

    printf("Welcome!\n1. Start\n2. Exit\nSelection: ");
    
    if (scanf("%d", &choice) != 1) return 0;
    clearBuffer();
    if (choice == 1) list = runMenu(list);
    
    return 0;
}
