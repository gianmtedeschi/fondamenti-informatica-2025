#include <stdio.h>

int main() {
    int a, b, lunghezza;

    printf("Inserisci il primo punto: ");
    scanf("%d", &a);

    printf("Inserisci il secondo punto: ");
    scanf("%d", &b);

    lunghezza = a - b;

    if (lunghezza == 0) {
        printf("I due punti coincidono.\n");
    } else {
        if (lunghezza < 0) {
            lunghezza = -lunghezza;
        }

        printf("La lunghezza del segmento e': %d\n", lunghezza);
    }
}
