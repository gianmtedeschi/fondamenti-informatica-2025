#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin, *fout;
    int righe, colonne;
    int i, j;
    double valore;
    int elementi_letti;

    // Apertura del file binario in lettura
    // "rb" è fondamentale per leggere correttamente i file binari
    fin = fopen("input6.bin", "rb");
    if (fin == NULL) {
        printf("Errore: Impossibile aprire input6.bin\n");
        return 1;
    }
    elementi_letti = fread(&righe, sizeof(int), 1, fin);
    elementi_letti += fread(&colonne, sizeof(int), 1, fin);

    if (elementi_letti != 2) {
        printf("Errore: Il file è troppo corto o corrotto.\n");
        fclose(fin);
        return 1;
    }

    fout = fopen("coo6.txt", "w");
    if (fout == NULL) {
        printf("Errore: Impossibile creare coo6.txt\n");
        fclose(fin);
        return 1;
    }

    for (i = 0; i < righe; i++) {
        for (j = 0; j < colonne; j++) {
            if (fread(&valore, sizeof(double), 1, fin) != 1) {
                printf("Attenzione: Fine del file inaspettata all'elemento (%d, %d)\n", i, j);
                // Interrompiamo i cicli forzando gli indici al massimo
                i = righe; 
                j = colonne;
            } else {
                // Se il valore è diverso da zero, salviamo la tripla (COO)
                if (valore != 0.0) {
                    // Scriviamo: indice riga, indice colonna, valore
                    fprintf(fout, "%d %d %lf\n", i, j, valore);
                }
            }
        }
    }

    fclose(fin);
    fclose(fout);

    printf("Conversione completata. Risultato salvato in coo6.txt\n");

    return 0;
}