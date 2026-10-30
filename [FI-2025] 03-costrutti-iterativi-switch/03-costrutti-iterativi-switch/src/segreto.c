#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int segreto;
    int tentativo;

    // imposta seed della funzione rand()
    srand(time(NULL));

    // genera un numero "casuale" fra 1 e 10
    segreto = rand() % 10 + 1;

    do {
        printf ("Indovina il numero (tra 1 e 10): ");
        scanf ("%d",&tentativo);
        if (segreto < tentativo)
            printf("In numero e' piu' basso\n");
        else {
            if (segreto > tentativo)
                printf("In numero e' piu' alto\n");
        }
    } while (segreto!=tentativo);

    printf("Esatto!");
}
