#include <stdio.h>

#define MAX_LEN 10

int main(){

    int pari[MAX_LEN];
    int dispari[MAX_LEN];
    int n_val;
    int i, valore;
    int n_pari = 0, n_disp = 0;

    //chiedo all'utente quanti valori intende immettere
    do{
        printf("Inserire il numero di valori da considerare: ");
        scanf("%d", &n_val);
    }while(n_val < 1 || n_val > MAX_LEN);

    //ciclo di acquisizione dei valori
    for (i = 0; i < n_val; i++) {
        printf("Inserire il %do valore: ", i+1);
        scanf("%d", &valore);
        //controllo se pari o dispari
        if (valore % 2 == 0) {
            pari[n_pari] = valore;
            n_pari++;
        }
        else {
            dispari[n_disp] = valore;
            n_disp++;
        }
    }

    //stampa dell'array pari
    printf("Numeri pari: ");
    for (i = 0; i < n_pari; i++) {
        printf("%d ",pari[i]);
    }
    printf("\n");

    //stampa dell'array dispari
    printf("Numeri dispari: ");
    for (i = 0; i < n_disp; i++) {
        printf("%d ",dispari[i]);
    }
    printf("\n");

}
