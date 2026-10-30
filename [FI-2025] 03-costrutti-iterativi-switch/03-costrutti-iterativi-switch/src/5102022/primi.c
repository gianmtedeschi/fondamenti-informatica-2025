#include <stdio.h>

void main(){

    int n_primi = -2;
    int n = 2;
    int i;
    int divisore;
    int flag = 1;

    // ciclo di acquisizione
    while (n_primi < 1) {
        printf("Numero positivo: ");
        scanf("%d",&n_primi);
    }

    // ciclo di ricerca degli n_primi numeri primi
    i = 1;
    while (i <= n_primi) {
        flag = 1;
        for(divisore = 2; divisore <= n / 2 && flag == 1; divisore++) {
            if (n % divisore == 0) {
                flag = 0;
            }
        }

        if (flag == 1) {
            printf("%d, ",n);
            i++;
        }
        n++;
    }
}
