#include <stdio.h>

#define N 10

void main(){

    int v1[N], v2[N], v3[2*N];
    int i;

    //acquisizione dei due vettori in ingresso
    for(i = 0; i < N; i++){
        printf("Inserire il %d valore del primo vettore: ", i+1);
        scanf("%d", &v1[i]); // notare che non c'è check su errori
    }
    for(i = 0; i < N; i++){
        printf("Inserire il %d valore del secondo vettore: ", i+1);
        scanf("%d", &v2[i]);
    }

    //ciclo di inserimento nel vettore in uscita
    for(i = 0; i < N; i++){
        v3[2 * i] = v1[i];
        v3[2 * i + 1] = v2[i];
    }

    //stampa del vettore rislutante
    printf("Vettore risultante: [ ");
    for(i = 0; i < 2 * N; i++){
        printf("%d ", v3[i]);
    }
    printf("]\n");

}
