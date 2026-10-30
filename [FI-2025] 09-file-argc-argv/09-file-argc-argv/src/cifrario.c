#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampa_uso(char *nome_prog) {
    printf("Errore nei parametri.\n");
    printf("Uso: %s -i <input> -o <output> -k <chiave> [-d]\n", nome_prog);
}

int main(int argc, char *argv[]) {
    char *file_in = NULL;
    char *file_out = NULL;
    int chiave = 0;
    int chiave_trovata = 0;
    int decifra = 0;
    
    int j;
    FILE *fin, *fout;
    int c; 

    for (j = 1; j < argc; j++) {
        if (strcmp(argv[j], "-i") == 0) {
            if (j + 1 < argc) { 
                file_in = argv[++j]; 
            }
            else { 
                return 1; 
            }
        }
        else if (strcmp(argv[j], "-o") == 0) {
            if (j + 1 < argc) { 
                file_out = argv[++j]; 
            }
            else { 
                return 1; 
            }
        }
        else if (strcmp(argv[j], "-k") == 0) {
            if (j + 1 < argc) { 
                chiave = atoi(argv[++j]); 
                chiave_trovata = 1; 
            } else { 
                return 1; 
            }
        }
        else if (strcmp(argv[j], "-d") == 0) {
            decifra = 1;
        }
    }

    if (file_in == NULL || file_out == NULL || chiave_trovata == 0) {
        stampa_uso(argv[0]);
        return 1;
    }

    fin = fopen(file_in, "r");
    if (fin == NULL) return 1;

    fout = fopen(file_out, "w");
    if (fout == NULL) { fclose(fin); return 1; }

    if (decifra) {
        chiave = -chiave;
    }

    while ((c = fgetc(fin)) != EOF) {
        
        // Caso Maiuscole: da 'A' (65) a 'Z' (90)
        if (c >= 'A' && c <= 'Z') {
            // Normalizziamo da 0 a 25 sottraendo 'A'
            // Aggiungiamo la chiave
            // Facciamo il modulo 26
            c = (c - 'A' + chiave) % 26;
            
            // Gestione modulo per numeri negativi (decifratura)
            if (c < 0) c += 26;
            
            // Riportiamo nel range ASCII sommando 'A'
            c += 'A';
        }

        // Caso Minuscole: da 'a' (97) a 'z' (122)
        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + chiave) % 26;
            
            if (c < 0) c += 26;
            
            c += 'a';
        }
        
        /* Se non è né maiuscola né minuscola (es. numeri, punteggiatura), 
           saltiamo gli if e scriviamo il carattere originale */

        fputc(c, fout);
    }

    printf("Operazione completata.\n");

    fclose(fin);
    fclose(fout);

    return 0;
}