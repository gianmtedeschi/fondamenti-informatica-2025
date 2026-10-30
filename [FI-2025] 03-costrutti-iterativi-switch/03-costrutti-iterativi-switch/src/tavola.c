#include <stdio.h>

int main() {
    int i, j, N;

    printf("Programma per stampare la tavola pitagorica fino a N\n");
    printf("Inserisci il valore di N (positivo): ");
    scanf("%d", &N);
    
    printf("\nTavola pitagorica (1 - %d)\n\n", N);

    /* Corpo della tavola */
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
