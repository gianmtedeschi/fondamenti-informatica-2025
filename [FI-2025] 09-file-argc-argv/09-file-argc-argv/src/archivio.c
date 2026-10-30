#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

#define MAX_AUTORE 24
#define MAX_TITOLO 56
#define MAX_VOLUMI 30

typedef struct {
    char autore[MAX_AUTORE];
    char titolo[MAX_TITOLO];
    int copie_possedute;
    int copie_prestito;
} Volume;


int main() {
    FILE *fp;
    Volume V[MAX_VOLUMI];
    int num_volumi = 0;
    int i;
    
    ListaDiElem L = NULL; 
    ListaDiElem curr;     

    int diff;
    int sum_possedute = 0;
    int sum_disponibili = 0;
    float rapporto;

    int max_val = -1;
    int riga_max = -1;
    int riga_corrente;

    fp = fopen("archivio.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Errore: impossibile aprire 'archivio.txt'.\n");
        return 1;
    }

    while (num_volumi < MAX_VOLUMI && 
           fscanf(fp, "%s %s %d %d", 
                  V[num_volumi].autore, 
                  V[num_volumi].titolo, 
                  &V[num_volumi].copie_possedute, 
                  &V[num_volumi].copie_prestito) == 4) {
        num_volumi++;
    }
    fclose(fp);

    printf("--- CONTENUTO DEL VETTORE V ---\n");
    for (i = 0; i < num_volumi; i++) {
        printf("Riga %d: %s - %s (Poss: %d, Prest: %d)\n", 
               i + 1, V[i].autore, V[i].titolo, V[i].copie_possedute, V[i].copie_prestito);
    }
    printf("\n");


    for (i = 0; i < num_volumi; i++) {
        diff = V[i].copie_possedute - V[i].copie_prestito;
        L = inserisciCoda(L, diff);
    }

    printf("--- CONTENUTO DELLA LISTA L (Copie Disponibili) ---\n");
    stampaLista(L);
    printf("\n");

    for (i = 0; i < num_volumi; i++) {
        sum_possedute += V[i].copie_possedute;
    }

    curr = L;
    while (curr != NULL) {
        sum_disponibili += curr->dato;
        curr = curr->prox;
    }

    if (sum_possedute > 0) {
        rapporto = (float)sum_disponibili / (float)sum_possedute;
        printf("--- STATISTICHE ---\n");
        printf("Totale Possedute (da V): %d\n", sum_possedute);
        printf("Totale Disponibili (da L): %d\n", sum_disponibili);
        printf("Rapporto: %.2f\n\n", rapporto);
    }

    curr = L;
    riga_corrente = 1;

    while (curr != NULL) {
        if (curr->dato > max_val) {
            max_val = curr->dato;
            riga_max = riga_corrente;
        }
        curr = curr->prox;
        riga_corrente++;
    }

    printf("--- RISULTATO ---\n");
    if (riga_max != -1) {
        printf("Volume con piu' copie disponibili (%d) alla riga: %d\n", max_val, riga_max);
    } else {
        printf("Nessun dato disponibile.\n");
    }

    eliminaLista(L);

    return 0;
}