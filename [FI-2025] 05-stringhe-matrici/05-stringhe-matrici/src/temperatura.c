#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int giorni, ore;
    int num_giorni;                 /* numero reale di giorni del mese */
    float temp[31][24];             /* matrice temperature */
    float somma_mese = 0.0f;
    float media_mese;
    float somma_giorno, media_giorno;
    float somma_diurna = 0.0f, somma_notturna = 0.0f;
    int conteggio_diurno = 0, conteggio_notturno = 0;

    printf("Inserisci il numero di giorni del mese (28-31): ");
    scanf("%d", &num_giorni);
    if (num_giorni < 28 || num_giorni > 31) {
        printf("Numero di giorni non valido.\n");
        return 1;
    }

    /* Popolamento della matrice con temperature casuali (es. da -5 a 35 gradi) */
    for (giorni = 0; giorni < num_giorni; giorni++) {
        for (ore = 0; ore < 24; ore++) {
            temp[giorni][ore] = rand() % 41 - 5; /* range [-5, 36) */
        }
    }

    /* Calcolo della temperatura media del mese e giornaliera */
    for (giorni = 0; giorni < num_giorni; giorni++) {
        somma_giorno = 0.0f;
        for (ore = 0; ore < 24; ore++) {
            somma_giorno += temp[giorni][ore];
            somma_mese += temp[giorni][ore];

            /* Diurna: ore 7:00 - 19:00 (cioè ore 7–18 incluse) */
            if (ore >= 7 && ore < 19) {
                somma_diurna += temp[giorni][ore];
                conteggio_diurno++;
            } else {
                somma_notturna += temp[giorni][ore];
                conteggio_notturno++;
            }
        }
        media_giorno = somma_giorno / 24.0f;
        printf("Giorno %2d -> Temperatura media giornaliera: %.2f °C\n", giorni + 1, media_giorno);
    }

    /* Calcolo delle medie */
    media_mese = somma_mese / (num_giorni * 24.0f);
    printf("\nTemperatura media del mese: %.2f °C\n", media_mese);
    printf("Temperatura media diurna (7-19): %.2f °C\n", somma_diurna / conteggio_diurno);
    printf("Temperatura media notturna: %.2f °C\n", somma_notturna / conteggio_notturno);

    return 0;
}
