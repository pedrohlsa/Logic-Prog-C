#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 50

typedef struct {
    char* name;
    int stock;    
    float price;  
} Product;         

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addProducts(Product** p, int* qty) {
    int new_items;
    printf("\nHow many products to add? ");
    if (scanf("%d", &new_items) != 1) return;
    cleanBuffer();

    int old_qty = *qty;
    *qty += new_items;

    // realloc pq vou estar alterando toda hora o tamanho da struct
    *p = (Product*)realloc(*p, (*qty) * sizeof(Product));
    
    for (int i = old_qty; i < *qty; i++) {
        // malloc pro nome, afinal nesse programa nao iremos alterar o nome dele.
        (*p)[i].name = (char*) malloc(MAX_CHARS * sizeof(char));
        (*p)[i].stock = 0;
        (*p)[i].price = 0.0; // importante comecar no 0.

        printf("Product #%d name: ", i + 1);
        fgets((*p)[i].name, MAX_CHARS, stdin);
        (*p)[i].name[strcspn((*p)[i].name, "\n")] = '\0';        
    }
}

// Função nova pra mexer no dindin
void updatePrice(Product* p, int qty) {
    char buffer[MAX_CHARS];
    printf("\nEnter product name to update price: ");
    fgets(buffer, MAX_CHARS, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    for (int i = 0; i < qty; i++) {
        if (strcasecmp(p[i].name, buffer) == 0) {
            printf("Current price for [%s]: $%.2f\n", p[i].name, p[i].price);
            printf("New price: ");
            scanf("%f", &p[i].price);
            cleanBuffer();
            return;
        }
    }
    printf("Product not found!\n");
}

void updateStock(Product* p, int qty) {
    char buffer[MAX_CHARS];
    printf("\nEnter product name to update stock: ");
    fgets(buffer, MAX_CHARS, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    for (int i = 0; i < qty; i++) {
        if (strcasecmp(p[i].name, buffer) == 0) {
            printf("Current stock for [%s]: %d\n", p[i].name, p[i].stock);
            printf("New stock quantity: ");
            scanf("%d", &p[i].stock);
            cleanBuffer();
            return;
        }
    }
    printf("Product not found!\n");
}

void listProducts(Product* p, int qty) {
    printf("\n--- CURRENT INVENTORY ---\n");
    for (int i = 0; i < qty; i++) {
        printf("ID: %02d | Name: %-15s | Stock: %3d | Price: $ %7.2f\n", 
                i + 1, p[i].name, p[i].stock, p[i].price);
    }
}

void calculateStockValue(Product* p, int qty) {
    float total_inventory = 0;

    printf("\n--- STOCK VALUE ANALYSIS ---\n");
    for (int i = 0; i < qty; i++) {
        float subtotal = p[i].stock * p[i].price;
        total_inventory += subtotal;

        printf("Product: %-15s | Qty: %3d | Price: $ %7.2f | Subtotal: $ %10.2f\n", 
                p[i].name, p[i].stock, p[i].price, subtotal);
    }
    printf("---------------------------------------------------------------------\n");
    printf("TOTAL INVENTORY VALUE: $ %.2f\n", total_inventory);
    printf("---------------------------------------------------------------------\n");
}

int main() {
    Product* p = NULL;
    int qty = 0;
    int option = -1;

    while (option != 0) {
        // Importante usar o 0 para salvar os produtos!
        printf("\n1. Add | 2. Update Stock | 3. Update Price | 4. List | 5. Value | 0. Save & Exit\nChoice: ");
        if (scanf("%d", &option) != 1) break;
        cleanBuffer();

        if (option == 1) addProducts(&p, &qty);
        else if (option == 2) updateStock(p, qty);
        else if (option == 3) updatePrice(p, qty); 
        else if (option == 4) listProducts(p, qty);
        else if (option == 5) calculateStockValue(p, qty);
    }

    // "w" abre pra escrever. Se o arquivo não existir, ele cria. Se existir, ele LIMPA e começa denovo. (Se atentar ao LIMPA). 
    FILE* file = fopen("txt/products.txt", "w");
    if (file) {
        for (int i = 0; i < qty; i++) {
            // escreve no arquivo 
            fprintf(file, "Product: %s | Stock: %d | Price: %.2f\n", 
                    p[i].name, p[i].stock, p[i].price);
            free(p[i].name); // Libera o nome aqui pra economizar loop dps
        }
        fclose(file); // Se não fechar o arquivo, os dados ficam na memoria e nao sao salvos.
        free(p);
        printf("Inventory saved to products.txt. Goodbye!\n");
    } else {
        // Se n abrir o arquivo, ainda tem que dar free na memória pra não dar leak
        if(p != NULL){
            for(int i = 0; i < qty; i++) free(p[i].name);
            free(p);
        }
    }

    system("explorer .");
    return 0;
}
