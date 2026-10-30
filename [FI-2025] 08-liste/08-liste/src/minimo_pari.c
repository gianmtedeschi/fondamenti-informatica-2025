#include "lista.c"

// Prototipo
ListaDiElem minimoPari(ListaDiElem);

// Funzione
ListaDiElem minimoPari(ListaDiElem head){
    if(head == NULL){
        printf("Lista vuota.\n");
        return NULL;
    }

    ListaDiElem curr = head, pMin = NULL;
    int min = 0;

    while(curr != NULL){
        if(curr->dato % 2 == 0){
            if(pMin == NULL || min > curr->dato){
                pMin = curr;
                min = curr->dato;
            }
        }
        curr = curr->prox;
    }

    return pMin;
}
