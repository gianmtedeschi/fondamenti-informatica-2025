#include <stdio.h>
#include <stdlib.h>
#include "lista.c"



ListaDiElem trova_centro_k(ListaDiElem head, int k) {
    ListaDiElem fast = head;
    ListaDiElem target = head;
    int acc_vantaggio = 0; // Contatore per i passi di vantaggio accumulati

    if (head == NULL) return NULL;

    while (fast != NULL && fast->prox != NULL) {
        
        /* 1. Fast si muove sempre di 2 passi */
        fast = fast->prox->prox;

        /* 2. Gestione del puntatore Target */
        if (acc_vantaggio < k) {
            /* Finché non abbiamo accumulato k passi di vantaggio rispetto 
               al "ritmo dimezzato", target corre alla stessa velocità di fast (2 passi). */
            target = target->prox->prox;
            acc_vantaggio++;
        } else {
            /* Abbiamo già il vantaggio k. Ora target si muove al ritmo 
               standard del "middle finding" (1 passo alla volta). */
            target = target->prox;
        }
    }

    /* Se il ciclo è finito ma non abbiamo fatto in tempo ad accumulare 
       tutto il vantaggio k (perché la lista era troppo corta), 
       significa che il nodo (N/2 + k) non esiste. */
    if (acc_vantaggio < k) {
        return NULL;
    }

    return target;
}



int main(){
    ListaDiElem head = NULL; // Inizializzazione della lista
    ListaDiElem res = NULL;
    int err;

    printf("Creazione lista con inserimento in testa:\n");
    head = inserisciTesta(head, 1);
    head = inserisciTesta(head, 2);
    head = inserisciTesta(head, 3);
    head = inserisciTesta(head, 4);
    head = inserisciTesta(head, 5);
    head = inserisciTesta(head, 6);
    head = inserisciTesta(head, 7);

    stampaLista(head);

    res = trova_centro_k(head, 2);

    stampaLista(res);
}

