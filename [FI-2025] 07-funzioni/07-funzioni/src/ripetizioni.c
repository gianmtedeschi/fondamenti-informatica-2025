#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int leggi(int vet[], int dim) {
    int size = 0;
    int num;
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

int elimina_ripetuti(int values[], int dim_v, int single[], int dim_s) {
    int size_s = 0;
    int i, j, trovato;

    for (i=0; i < dim_v && size_s < dim_s; i++) {
        trovato = 0;
        for (j=0; j<size_s && !trovato; j++) {
            if (values[i] == single[j])
                trovato = 1;
        }
        if (!trovato) {
            single[size_s] = values[i];
            size_s++;
        }
    }
    return size_s;
}

int main() {
    int v1[DIM], v2[DIM];
    int dim1 = leggi(v1, DIM);
    int dim2 = elimina_ripetizioni(v1, dim1, v2, DIM);
    
    printf("Elementi non ripetuti:\n");
    for (int i = 0; i < dim2; i++) {
        printf("%d\n", v2[i]);
    }
    
    return 0;
}