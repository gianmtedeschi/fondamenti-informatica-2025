#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void main(){

    char stringa1[MAX_LEN];
    char stringa2[MAX_LEN];
    int i, j;
    int trovato, uguali;
    char cestino;
    int lungh1;

    // acquisizione delle due stringhe
    printf("Inserire la prima stringa: ");
    scanf("%s",&stringa1);
    scanf("%c", &cestino);
    printf("Inserire la seconda stringa: ");
    scanf("%s",&stringa2);
    scanf("%c", &cestino);

    // controllo che la lunghezza sia uguale
    uguali = 1;
    if (strlen(stringa1) != strlen(stringa2))
        uguali = 0;

    // ciclo per scorrere la prima stringa
    for (i = 0; i < strlen(stringa1) && uguali; i++) {
        trovato = 0;
        // ciclo per scorrere la seconda stringa
        for (j = 0; j < strlen(stringa2) && !trovato; j++)
            // se trovo la lettera la cancello dalla stringa 2
            if (stringa1[i] == stringa2[j]){
                stringa2[j] = '-';
                trovato = 1;
            }
        // se non ho trovato la lettera non sono anagrammi
        if (trovato == 0)
            uguali = 0;
    }

    if (uguali)
        printf("Le due stringhe sono una l'anagramma dell'altra\n");
    else
        printf("No\n");
}
