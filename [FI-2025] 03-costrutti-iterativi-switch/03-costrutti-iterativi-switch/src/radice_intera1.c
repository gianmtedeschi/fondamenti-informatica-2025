#include <stdio.h>

int main() {

    int n; //numero inserito dall'utente
    int radice; //radice intera di n

    printf("\nInserire un numero intero positivo: ");
    scanf("%d", &n);

    radice = n / 2;

    while (radice * radice > n)
        radice--;

    printf("La radice intera di %d e': %d \n", n, radice);

}
