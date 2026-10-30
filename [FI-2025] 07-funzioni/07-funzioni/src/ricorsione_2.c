#include <stdio.h>

/* Versione ricorsiva */
int inverti_ric(int n, int rev) {
    if (n == 0)
        return rev; /* Caso base: nessuna cifra rimasta */
    else
        return inverti_ric(n / 10, rev * 10 + (n % 10));
}

/* Funzione di comodo per chiamare la ricorsiva */
int inverti_ricorsivo(int n) {
    return inverti_ric(n, 0);
}

/* Versione iterativa */
int inverti_iterativo(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n = n / 10;
    }
    return rev;
}

int main(void) {
    int n;

    printf("Inserisci un numero intero: ");
    scanf("%d", &n);

    printf("Versione ricorsiva: %d\n", inverti_ricorsivo(n));
    printf("Versione iterativa: %d\n", inverti_iterativo(n));

    return 0;
}
