#include <stdio.h>

int main(){

    int n, i, primo;

    do {
        printf("Inserire un intero: ");
        scanf("%d" , &n);
    } while(n < 1);

    /*
      Variabile di flag: il suo valore cambia da 1 a 0 quando trovo un
      divisore. Nell'inizializzazione della variabile, assumiamo che
      il numero inserito sia primo.
    */
    primo = 1;

    /*
      Occorre escludere 1 e n perche' dobbiamo considerare solo i
      divisori propri. Quindi iniziamo da 2.
     */
    i = 2;

    /*
      Inutile controllare i numeri da n/2 + 1 a n: non contengono divisori.

      Arresto il ciclo quando la variabile di flag primo diventa 0: è
      inutile cercare altri divisori
    */
    while (i <= n/2 && primo == 1) {
        if (n % i == 0) //se divisore trovato -> numero non primo!
            primo = 0;
        i++;
    }

    /*
      Qui, al termine del ciclo, se primo == 1 vuol dire che non si è
      mai verificato n % i == 0, quindi non esistono divisori propri
      ed n è primo.
    */

    printf("\n%d", n);

    if (primo == 0)
        printf(" non"); // il corpo dell'if è solo quest'istruzione
    printf(" e' primo\n");
}
