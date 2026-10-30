#include <stdio.h>

int main() {
    int prezzo;
    int scarto;
    int n_cinquanta;
    int n_venti;
    int n_cinque;

    printf("Inserisci il prezzo: ");
    scanf("%d", &prezzo);

    n_cinquanta = prezzo / 50;
    scarto = prezzo % 50;

    n_venti = scarto / 20;
    scarto = scarto % 20;

    n_cinque = scarto / 5;
    scarto = scarto % 5;

    printf("Banconote da 50: %d\n", n_cinquanta);
    printf("Banconote da 20: %d\n", n_venti);
    printf("Banconote da 5: %d\n", n_cinque);
    printf("Monete: %d\n", scarto);

}
