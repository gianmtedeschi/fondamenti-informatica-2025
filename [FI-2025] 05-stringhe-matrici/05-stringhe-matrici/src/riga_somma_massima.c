#include <stdio.h>
#define DIM_R 2
#define DIM_C 3

int main(){
    //dichiarazioni
    int M[DIM_R][DIM_C];
    int i, j;
    int somma, max, i_max;
    //acquisizione
    printf("\n");
    for(i = 0; i < DIM_R; i++){
        for(j = 0; j < DIM_C; j++){
            printf("Inserire cella (%d,%d): ", i + 1, j + 1);
            scanf("%d", &M[i][j]);
        }
    }
    //stampa matrice
    printf("\nM = \n");
    for(i = 0; i < DIM_R; i++){
        printf("[ ");
        for(j = 0; j < DIM_C; j++){
            printf("%d ", M[i][j]);
        }
        printf("]\n");
    }
    //calcolo massimo somma sulle righe
    max = 0;
    i_max = -1;
    for(i = 0; i < DIM_R; i++){
        somma = 0;
        for(j = 0; j < DIM_C; j++){
            somma = somma + M[i][j];
        }
        if(somma > max){
            max = somma;
            i_max = i;
        }
    }
    //stampa risultato
    printf("\nLa somma massima e' %d, alla riga %d\n\n", max, i_max + 1);
}
