#include <stdio.h>

int main() {
    char voto;
    int isValido = 0;

    while (!isValido) {
        printf("Inserisci un voto (A - E): ");
        scanf(" %c", &voto);

        if (voto == 'A' || voto == 'a') {
            printf("A = Ottimo\n");
            isValido = 1;
        } else {
            if (voto == 'B' || voto == 'b') {
                printf("B = Distinto\n");
                isValido = 1;
            } else {
                if (voto == 'C' || voto == 'c') {
                    printf("C = Buono\n");
                    isValido = 1;
                } else {
                    if (voto == 'D' || voto == 'd') {
                        printf("D = Sufficiente\n");
                        isValido = 1;
                    } else {
                        if (voto == 'E' || voto == 'e') {
                            printf("E = Gravemente insufficiente\n");
                            isValido = 1;
                        } else {
                            printf("Valore non valido. Inserisci un voto tra A e E.\n");
                        }
                    }
                }
            }
        }
    }

    return 0;
}
