#include <stdio.h>

#define DIM 10

void main(){

    //dichiarazioni
    int m[DIM][DIM];
    int i, j, inf, sup;

    //inizializzazione della matrice con valori della tavola pitagorica
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            m[i][j] = (i + 1) * (j + 1);
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }

    //stampa a spirale

    //limite inferiore (e superiore)
    for (inf = 0; inf < DIM / 2; inf++) {
        sup = DIM - inf - 1;

        printf("\n");

        //da sinistra a destra
        for (j = inf; j < sup; j++)
            printf("%2d ", m[inf][j]);

        printf("\n");

        //dall'alto verso il basso
        for (i = inf; i <= sup; i++)
            printf("%2d ", m[i][sup]);

        printf("\n");

        //da destra a sinistra
        for (j = sup - 1; j >= inf; j--)
            printf("%2d ", m[sup][j]);

        printf("\n");

        //dal basso verso l'alto
        for (i = sup - 1; i > inf; i--)
            printf("%2d ", m[i][inf]);

        printf("\n");
    }
}
