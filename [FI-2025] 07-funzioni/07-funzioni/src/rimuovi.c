// Librerie
#include <stdio.h>
#include <string.h>

// Costanti 
#define LEN 100

// Prototipi
char leggiCarattere();
void leggiStringa(char []);
void rimuoviCarattere(char [], char [], char);

// Main
int main(){
    // Variabili
    char src[LEN], dest[LEN], da_rimuovere;

    // Leggi stringa
    leggiStringa(src);

    // Leggi Carattere
    da_rimuovere = leggiCarattere();

    // Rimuovi il carattere dalla stringa
    rimuoviCarattere(src, dest, da_rimuovere);

    // Stampa la stringa dst
    printf("%s senza %c = %s\n", src, da_rimuovere, dest);

    return 0;
}

// Funzioni
char leggiCarattere(){
    char c;
    printf("Inserisci carattere: ");
    scanf("%c", &c);
    scanf("%*c");
    return c;
}

void leggiStringa(char stringa[]){
    printf("Inserisci stringa: ");
    scanf("%s", stringa);
    fflush(stdin);
    return;
}

void rimuoviCarattere(char src[], char dest[], char da_rimuovere){
    // Variabili
    int len_src, i, len_dest;

    // Inizializzo Lunghezze
    len_src = strlen(src);
    len_dest = 0;

    // Scorro src per copiare senza buchi in dest
    for(i=0; i<len_src; i++){
        if(src[i] != da_rimuovere){
            dest[len_dest] = src[i];
            len_dest++;
        }
    }

    // Aggiungo carattere di terminazione
    dest[len_dest] = '\0';

    return;
}
