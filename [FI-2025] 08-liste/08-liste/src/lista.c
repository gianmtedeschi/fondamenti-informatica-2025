// Librerie 
#include <stdio.h>
#include <stdlib.h> 

// Dati
typedef struct EL {
    int dato;
    struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;

// Prototipi
void stampaLista(ListaDiElem);
ListaDiElem inserisciCoda(ListaDiElem, int);
ListaDiElem inserisciTesta(ListaDiElem, int);
ListaDiElem inserisciPos(ListaDiElem, int, int);
ListaDiElem inserisciOrd(ListaDiElem, int);
ListaDiElem inserisciOrdinatoNoRip(ListaDiElem, int);
int dimensione(ListaDiElem);
float listaMedia(ListaDiElem, int*);
int cercaElemento(ListaDiElem, int);
void eliminaLista(ListaDiElem);
ListaDiElem eliminaPos(ListaDiElem, int);
ListaDiElem eliminaElementiValore(ListaDiElem, int);
ListaDiElem eliminaElementiValore_ric(ListaDiElem, int);

// Main
int main() {
    ListaDiElem head = NULL; // Inizializzazione della lista
    int err;

    printf("Creazione lista con inserimento in testa:\n");
    head = inserisciTesta(head, 10);
    head = inserisciTesta(head, 20);
    head = inserisciTesta(head, 30);
    stampaLista(head);

    printf("\nInserimento in coda:\n");
    head = inserisciCoda(head, 40);
    head = inserisciCoda(head, 50);
    stampaLista(head);

    printf("\nInserimento in posizione:\n");
    head = inserisciPos(head, 25, 2); // Inserisce 25 alla posizione 2
    stampaLista(head);

    printf("\nInserimento ordinato senza duplicati:\n");
    head = inserisciOrdinatoNoRip(head, 35); // Inserisce ordinato
    head = inserisciOrdinatoNoRip(head, 10); // Tentativo duplicato
    stampaLista(head);

    printf("\nCalcolo della lunghezza e media della lista:\n");
    int len = dimensione(head);
    float media = listaMedia(head, &err);
    if (!err) {
        printf("Lunghezza: %d, Media: %.2f\n", len, media);
    } else {
        printf("Errore nel calcolo della media (lista vuota).\n");
    }

    printf("\nRicerca di un elemento nella lista:\n");
    int val = 25;
    if (cercaElemento(head, val)) {
        printf("Elemento %d trovato nella lista.\n", val);
    } else {
        printf("Elemento %d non trovato.\n", val);
    }

    printf("\nEliminazione del nodo in posizione 3:\n");
    head = eliminaPos(head, 3); // Elimina il nodo alla posizione 3
    stampaLista(head);

    printf("\nEliminazione di tutti i nodi con valore 40:\n");
    head = eliminaElementiValore(head, 40); // Elimina tutti i nodi con valore 40
    stampaLista(head);

    printf("\nLiberazione della lista:\n");
    eliminaLista(head);
    head = NULL;
    stampaLista(head); // Verifica che la lista sia vuota

    return 0;
}

// Funzioni
void stampaLista(ListaDiElem head){
    if(head == NULL){
        printf("Lista vuota!\n");
    }
    else{
        ListaDiElem curr = head;
        // Stampo fino al penultimo
        while(curr->prox != NULL){
            printf("%d ->", curr->dato);
            curr = curr->prox;
        }
        // stampo l'ultimo
        printf("%d\n", curr->dato);
    }
}

ListaDiElem inserisciCoda(ListaDiElem head, int new_dato){
    // Alloco il nuovo nodo
    ListaDiElem new = (ListaDiElem)malloc(sizeof(ElemLista));
    if(new == NULL){
        printf("Errore di allocazione\n");
        return head;
    }
    new->dato = new_dato;
    new->prox = NULL;

    // Verifico che la lista sia allcocata, altrimenti il nuovo nodo è il primo
    if(head == NULL) return new;

    // Scorro la lista fino alla fine
    ListaDiElem curr = head;
    while(curr->prox != NULL) curr = curr->prox;
    
    // curr è l'ultimo elemento, quindi attacco new
    curr->prox = new;

    return head;
}

ListaDiElem inserisciTesta(ListaDiElem head, int new_dato){
    // Alloco il nuovo nodo
    ListaDiElem new = (ListaDiElem)malloc(sizeof(ElemLista));
    if(new == NULL){
        printf("Errore di allocazione\n");
        return head;
    }
    new->dato = new_dato;
    new->prox = NULL;

    // Bisogna che il nuovo nodo sia la testa e bisogna restituire la testa
    new->prox = head;

    return new;
}

ListaDiElem inserisciPos(ListaDiElem head, int new_dato, int index) {
    // Controllo se l'indice è valido
    if (index < 0) {
        printf("Indice %d non valido\n", index);
        return head;
    }

    // Caso speciale: lista vuota
    if (head == NULL) {
        if (index == 0) {
            return inserisciTesta(head, new_dato);
        } else {
            printf("Lista vuota, impossibile inserire in posizione %d.\n", index);
            return head;
        }
    }

    // Caso speciale: inserimento in testa
    if (index == 0) {
        return inserisciTesta(head, new_dato);
    }

    // Alloco il nuovo nodo
    ListaDiElem new = (ListaDiElem)malloc(sizeof(ElemLista));
    if (new == NULL) {
        printf("Errore di allocazione\n");
        return head;
    }
    new->dato = new_dato;
    new->prox = NULL;

    // Altri casi: Scorro la lista per trovare la posizione
    int pos = 0;
    ListaDiElem curr = head, prec = NULL;

    while (curr != NULL && pos < index) {
        prec = curr;
        curr = curr->prox;
        pos++;
    }

    // Verifica se l'indice è fuori dai limiti
    if (pos != index) {
        printf("Indice %d fuori dai limiti.\n", index);
        free(new);
        return head;
    }

    // Inserimento del nodo
    prec->prox = new;
    new->prox = curr;

    return head;
}

ListaDiElem inserisciOrd(ListaDiElem lista, int elem) {
    ListaDiElem punt, puntCor = lista, puntPrec = NULL;
    
    // Trova la posizione
    while (puntCor != NULL && elem > puntCor->dato) {
        puntPrec = puntCor;
        puntCor = puntCor->prox;
    }
    
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->dato = elem;
    
    if (puntPrec != NULL) { // Inserimento interno o in coda
        punt->prox = puntCor;
        puntPrec->prox = punt;
        return lista;
    } else { // Inserimento in testa
        punt->prox = lista;
        return punt;
    }
}

ListaDiElem inserisciOrdinatoNoRip(ListaDiElem head, int new_dato) {
    // Alloco il nuovo nodo
    ListaDiElem new_ElemLista = (ListaDiElem)malloc(sizeof(ElemLista));
    if (new_ElemLista == NULL) {
        printf("Errore di allocazione\n");
        return head;
    }
    new_ElemLista->dato = new_dato;
    new_ElemLista->prox = NULL;

    // Controllo se il valore è già presente
    ListaDiElem curr = head, prec = NULL;

    while (curr != NULL && new_dato > curr->dato) {
        prec = curr;
        curr = curr->prox;
    }

    // Se il valore è già presente, non inserisco nulla
    if (curr != NULL && curr->dato == new_dato) {
        printf("Valore %d già presente, non inserito.\n", new_dato);
        free(new_ElemLista);
        return head;
    }

    // Inserimento in testa (prec == NULL)
    if (prec == NULL) {
        new_ElemLista->prox = curr;
        head = new_ElemLista;
    } 
    // Inserimento tra prec e curr
    else {
        prec->prox = new_ElemLista;
        new_ElemLista->prox = curr;
    }

    return head;
}

int dimensione(ListaDiElem head){
    int len = 0;
    ListaDiElem curr = head;

    while(curr != NULL){
        curr = curr->prox;
        len ++;
    }

    return len;
}

int listaMax(ListaDiElem head, int* err){
    // lista vuota
    if(head == NULL){
        printf("Lista vuota\n");
        *err = 1;
        return 0;
    }

    // altrimenti
    *err = 0;
    int max = head->dato;
    ListaDiElem curr = head;

    while(curr != NULL){
        if(max < curr->dato) max = curr->dato;
        curr = curr->prox;
    }

    return max;
}

float listaMedia(ListaDiElem head, int* err){
    // lista vuota
    if(head == NULL){
        printf("Lista vuota\n");
        *err = 1;
        return 0;
    }

    // altrimenti
    *err = 0;
    float media = 0;
    int len = 0;
    ListaDiElem curr = head;

    while(curr != NULL){
        media += curr->dato;
        curr = curr->prox;
        len++;
    }

    return media/len;
}

int cercaElemento(ListaDiElem head, int value){
    ListaDiElem curr = head;
    
    while(curr != NULL){
        if(curr->dato == value) return 1;
        curr = curr->prox;
    }

    return 0;
}

void eliminaLista(ListaDiElem head){
    ListaDiElem curr = head;

    while(head != NULL){
        curr = head;
        head = head->prox;

        free(curr);
    }
}

ListaDiElem eliminaPos(ListaDiElem head, int index) {
    // Controllo se l'indice è valido
    if (index < 0) {
        printf("Indice %d non valido\n", index);
        return head;
    }

    // Lista vuota
    if (head == NULL) {
        printf("Lista vuota, impossibile eliminare.\n");
        return head;
    }

    // Eliminazione della testa
    if (index == 0) {
        ListaDiElem temp = head;
        head = head->prox;
        free(temp);
        return head;
    }

    // Altri casi: scorro la lista
    ListaDiElem curr = head, prec = NULL;
    int pos = 0;

    while (curr != NULL && pos < index) {
        prec = curr;
        curr = curr->prox;
        pos++;
    }

    // Controllo se l'indice è fuori dai limiti
    if (curr == NULL) {
        printf("Indice %d fuori dai limiti.\n", index);
        return head;
    }

    // Rimuovo il nodo corrente
    prec->prox = curr->prox;
    free(curr);

    return head;
}

ListaDiElem eliminaElementiValore(ListaDiElem head, int value){
    ListaDiElem curr = head, prec = NULL, tmp;

    // Elimino in testa
    while(curr != NULL && curr->dato == value){
        tmp = curr;
        curr = curr->prox;

        free(tmp);
    }
    // Aggiorno la testa
    head = curr;

    // Elimino non in testa
    while(curr != NULL){
        if(curr->dato == value){
            tmp = curr;
            prec->prox = curr->prox;
            curr = curr->prox;

            free(tmp);
        }
        else{
            prec = curr;
            curr = curr->prox;
        }
    }

    return head;
}


ListaDiElem eliminaElementiValore_ric(ListaDiElem lista, int elem) {
    ListaDiElem puntTemp;
    if (lista != NULL) {
        if (lista->dato == elem) {
            // Elemento trovato: salva il prossimo e libera il corrente
            puntTemp = lista->prox;
            free(lista);
            return puntTemp; // Il prossimo diventa la testa (o il link corrente)
        } else {
            // Ricorsione sul resto della lista
            lista->prox = cancella(lista->prox, elem);
        }
    }
    return lista;
}
