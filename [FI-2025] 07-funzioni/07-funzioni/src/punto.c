#include <stdio.h>

typedef struct{
    double x;
    double y;
} Punto;

/* Trasla un punto di (dx, dy) – modifica per riferimento */
void trasla(Punto *p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

/* Calcola il baricentro di n punti (restituito per riferimento) */
Punto baricentro(Punto *punti, int n)
{
    int i;
    Punto ris;
    ris.x = 0.0;
    ris.y = 0.0;

    for (i = 0; i < n; i++) {
        ris.x += punti[i].x;
        ris.y += punti[i].y;
    }

    ris.x /= n;
    ris.y /= n;

    return ris;
}

int main(void)
{
    Punto punti[3];
    Punto centro;
    int i;
    double dx, dy;

    printf("Inserisci le coordinate di 3 punti (x y):\n");
    for (i = 0; i < 3; i++)
        scanf("%lf %lf", &punti[i].x, &punti[i].y);

    printf("Vettore di traslazione (dx dy): ");
    scanf("%lf %lf", &dx, &dy);

    for (i = 0; i < 3; i++)
        trasla(&punti[i], dx, dy);  /* passaggio per riferimento */

    centro = baricentro(punti, 3);  /* risultato via valore di ritorno */

    printf("Punti traslati:\n");
    for (i = 0; i < 3; i++)
        printf("(%.2f, %.2f)\n", punti[i].x, punti[i].y);

    printf("Baricentro: (%.2f, %.2f)\n", centro.x, centro.y);

    return 0;
}
