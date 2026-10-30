#include <stdio.h>

#define DIM 10

int main() {
    int num, size, i;
    int values[DIM];
    size = 0;

    // Inserimento 
    do {
        printf("Inserisci un numero:");
        scanf("%d", &num);
        if (num>0 && size<DIM) {
            values[size] = num;
            size++;
        }
    } while (num!=0 && size<DIM);

    // Stampa condizionata
    for (i=0; i<size; i++){
        if (values[i] == i)
            printf("%d ", values[i]);
    }

    return 0;
}