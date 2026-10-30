#include <stdio.h>

int main() {

    int n, i;

    // ciclo di acquisizione
    do {
        printf("Inserire un intero ");
        scanf("%d" , &n);
    } while(n < 1);

    // soluzione con il ciclo while
    i = 1;
    while(i <= n / 2) {
        if(n % i == 0)
            printf(" %d " , i);

        i++;
    }
}
