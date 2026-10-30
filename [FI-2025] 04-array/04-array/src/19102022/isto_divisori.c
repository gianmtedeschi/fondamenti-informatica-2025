#include <stdio.h>

#define LEN_DIVI 50
#define N_MAX 50

void main(){

    int numeri[N_MAX];
    int divisori[LEN_DIVI];
    int maxi = -1;
    int n_val = -1;
    int i,j;

    //chiedo all'utente quanti valori intende immettere
    while (n_val < 1 || n_val > N_MAX){
        printf("Inserire il numero di valori da considerare: ");
        scanf("%d",&n_val);
    }

    // Inizializzazione divisori
    for (i = 0; i < LEN_DIVI; i++)
        divisori[i] = 0;

    for (i = 0; i < n_val; i++) {
        //acquisizione di un valore
        do {
            printf("Inserire il %do valore: ",i+1);
            scanf("%d",&numeri[i]);
        } while (numeri[i] <= 0);
        //aggiornamento del massimo
        if (numeri[i] > maxi)
            maxi = numeri[i];
        //calcolo istogramma
        for (j = numeri[i] / 2; j > 1; j--)
            if (numeri[i] % j == 0)
                divisori[j-1]++;
    }

    //stampa istogramma
    for (i = 1; i < maxi / 2; i++) {
        printf("%d\t| ",i+1);
        for (j = 0; j < divisori[i]; j++)
            printf("*");
        printf("\n");
    }

}
