#include <stdio.h>
#include <math.h>

/* Funzione che modifica le variabili potenza e radice per riferimento */
void calcola(double base, double exp, double *potenza, double *radice)
{
    /* Uso dell’operatore * per accedere ai valori puntati */
    *potenza = pow(base, exp);

    if (base >= 0.0)
        *radice = sqrt(base);
    else
        *radice = -1.0; /* valore sentinella per base negativa */
}

int main()
{
    double b, e;
    double p, r;

    printf("Inserisci base ed esponente: ");
    scanf("%lf %lf", &b, &e);

    /* Passaggio per riferimento con l’operatore & */
    calcola(b, e, &p, &r);

    printf("\nRisultati calcolati tramite passaggio per riferimento:\n");
    printf("Base = %.3f, Esponente = %.3f\n", b, e);
    printf("Potenza = %.3f\n", p);
    if (r >= 0)
        printf("Radice quadrata = %.3f\n", r);
    else
        printf("Radice quadrata: impossibile (base negativa)\n");

    return 0;
}
