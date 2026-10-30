#include <stdio.h>

int main() {
    int n, i = 0;
    int y = 0;

    printf("Inserisci un numero intero positivo n: ");
    scanf("%d", &n);

    // versione con ciclo while
    if (n < 0) {
        printf("Errore: n deve essere un intero positivo.\n");
    } else {
        while (i <= n) {
            y = y + i;
            i++;
        }
        printf("La somma da 0 a %d e' %d\n", n, y);
    }

    // versione con ciclo do...while
    if (n < 0) {
        printf("Errore: n deve essere un intero positivo.\n");
    } else {
        do {
            y = y + i;
            i++;
        } while (i <= n);
        printf("La somma da 0 a %d e' %d\n", n, y);
    }

    // versione con ciclo for
    if (n < 0) {
        printf("Errore: n deve essere un intero positivo.\n");
    } else {
        for (i = 0; i <= n; i++) {
            y = y + i;
        }
        printf("La somma da 0 a %d e' %d\n", n, y);
    }

    return 0;
}
