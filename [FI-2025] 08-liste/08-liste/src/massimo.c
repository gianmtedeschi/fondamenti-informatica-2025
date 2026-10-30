#include "lista.c"

// Prototipo
int trovaMax(ListaDiElem, int*);

// Funzione
int trovaMax(ListaDiElem head, int *err) {
    // Inizializzo l'errore a 0
    *err = 0;

    // Gestione della lista vuota
    if (head == NULL) {
        printf("Errore: Lista vuota.\n");
        *err = 1;
        return 0; // Valore predefinito in caso di errore
    }

    // Inizializzo il massimo con il primo elemento
    int max = head->dato;
    ListaDiElem curr = head->prox;

    // Scorro la lista per trovare il massimo
    while (curr != NULL) {
        if (curr->dato > max) {
            max = curr->dato;
        }
        curr = curr->prox;
    }

    return max;
}
