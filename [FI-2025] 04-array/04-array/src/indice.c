#include <stdio.h>

#define DIM 10

int main(){

    int i;
    int j; //indice usato solo per chiarezza, ma non necessario
    int indice[DIM];
    int valori[DIM];
    int dim;

    //acquisizione della dimensione
    do {
        printf("Quanti elementi vuoi inserire (max: %d)? ", DIM);
        scanf("%d", &dim);
        if (dim > DIM)
            printf("Il valore inserito e' troppo grande!\n");
    } while (dim > DIM);

    //acquisizione valori
    for (i = 0; i < dim; i++) {
        printf("Inserire il %do valore: ", i+1);
        scanf("%d", &valori[i]);
    }

    //acquisizione indice
    for (i = 0; i < dim; i++) {
        printf("Qual e' il %do valore che vuoi stampare? ", i+1);
        //tutti i valori dell'indice devono puntare ad elementi validi
        // quindi all'interno dei limiti 0,dim
        do {
            scanf("%d", &indice[i]);
            if (indice[i] > dim || indice[i] < 0)
                printf("Il valore inserito non e' in [0, %d]", dim);
        } while (indice[i] > dim || indice[i] < 0);

        //si assume che l'utente che vuole indicare il primo elemento (ad
        // esempio), inserisca il numero 1, quindi dobbiamo decrementare
        // tutto di 1: 1o, 2o, 3o... -> 0, 1, 2
        indice[i] = indice[i] - 1;
    }

    //stampa in ordine stabilito dall'indice
    for (i = 0; i < dim; i++)
    {
        j = indice[i];
        printf("%d\n", valori[j]);
    }
}
