#include <stdio.h>
#define DIM 100

int main(){
    // Variabili
    int N, v[DIM], i, j;
    
    // Acquisisco l'array
    do {
        printf("Quanti numeri vuoi inserire?: ");
        scanf("%d", &N);
    } while (N < 0 || N > DIM);
    
    for(i = 0; i < N; i++){
        printf("Inserisci l'elemento in posizione %d: ", i);
        scanf("%d", &v[i]);
    }
    
    // Cerco e stampo le coppie di numeri di cui il primo è il doppio del secondo
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(v[i] == 2 * v[j]) printf("%d in posizione %d è il doppio di %d in posizione %d.\n", v[i], i, v[j], j);
        }
    }
    
    return 0;
} 