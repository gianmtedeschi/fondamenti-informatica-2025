#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin, *fout;
    int numero_letto;
    int max;
    int conteggio;
    int primo_numero; // Flag per il primo numero letto

    fin = fopen("input1.txt", "r");
    if (fin == NULL) {
        printf("Errore: Impossibile aprire input1.txt\n");
        return 1;
    }

    fout = fopen("output1.txt", "w");
    if (fout == NULL) {
        printf("Errore: Impossibile creare output1.txt\n");
        fclose(fin);
        return 1;
    }

    conteggio = 0;
    primo_numero = 1; 

    while (fscanf(fin, "%d", &numero_letto) == 1) {
        
        if (primo_numero) {
            // Se è il primo numero, è automaticamente il massimo corrente
            max = numero_letto;
            conteggio = 1;
            primo_numero = 0; // Impostiamo il flag a falso
        } 
        else {
            // Confronto con il massimo attuale
            if (numero_letto > max) {
                max = numero_letto;
                conteggio = 1; // Nuovo massimo trovato, resetto il conteggio a 1
            } 
            else if (numero_letto == max) {
                conteggio++; // Stesso valore del massimo, incremento il conteggio
            }
        }
    }

    if (!primo_numero) {
        fprintf(fout, "%d %d\n", max, conteggio);
    } else {
        printf("Il file di input era vuoto.\n");
    }

    fclose(fin);
    fclose(fout);

    return 0;
}