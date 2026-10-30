#include <stdio.h>
#include <string.h>

#define MAX_LEN 160

int main(){

    char messaggio[MAX_LEN+1];
    char cifrato[MAX_LEN+1];
    int lungh;
    int chiave;
    int i;
    char cestino;

    // acquisizione messaggio da cifrare
    printf("Inserire un messaggio: ");
    gets(messaggio);
    fflush(stdin);
    lungh = strlen(messaggio);

    // acquisizione di una chiave valida
    do {
        printf("Inserire una chiave: ");
        scanf("%d", &chiave);
    } while ( chiave < 1 || chiave > 25 );
    scanf("%c", &cestino);

    // ciclo per cifrare il messaggio
    for (i = 0; i <= lungh; i++) {
        if (messaggio[i] > 96 && messaggio[i] < 123) {
            cifrato[i] = (messaggio[i] - 97 + chiave) % 26 + 97;
        } else
            cifrato[i] = messaggio[i];
    }

    printf("Messaggio cifrato: ");
    printf("%s\n", cifrato);

    // acquisizione messaggio cifrato
    printf("Inserire un messaggio cifrato: ");
    gets(cifrato);
    fflush(stdin);

    // ciclo per decifrare il messaggio
    for (i = 0; i <= lungh; i++) {
        if (cifrato[i] > 96 && cifrato[i] < 123)
            messaggio[i] = (cifrato[i] - 97 + (26 - chiave) ) % 26 + 97;
        else
            messaggio[i] = cifrato[i];

    }

    printf("Messaggio in chiaro: ");
    printf("%s\n", messaggio);
}
