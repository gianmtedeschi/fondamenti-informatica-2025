#include <stdio.h>
#include <stdlib.h>
#include "lista.c"


// Lista di interi
typedef struct el{
    int dato;
    struct el* prox;
} Node;
typedef Node* Lista;

// Lista compressa di interi
typedef struct c_el{
    int dato, count;
    struct c_el* prox;
} CNode;
typedef CNode* ListaCompressa;

ListaCompressa inserisciCodaCompresso(ListaCompressa head, int new_data, int new_count){
    // Alloco il nuovo nodo
    ListaCompressa new = (ListaCompressa)malloc(sizeof(CNode));
    if(new == NULL){
        printf("Errore di allocazione\n");
        return head;
    }
    new->dato = new_data;
    new->count = new_count;
    new->prox = NULL;

    // Verifico che la lista sia allcocata, altrimenti il nuovo nodo è il primo
    if(head == NULL) return new;

    // Scorro la lista fino alla fine
    ListaCompressa curr = head;
    while(curr->prox != NULL) curr = curr->prox;

    // curr è l'ultimo elemento, quindi attacco new
    curr->prox = new;

    return head;
}

int contaOccorrenze(Lista head, int value){
    int count = 0;
    Lista curr = head;
    while(curr != NULL){
        if(curr->dato == value) count++;
        curr = curr->prox;
    }
    return count;
}

int cercaElemento(ListaCompressa head, int value){
    int found = 0;
    ListaCompressa curr = head;
    while(curr != NULL && !found){
        if(curr->dato == value) found = 1;
        curr = curr->prox;
    }
    return found;
}

ListaCompressa comprimiLista(Lista head, ListaCompressa c_head){
    if(head == NULL) return c_head;

    Lista curr = head;
    int tmp_count;

    while(curr != NULL){
        if(!cercaElemento(c_head, curr->dato)){
            tmp_count = contaOccorrenze(curr, curr->dato);
            c_head = inserisciCodaCompresso(c_head, curr->dato, tmp_count);
        }
        curr = curr->prox;
    }

    return c_head;
}

void stampaListaCompressa(ListaCompressa head) {
    ListaCompressa curr = head;
    printf("Lista Compressa: [ ");
    while (curr != NULL) {
        printf("(%d, %d) ", curr->dato, curr->count);
        curr = curr->prox;
    }
    printf("]\n");
}

int main() {
    /* Dichiarazione variabili (Obbligatorio a inizio blocco in C89) */
    Lista myHead = NULL;
    ListaCompressa myCompHead = NULL;
    
    /* 1. Costruzione della lista dell'esempio: [3,3,3,5,5,2,2,2,2] */
    myHead = inserisciCoda(myHead, 3);
    myHead = inserisciCoda(myHead, 3);
    myHead = inserisciCoda(myHead, 3);
    myHead = inserisciCoda(myHead, 5);
    myHead = inserisciCoda(myHead, 5);
    myHead = inserisciCoda(myHead, 2);
    myHead = inserisciCoda(myHead, 2);
    myHead = inserisciCoda(myHead, 2);
    myHead = inserisciCoda(myHead, 2);

    /* 2. Stampa stato iniziale */
    stampaLista(myHead);

    /* 3. Chiamata alla funzione di compressione */
    /* Nota: passiamo NULL come secondo argomento perché la lista compressa parte vuota */
    myCompHead = comprimiLista(myHead, NULL);

    /* 4. Stampa risultato */
    stampaListaCompressa(myCompHead);

    /* 5. Pulizia memoria */
    eliminaLista(myHead);
    eliminaLista(myCompHead);

    return 0;
}