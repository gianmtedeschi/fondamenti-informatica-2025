#include <stdio.h>

int main() {
    int secondi;
    int sec;
    int min;
    int ore;

    printf("Inserisci il numero di ore:\n");
    scanf("%d", &ore);
    printf("Inserisci il numero di minuti:\n");
    scanf("%d", &min);
    printf("Inserisci il numero di secondi:\n");
    scanf("%d", &sec);

    secondi = (ore * 60 + min) * 60 + sec;

    printf("%d ore, %d minuti, %d secondi equivalgono a %d secondi",
            ore, min, sec, secondi);
}
