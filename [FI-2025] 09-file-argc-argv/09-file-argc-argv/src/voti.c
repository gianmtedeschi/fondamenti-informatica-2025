#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nome_file_db = "registro.txt"; 

// Prototipi
void stampa_uso(char *prog_name);
void aggiungi_studente(char *nome, char *cognome, int voto);
void cerca_studenti(int soglia_voto);

int main(int argc, char *argv[]) {
    int i;
    int azione_trovata = 0; // 0 = nessuna, 1 = add, 2 = find */
    
    int idx_add = -1;
    int idx_find = -1;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                nome_file_db = argv[i + 1]; // Sovrascrive il default globale
                i++; // Salta il prossimo elemento (il nome del file)
            } else {
                printf("Errore: Manca il nome del file dopo -f\n");
                return 1;
            }
        } 
        else if (strcmp(argv[i], "-add") == 0) {
            azione_trovata = 1;
            idx_add = i;
        }
        else if (strcmp(argv[i], "-find") == 0) {
            azione_trovata = 2;
            idx_find = i;
        }
    }

    if (azione_trovata == 0) {
        stampa_uso(argv[0]);
        return 0;
    }

    if (azione_trovata == 1) { // Modalità ADD
        if (idx_add + 3 < argc) {
            char *n = argv[idx_add + 1];
            char *c = argv[idx_add + 2];
            int v = atoi(argv[idx_add + 3]); 
            aggiungi_studente(n, c, v);
        } else {
            printf("Errore: -add richiede <nome> <cognome> <voto>\n");
        }
    } 
    else if (azione_trovata == 2) { // Modalità FIND
        if (idx_find + 1 < argc) {
            int soglia = atoi(argv[idx_find + 1]);
            cerca_studenti(soglia);
        } else {
            printf("Errore: -find richiede <voto_minimo>\n");
        }
    }

    return 0;
}

void stampa_uso(char *prog_name) {
    printf("Gestore Registro Voti v1.0\n");
    printf("Uso: %s [-f filename] <azione>\n", prog_name);
    printf("Azioni:\n");
    printf("  -add <nome> <cognome> <voto>  : Aggiunge uno studente\n");
    printf("  -find <voto_min>              : Cerca studenti con voto >= soglia\n");
}

void aggiungi_studente(char *nome, char *cognome, int voto) {
    FILE *fp;
    
    // Apertura in "a" (append): scrive in coda senza cancellare  
    fp = fopen(nome_file_db, "a");
    if (fp == NULL) {
        printf("Errore critico: Impossibile scrivere su '%s'\n", nome_file_db);
        return;
    }

    fprintf(fp, "%s %s %d\n", nome, cognome, voto);
    
    printf(">> Studente aggiunto correttamente in '%s'.\n", nome_file_db);
    
    fclose(fp); // Chiude il file per salvare le modifiche
}

void cerca_studenti(int soglia_voto) {
    FILE *fp;
    char n[50], c[50];
    int v;
    // Variabile STATICA: Viene inizializzata solo una volta all'avvio del programma.
    // Mantiene il valore anche dopo che la funzione termina
    static int record_trovati = 0; 

    fp = fopen(nome_file_db, "r"); 
    if (fp == NULL) {
        printf("Nessun database trovato (%s)\n", nome_file_db);
        return;
    }

    printf("Risultati (Voto >= %d)\n", soglia_voto);

    while (fscanf(fp, "%s %s %d", n, c, &v) == 3) {
        if (v >= soglia_voto) {
            printf("[%d] %s %s: %d\n", ++record_trovati, n, c, v);
        }
    }

    if (record_trovati == 0) {
        printf("Nessuno studente trovato con i criteri richiesti.\n");
    } else {
        printf("Totale record visualizzati: %d\n", record_trovati);
    }

    fclose(fp);
}