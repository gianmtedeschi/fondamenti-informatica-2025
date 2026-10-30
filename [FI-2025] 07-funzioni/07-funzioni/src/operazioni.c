#include <stdio.h>

/* Prototipi */
int leggiNumero();
int massimo(int a, int b);
int minimo(int a, int b);
float media(int somma, int count);

int main() {
    int numero;
    int count = 0;
    int somma = 0;
    int max, min;
    float m;

    printf("Inserisci numeri positivi (0 per terminare):\n");
    numero = leggiNumero();

    /* Gestione caso nessun numero */
    if (numero == 0) {
        printf("Nessun numero inserito.\n");
        return 0;
    }

    /* Inizializzo con il primo numero */
    max = numero;
    min = numero;
    somma = numero;
    count = 1;

    /* Ciclo di lettura successivi */
    numero = leggiNumero();
    while (numero != 0) {
        somma += numero;
        count++;

        max = massimo(max, numero);
        min = minimo(min, numero);

        numero = leggiNumero();
    }

    m = media(somma, count);

    printf("\nHai inserito %d numeri.\n", count);
    printf("Somma = %d\n", somma);
    printf("Massimo = %d\n", max);
    printf("Minimo = %d\n", min);
    printf("Media = %.2f\n", m);

    return 0;
}

/* Legge un numero da tastiera */
int leggiNumero() {
    int n;
    printf("Numero: ");
    do{
        scanf("%d", &n);
    }while(n < 0);
    return n;
}

/* Restituisce il maggiore tra due numeri */
int massimo(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

/* Restituisce il minore tra due numeri */
int minimo(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

/* Calcola la media */
float media(int somma, int count) {
    return (float)somma / (float)count;
}
