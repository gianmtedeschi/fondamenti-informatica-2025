#include <stdio.h>

int main() {
    int secondi;
    int sec;
    int min;
    int ore;

    printf("Inserisci il numero di secondi:\n");
    scanf("%d", &secondi);

    min = secondi / 60;
    sec = secondi - min * 60;

    ore = min / 60;
    min = min - ore * 60;

    printf("%d secondi equivalgono a (h:m:s) %d:%d:%d",
            secondi, ore, min, sec);
}
