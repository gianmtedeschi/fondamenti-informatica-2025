#include <stdio.h>
#include <string.h>

#define LEN 256


int main(){

    char parola[LEN+1];
    char parola_tradotta[LEN+1];
    int n,i,j;
    int accettabile;

    // acquisizone
    printf("\nInserire la parola da tradurre: ");
    scanf("%s",parola);

    n = strlen(parola);

    j = 0;
    accettabile = 1;
    // ciclo di traduzione
    for (i = 0; i <= n; i++) {
        // controllo che la stringa non superi la massima lunghezza
        if (j < LEN+1) {
            // copio lettera nella stringa tradotta
            parola_tradotta[j] = parola[i];
            // se � una vocale devo inserire la f e raddoppiarla
            if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u') {
                parola_tradotta[j+1] = 'f';
                parola_tradotta[j+2] = parola[i];
                j = j + 3;
            }
            else
                j++;
        }
        else
            accettabile = 0;

    }

    if (accettabile == 1)
        printf("Parola tradotta: %s\n\n",parola_tradotta);
    else
        printf("Parola troppo lunga da tradurre\n\n");

}
