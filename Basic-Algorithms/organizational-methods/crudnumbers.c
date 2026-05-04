#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int number;
} Challenge;

void cleanBufferEntry() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void insertChallenge(Challenge** c, int *n) {
    int new_qty;
    printf("How many numbers: ");
    if (scanf("%d", &new_qty) != 1) {
        cleanBufferEntry();
        return;
    }
    cleanBufferEntry();

    int old = *n;
    *n += new_qty; 

    *c = (Challenge*)realloc(*c, (*n) * sizeof(Challenge));

    for (int i = old; i < *n; i++) {
        printf("#%d Insert number: ", i + 1);
        scanf("%d", &(*c)[i].number);
        cleanBufferEntry();
    }
}


int comparison(const void *a, const void *b) {
    Challenge *R1 = (Challenge*)a;
    Challenge *R2 = (Challenge*)b;
    return (R1->number - R2->number);
}


void selectionSort(Challenge* c, int n) {
    int i, j;
    Challenge key;
    for (i = 1; i < n; i++) {
        key = c[i];
        j = i - 1;
        while (j >= 0 && c[j].number > key.number) {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = key;
    }
}


int binarySearch(Challenge* c, int n, int target) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (c[meio].number == target) return meio;
        if (c[meio].number > target) fim = meio - 1;
        else ini = meio + 1;
    }
    return -1;
}

void removeChallenge(Challenge** c, int* n) {
    if (*c == NULL) return;
    int target, i, j, found = 0;
    printf("Target to remove: ");
    scanf("%d", &target);
    cleanBufferEntry();

    for (i = 0; i < *n; ) {
        if ((*c)[i].number == target) {
            found = 1;
            for (j = i; j < *n - 1; j++) {
                (*c)[j] = (*c)[j + 1];
            }
            (*n)--;
            if (*n > 0) *c = (Challenge*)realloc(*c, (*n) * sizeof(Challenge));
            else { free(*c); *c = NULL; }
        } else i++;
    }
    if (found) printf("Removed!\n");
    else printf("Not found!\n");
}

int main() {
    Challenge* c = NULL;
    int quantia = 0, op;

    do {
        printf("\n1. Insert | 2. List/Sort | 3. Remove | 0. Exit\nChoose: ");
        if (scanf("%d", &op) != 1) { cleanBufferEntry(); continue; }
        cleanBufferEntry();

        if (op == 1) {
            if (quantia < 20) insertChallenge(&c, &quantia);
            else printf("Full!\n");
        } 
        else if (op == 2) {
            if (c == NULL) { printf("Empty!\n"); continue; }
            int subop;
            do {
                printf("\n1. List | 2. Selection | 3. Qsort | 0. Back\nChoose: ");
                scanf("%d", &subop);
                cleanBufferEntry();

                if (subop == 1) {
                    for (int i = 0; i < quantia; i++) printf("#%d: %d\n", i + 1, c[i].number);
                } 
                else if (subop == 2 || subop == 3) {
                    clock_t t = clock();
                    if (subop == 2) selectionSort(c, quantia);
                    else qsort(c, quantia, sizeof(Challenge), comparison);
                    t = clock() - t;
                    printf("Sorted! Time: %f s\n", (double)t / CLOCKS_PER_SEC);

                    int target;
                    printf("Search for: ");
                    scanf("%d", &target);
                    cleanBufferEntry();
                    int pos = binarySearch(c, quantia, target);
                    if (pos != -1) printf("Found at index %d\n", pos);
                    else printf("Not found!\n");
                }
            } while (subop != 0);
        } 
        else if (op == 3) {
            removeChallenge(&c, &quantia);
        }
    } while (op != 0);

    if (c) free(c);
    return 0;
}
