#include <stdio.h>

int main() {
    char car;
    int n;

    printf("Inserire una lettera dell'alfabeto: ");
    scanf("%c", &car);

    printf("Inserire un numero intero positivo: ");
    scanf("%d", &n);

    printf("Carattere %c (intero corrispondente: %d)\n", car, car);

    car = car + n;

    printf("Carattere %c (intero corrispondente: %d)\n", car, car);

    getchar();
}
