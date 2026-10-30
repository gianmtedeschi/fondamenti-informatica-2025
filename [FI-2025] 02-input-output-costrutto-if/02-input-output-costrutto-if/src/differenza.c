#include <stdio.h>

// inizio della procedura principale, detta "main"
int main() {
    /*  Dichiarazione delle variabili */
    int a;
    int b;
    int differenza;

    /* Stampa a video della stringa formattata. Il carattere speciale "\n" manda a capo. */

    printf("Inserisci il primo numero \n"); // stampa("...")

    /* Legge un valore di tipo intero (i.e., "%d") e lo scrive nella cella di memoria della variabile "a". L'indirizzo di memoria di tale cella è specifocato con l'operatore "&", ovvero "indirizzo di" */
    scanf("%d", &a); //leggi(a)

    printf("Inserisci il secondo numero \n"); //stampa("...")
    scanf("%d", &b); //leggi(b)

    /* Calcola la differenza tra il valore memorizzato nella variabile "a" ed
        il valore memorizzato nella variabile "b". Il risultato dell'operazione
        è scritto nella variabile "differenza". */
    differenza = a - b;

    /* Stampa a video la stringa formattata. Al posto dello specificatore di
        formato "%d" verrà stampato il contenuto della variabile "differenza",
        formattato come intero. */
    printf("La differenza e' %d\n", differenza);
}
