#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 64

int main() {
    FILE * fp;
    char s[DIM];

    if ((fp=fopen("output.txt", "w")) == NULL) {
        return -1;
    }

    int i = 0;
    do {

        // la scanf qui funziona come una gets perchè se scrivo "ciao mondo" in realtà
        // la scrittura reale avverrà in due cicli, nel primo scriverà "ciao" nel secondo
        // non aspetterà l'input dell'utente essendo già il buffer pieno e scriverà "mondo"

        scanf("%s", s); // non conta i \n ma solo gli spazi --> non va mai a capo su file 

        // fgets(s, DIM, stdin); // conteggia i \n mandati da tastiera --> cambiare strcmp "fine\n"
        
        printf("%s\n", s);
        
        if (strcmp("fine", s) != 0)
            fprintf(fp, "%s ", s); // lo spazio nella "%s " stampa lo spazio dopo la prima serie di caratteri

        i++;
    } while (strcmp("fine", s) != 0);
    
    printf("Totale iterazioni %d\n", i);
    fclose(fp);
    
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Errore: Impossibile aprire il file per la lettura.\n");
        return 1;
    }

    /* fscanf funziona come scanf ma legge dal file.
       Restituisce EOF (End Of File) quando non c'è più nulla da leggere. */
    while (fscanf(fp, "%63s", s) != EOF) {
        printf("Parola letta: %s\n", s);
    }

    fclose(fp);

    return 0;
}