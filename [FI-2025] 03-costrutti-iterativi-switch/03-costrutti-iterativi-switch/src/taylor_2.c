#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double x, res, fatt;
    double segno;

    printf("Programma per calcolare lo sviluppo di McLaurin di sin(x) all'ordine n\n");
    printf("Inserire un valore di x: ");
    scanf("%lf",&x);

    printf("Inserire un valore di n: ");
    scanf("%d", &n);

    res = 0.0;
    fatt = 1.0;
    segno = 1.0;
    potenza = x;
    
    /* Primo termine: i = 0 -> x^(1) / 1! = x */
    for (i = 0; i < n; i++) {
        /* aggiorno il risultato */
        res += segno * potenza / fatt;

        /* preparo i valori per il prossimo termine */
        segno = -segno;  /* alterna il segno (-1)^i */

        /* aggiorna (2i+1)! → (2(i+1)+1)! */
        fatt *= (2.0 * i + 2.0) * (2.0 * i + 3.0); 
        
        /* aggiorna potenza: x^(2i+3) = x^(2i+1) * x^2 */
        potenza *= x * x;
    }

    printf("Lo sviluppo di sin(x) e': %2.10f\n", res);
    printf("Il valore reale e': %2.10f", sin(x));

    return 0;
}
