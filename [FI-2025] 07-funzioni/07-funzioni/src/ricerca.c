#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int leggi(int vet[], int dim) {
    int size = 0, num;
    do {
        printf("Inserisci un numero: ");
        scanf("%d", &num);
        if (num!=0 && size<dim) {
            vet[size] = num;
            size++;
        }
    } while (num!=0 && size<dim);
    
    return size;
}

void search(int v[], int dim, int k) {
    int found = 0;
    for (int i = 0; i < dim; i++) {
        if (v[i] == k) {
            printf("Trovato %d all'indice %d\n", k, i);
            found = 1;
        }
    }
    if (!found) {
        printf("%d non trovato\n", k);
    }
}

int main() {
    int vettore[DIM];
    int size, k;

    size = leggi(vettore, DIM);
    
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &k);

    search(vettore, size, k);

    return 0;
}