#include <stdio.h>
#include <string.h>

// Definizione delle strutture dati
typedef struct {
    int ore;
    int minuti;
    int secondi;
} Tempo;

typedef struct {
    int id;
    char nome[51];  /* fino a 50 caratteri + terminatore */
    Tempo nuoto;
    Tempo bici;
    Tempo corsa;
    Tempo totale;
} Atleta;


Tempo somma_tempo(Tempo t1, Tempo t2) {
    Tempo risultato;
    risultato.secondi = t1.secondi + t2.secondi;
    risultato.minuti  = t1.minuti + t2.minuti + risultato.secondi / 60;
    risultato.ore     = t1.ore + t2.ore + risultato.minuti / 60;
    risultato.secondi = risultato.secondi % 60;
    risultato.minuti  = risultato.minuti % 60;
    return risultato;
}

int verifica_tempo_minore(Tempo t1, Tempo t2) {
    if (t1.ore < t2.ore)
        return 1;
    else if (t1.ore > t2.ore)
        return 0;

    if (t1.minuti < t2.minuti)
        return 1;
    else if (t1.minuti > t2.minuti)
        return 0;

    if (t1.secondi <= t2.secondi)
        return 1;
    else
        return 0;
}

Tempo calcola_tempo_totale(Atleta a) {
    Tempo temp;
    temp = somma_tempo(a.nuoto, a.bici);
    temp = somma_tempo(temp, a.corsa);
    return temp;
}

void stampa_miglior_tempo(Atleta atleti[], int n) {
    int i, indice_migliore = 0;

    for (i = 1; i < n; i++) {
        if (!verifica_tempo_minore(atleti[indice_migliore].totale, atleti[i].totale)) {
            indice_migliore = i;
        }
    }

    printf("\nMiglior tempo:\n");
    printf("ID: %d, Nome: %s\n", 
        atleti[indice_migliore].id, 
        atleti[indice_migliore].nome);
    printf("Tempo totale: %02d:%02d:%02d\n",
        atleti[indice_migliore].totale.ore,
        atleti[indice_migliore].totale.minuti,
        atleti[indice_migliore].totale.secondi);
}

int main(void) {
    int n, i;
    Atleta atleti[100]; // dimensione massima

    printf("Inserisci il numero di atleti: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n--- Atleta %d ---\n", i + 1);
        atleti[i].id = i + 1;

        printf("Nome: ");
        scanf("%s", atleti[i].nome);

        printf("Tempo nuoto (h m s): ");
        scanf("%d %d %d", &atleti[i].nuoto.ore, &atleti[i].nuoto.minuti, &atleti[i].nuoto.secondi);

        printf("Tempo bici (h m s): ");
        scanf("%d %d %d", &atleti[i].bici.ore, &atleti[i].bici.minuti, &atleti[i].bici.secondi);

        printf("Tempo corsa (h m s): ");
        scanf("%d %d %d", &atleti[i].corsa.ore, &atleti[i].corsa.minuti, &atleti[i].corsa.secondi);

        atleti[i].totale = calcola_tempo_totale(atleti[i]);
    }

    stampa_miglior_tempo(atleti, n);

    return 0;
}
