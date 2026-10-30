#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a); //leggi(a)

    if (a == 4) //confronto
        printf("La variabile 'a' contiene il valore 4\n");
    else
        printf("La variabile 'a' NON contiene il valore 4\n");
        
    if (a = 4) //assegnamento
        printf("Questo ramo viene sempre eseguito.\n");
    else
        printf("Questo ramo NON viene mai eseguito.\n");

    getchar();
}
