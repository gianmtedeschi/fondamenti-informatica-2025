#include <stdio.h>

void main() {
    int n, i, trovato;

    do {
        printf("Inserire un intero: ");
        scanf("%d" , &n);
    } while(n < 1);

    for (i = n/2; i > 1 && n % i != 0; i--);

    /*
       In alternativa, risolvendo con ciclo while:

       i = n/2;
       while (i > 1 && n % i != 0)
           i--;
     */

    if (i > 1)
        printf("Divisore %d trovato: numero non primo.", i);
    else // vale la condizione i == 1
        printf("Divisore non trovato: numero primo.");
}
