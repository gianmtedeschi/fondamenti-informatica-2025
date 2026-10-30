#include <stdio.h>

int main() {
    int n, m, MCD, mcm, i;

    do {
        printf("Inserire n = ");
        scanf("%d", &n);

        printf("Inserire m = ");
        scanf("%d", &m);

    } while (n < 1 || m < 1);

    MCD = 1;
    for (i = 1; i <= n && i <= m; i++) {
        if (n % i == 0 && m % i == 0)
            MCD = i;
    }

    /* mcm(a, b) = (a * b) / MCD(a, b) */
    mcm = (n * m) / MCD;

    printf("L'MCD di %d e %d e' %d\n", n, m, MCD);
    printf("Il m.c.m. di %d e %d e' %d\n", n, m, mcm);

    return 0;
}
