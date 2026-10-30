#include <stdio.h>

int main() {
    int n, m, a, b, resto, MCD, mcm;

    /* Acquisizione con controllo di validità */
    do {
        printf("Inserire n = ");
        scanf("%d", &n);

        printf("Inserire m = ");
        scanf("%d", &m);

    } while (n < 1 || m < 1);
    /* Si ripete finché almeno uno dei due è non positivo */

    /* Salviamo i valori originali per il calcolo dell'mcm */
    a = n;
    b = m;

    /* Algoritmo di Euclide per l'MCD */
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    MCD = a;
    mcm = (n * m) / MCD;     

    printf("L'MCD di %d e %d e' %d\n", n, m, MCD);
    printf("Il m.c.m. di %d e %d e' %d\n", n, m, mcm);

    return 0;
}
