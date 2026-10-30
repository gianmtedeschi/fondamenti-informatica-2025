#include <stdio.h>

/* Versione ricorsiva */
double f_ric(double a, int n) {
    if (n == 1)
        return a - 1 / a;  /* Caso base */
    else
        return (a - (n / a)) + f_ric(a, n - 1);
}

/* Versione iterativa */
double f_iter(double a, int n) {
    double somma = 0.0;
    int i;
    for (i = 1; i <= n; i++)
        somma += a - (i / a);
    return somma;
}

int main(void) {
    double a = 2.0;
    int n = 5;

    printf("Versione ricorsiva: f(%.2f, %d) = %.4f\n", a, n, f_ric(a, n));
    printf("Versione iterativa: f(%.2f, %d) = %.4f\n", a, n, f_iter(a, n));

    return 0;
}
