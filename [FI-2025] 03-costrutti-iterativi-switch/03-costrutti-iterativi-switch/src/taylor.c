#include <stdio.h>
#include <math.h>

int main() {

    int n, i, j;
    float x, res;
    double fatt;
    printf("Programma per calcolare lo sviluppo di McLaurin di sin(x) all'ordine n\n");
    printf("Inserire un valore di x: ");
    scanf("%f",&x);

    printf("Inserire un valore di n: ");
    scanf("%d",&n);

    res = 0.0;
    fatt = 1.0;
    for(i = 0; i < n; i++) {
        fatt = 1;
        for(j = 1; j <= 2 * i + 1; j++)
            fatt = fatt * j;
        res = res + pow(-1.0, i) / fatt * pow(x, 2 * i + 1);
        printf("%f\n", fatt);
    }

    printf("Lo sviluppo di sin(x) e': %2.10f\n", res);
    printf("Il valore reale e': %2.10f", sin(x));
}
