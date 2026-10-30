#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int b;
    int lunghezza;

    printf("Inserisci il primo punto: ");
    scanf("%d", &a);

    printf("Inserisci il secondo punto: ");
    scanf("%d", &b);

    lunghezza = abs(a - b);

    printf("La lunghezza del segmento e': %d\n", lunghezza);
}
