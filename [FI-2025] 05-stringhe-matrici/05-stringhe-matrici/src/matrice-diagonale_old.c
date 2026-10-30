#define D 10

#include <stdio.h>

typedef int matrix_t[D][D];

int main() {
    
    matrix_t m;

    int i, j, d;

    //acquisizione dimensione effettiva
    do {
        printf("inserire il numero di righe e colonne\n");
        scanf("%d", &d);
    } while (d < 0 || d > D);

    //lettura valori
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            printf("m[%d][%d] = ", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }

    //scansione lungo la diagonale mentre non ci sono zeri
    for (i = 0; m[i][i] != 0 && i < d; i++);

    //se i < d significa che sono uscito prima dal ciclo
    if (i < d)
        printf("non ");

    printf("diagonale\n");

    return 0;
}
