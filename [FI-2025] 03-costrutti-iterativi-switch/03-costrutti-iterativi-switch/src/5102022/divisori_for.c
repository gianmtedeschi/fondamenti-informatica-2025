#include <stdio.h>

void main() {

    int n, i;

    // ciclo di acquisizione
    do {
        printf("Inserire un intero ");
        scanf("%d" , &n);
    } while(n < 1);

     // soluzione con il ciclo for
    for(i = 1; i <= n / 2; i++)
        if(n % i == 0)
            printf(" %d ", i);

}
