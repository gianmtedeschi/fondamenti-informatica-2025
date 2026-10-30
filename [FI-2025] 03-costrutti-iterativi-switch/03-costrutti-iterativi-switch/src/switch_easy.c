#include <stdio.h>
int main ()
{
    char voto;
    scanf(" %c", &voto);
    switch (voto) {
        case 'A':
        case 'a':
            printf("A = Ottimo\n");
            break;
        case 'B':
        case 'b':
            printf("B = Distinto\n");
            break;
        case 'C':
        case 'c':
            printf("C = Buono\n");
            break;
        case 'D':
        case 'd':
            printf("D = Sufficiente\n");
            break;
        case 'E':
        case 'e':
            printf("E = Gravemente insufficiente\n");
            break;
        default:
            printf("Valore non valido. Inserisci un voto tra A e E.\n");
            voto = 0; /* forza la ripetizione */
    }
    return 0;
}