#include <stdio.h>

int main() {
    int secondi;
    int sec;
    int min;
    int ore;

    printf("Inserisci il numero di secondi:\n");
    scanf("%d", &secondi);

    ore = secondi / 3600;
    min = (secondi - ore * 3600) / 60;
    sec = secondi - ore * 3600 - min * 60;

    printf("%d secondi equivalgono a (h:m:s) %d:%d:%d",
            secondi, ore, min, sec);
}
