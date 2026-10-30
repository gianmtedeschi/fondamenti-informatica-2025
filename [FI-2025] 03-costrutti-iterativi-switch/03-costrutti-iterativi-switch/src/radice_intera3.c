#include <stdio.h>
#include <math.h>

int main() {

    int n; //numero inserito dall'utente
    int radice; // radice intera di n
    printf("\nInserire un numero intero positivo: ");
    scanf("%d",&n);

    radice = sqrt(n);

    printf("La radice intera di %d e': %d \n", n, radice);

    return 0;
}
