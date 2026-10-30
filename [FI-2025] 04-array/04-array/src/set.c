#include <stdio.h>

#define MAX_LEN 100

int main(){

    int n;
    int lista[MAX_LEN];
    int insieme[MAX_LEN];
    int lungh_ins;
    int i,j;
    int trovato;

    //chiedo all'utente quanti elementi vuole inserire
    do {
        printf("Inserire il numero degli elementi da inserire: ");
        scanf("%d", &n);
    } while ( n < 0 || n > 100);

    //ciclo di acquisizione degli elementi
    for (i = 0; i < n; i++) {
            printf("Inserire il %do numero : ", i+1);
            scanf("%d", &lista[i]);
    }

    //scorro gli elementi in lista ed inserisco in insieme
    lungh_ins = 1;
    insieme[0] = lista[0];
    for (i = 1; i < n; i++) {
        //controllo se l'elemento � gi� in insieme
        trovato = 0;
        for (j = 0; j < lungh_ins; j++)
            if (lista[i] == insieme[j])
                trovato = 1;
        //se non � ripetuto insrisco
        if (!trovato) {
            insieme[lungh_ins] = lista[i];
            lungh_ins++;
        }
    }

    //stampa degli elementi dell'insieme
    printf("[ ");
    for (i = 0; i < lungh_ins;i++)
        printf("%d ",insieme[i]);
    printf("]\n");

}
