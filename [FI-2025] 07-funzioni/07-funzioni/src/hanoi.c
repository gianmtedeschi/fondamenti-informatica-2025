#include <stdio.h>

/* 
 * n  = numero di dischi
 * from = asta di partenza
 * to   = asta di destinazione
 * aux  = asta di appoggio
 */

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        /* Caso base: sposta un solo disco */
        printf("Sposta il disco 1 da %c a %c\n", from, to);
    } else {
        /* Sposta n-1 dischi dalla sorgente all’asta di appoggio */
        hanoi(n - 1, from, aux, to);

        /* Sposta il disco più grande dalla sorgente alla destinazione */
        printf("Sposta il disco %d da %c a %c\n", n, from, to);

        /* Sposta n-1 dischi dall’asta di appoggio alla destinazione */
        hanoi(n - 1, aux, to, from);
    }
}

int main() {
    int n;

    printf("Inserisci il numero di dischi: ");
    scanf("%d", &n);

    printf("\nSoluzione per %d dischi:\n", n);
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
