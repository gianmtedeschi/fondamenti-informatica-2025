#include <stdio.h>

#define DIM 30


int main(){

    // indici per scansione
    int i, j;

    // dimensione effettiva degli array
    int dim_a, dim_b;

    // flag utile per le ricerche di elementi
    int trovato;

    // array e insiemi A e B
    int lista[DIM];
    int A[DIM];
    int B[DIM];

    // dimensione effettiva degli insiemi
    int len_a = 0;
    int len_b = 0;
    int len_u = 0; //dimensione unione
    int len_i = 0; //dimensione intersezione
    int len_d = 0; //dimensione differenza

    // altri insiemi
    int unione[2*DIM];    // A u B
    int intersezione[DIM];// A ^ B
    int differenza[DIM];  // B \ A

    /*
     * ACQUISIZIONE DELLA DIMENSIONE DELLA PRIMA LISTA
     */
    do {
        printf("Quanti elementi vuoi inserire nella prima lista (max: %d)? ",
               DIM);
        scanf("%d", &dim_a);

        if (dim_a > DIM)
            printf("Il valore inserito � troppo grande!\n");
    } while (dim_a > DIM);

    /*
     * ACQUISIZIONE DELLA PRIMA LISTA DI ELEMENTI
     */
    for (i = 0; i < dim_a; i++) {
        printf("Inserire il %do elemento: ", i+1);
        scanf("%d", &lista[i]);
    }

    /*
     * CONVERSIONE IN INSIEME A
     */
    for (i = 0; i < dim_a; i++) {
        trovato = 0;

        //ricerco il valore i-esimo nella lista
        for (j = 0; !trovato && j < len_a; j++)
            trovato = (lista[i] == A[j]);

        //se non trovato, lo inserisco e incremento l'indice
        if (!trovato) {
            //gi� che ci sono, lo inserisco anche nell'unione
            unione[len_a] = lista[i];

            A[len_a] = lista[i];
            len_a++;
        }
    }

    /*
     * A QUESTO PUNTO A COINCIDE CON L'INSIEME UNIONE, AL QUALE DOVR�
     * AGGIUNGERE GLI ELEMENTI DI B SENZA RIPETIZIONI
     */
    len_u = len_a;

    // stampa l'insieme A
    printf ("Insieme A = {");
    for (i = 0; i < len_a; i++)
        printf("%d ", A[i]);
    printf ("}\n");

    /*
     * ACQUISIZIONE DELLA DIMENSIONE DELLA SECONDA LISTA
     */
    do {
        printf("Quanti elementi vuoi inserire nella seconda lista (max: %d)? ",
               DIM);
        scanf("%d", &dim_b);

        if (dim_b > DIM)
            printf("Il valore inserito � troppo grande!\n");
    } while (dim_b > DIM);

    /*
     * ACQUISIZIONE DELLA SECONDA LISTA DI ELEMENTI
     */
    for (i = 0; i < dim_b; i++) {
        printf("Inserire il %do elemento: ", i+1);
        scanf("%d", &lista[i]);
    }

    /*
     * CONVERSIONE IN INSIEME B E CALCOLO UNIONE, INTERSEZIONE,
     * DIFFERENZA
     */
    for (i = 0; i < dim_b; i++) {
        trovato = 0;

        //ricerco il valore i-esimo nella lista
        for (j = 0; !trovato && j < len_b; j++)
            trovato = (lista[i] == B[j]);

        //se non trovato, lo inserisco e incremento l'indice
        if (!trovato) {
            B[len_b] = lista[i];
            len_b++;
        }

        /*
         * UNIONE: Tutti gli elementi in A e tutti gli elementi in B
         * senza ripetizioni.
         */
        trovato = 0;

        //ricerco il valore i-esimo nella lista
        for (j = 0; !trovato && j < len_u; j++)
            trovato = (unione[j] == lista[i]);

        //se non trovato, allora va aggiunto all'unione
        if (!trovato) {
            unione[len_u] = lista[i];
            len_u++;
        }

        /*
         * INTERSEZIONE: Tutti gli elementi che sono sia in A che in
         * B, senza ripetizioni.
         */
        trovato = 0;

        //uso len_b-1 perch� len_b � gi� stato incrementato
        for (j = 0; !trovato && j < len_a; j++)
            trovato = (A[j] == B[len_b-1]);

        //trovato anche in A: allora fa parte dell'intersezione
        if (trovato) {
            trovato = 0;

            //controllo per non inserire duplicati in intersezione
            for (j = 0; !trovato && j < len_i; j++)
                trovato = (intersezione[j] == B[len_b-1]);

            if (!trovato) {
                intersezione[len_i] = B[len_b-1];
                len_i++;
            }
        } else { //non trovato in A: allora fa parte della differenza
            /*
             * DIFFERENZA: Tutti gli elementi che sono in B, tranne
             * quelli che sono in A.
             */
            trovato = 0;

            //controllo per non inserire duplicati in differenza
            for (j = 0; !trovato && j < len_d; j++)
                trovato = (differenza[j] == B[len_b-1]);

            if (!trovato) {
                differenza[len_d] = B[len_b-1];
                len_d++;
            }
        }
    }

    // stampa l'insieme B
    printf ("Insieme B = { ");
    for (i = 0; i < len_b; i++)
        printf("%d ", B[i]);
    printf ("}\n");

    // stampa l'insieme unione
    printf ("unione = { ");
    for (i = 0; i < len_u; i++)
        printf("%d ", unione[i]);
    printf ("}\n");

    // stampa l'insieme intersezione
    printf ("intersezione = { ");
    for (i = 0; i < len_i; i++)
        printf("%d ", intersezione[i]);
    printf ("}\n");

    // stampa l'insieme differenza
    printf ("differenza = { ");
    for (i = 0; i < len_d; i++)
        printf("%d ", differenza[i]);
    printf ("}\n");
}

