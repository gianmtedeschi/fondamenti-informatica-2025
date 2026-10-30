#include <stdio.h>

int main() {
    float prezzo;
    float sconto;
    float finale;
    float risparmio;

    printf("Inserisci il prezzo originale:\n");
    scanf("%f", &prezzo);

    printf("Inserisci lo sconto da applicare:\n");
    scanf("%f", &sconto);

    risparmio = prezzo * (sconto / 100);
    finale = prezzo - risparmio;

    printf("Il prezzo scontato e': %f\n", finale);
    printf("Il risparmio e': %f\n", risparmio);
}
