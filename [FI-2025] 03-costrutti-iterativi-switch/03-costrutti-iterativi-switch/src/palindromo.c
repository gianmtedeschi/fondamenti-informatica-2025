#include <stdio.h>

int main(void) {
    int n, originale, invertito, cifra;

    /* Acquisizione e validazione */
    do {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Il numero deve essere positivo.\n");
        }
    } while (n < 0);

    originale = n;
    invertito = 0;

    /* Calcolo del numero invertito */
    while (n > 0) {
        cifra = n % 10;     /* Prendo l’ultima cifra */
        invertito = invertito * 10 + cifra; /* Aggiungo la cifra in fondo al numero invertito */
        n = n / 10;     /* Rimuovo l’ultima cifra */
    }

    /* Verifica */
    if (originale == invertito) {
        printf("%d è un numero palindromo.\n", originale);
    } else {
        printf("%d non è un numero palindromo.\n", originale);
    }

    return 0;
}
