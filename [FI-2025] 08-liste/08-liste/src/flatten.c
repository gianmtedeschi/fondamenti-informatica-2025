#include <stdio.h>
#include <stdlib.h>

// Definizione nuova struttura
typedef struct ELG {
    int dato;
    struct ELG * prox;   // Puntatore al nodo successivo (orizzontale)
    struct ELG * figlio; // Puntatore alla testa della sotto-lista (verticale)
} ElemGerarchico;

typedef ElemGerarchico * ListaGerarchica;

ListaGerarchica creaNodo(int valore) {
    ListaGerarchica nuovo = (ListaGerarchica)malloc(sizeof(ElemGerarchico));
    if (nuovo == NULL) {
        printf("Errore di allocazione\n");
        exit(1);
    }
    nuovo->dato = valore;
    nuovo->prox = NULL;
    nuovo->figlio = NULL;
    return nuovo;
}

/* Inserimento in coda standard (Adattamento di inserisciCoda) */
ListaGerarchica append(ListaGerarchica head, int valore) {
    ListaGerarchica nuovo = creaNodo(valore);
    
    if (head == NULL) return nuovo;

    ListaGerarchica curr = head;
    while (curr->prox != NULL) {
        curr = curr->prox;
    }
    curr->prox = nuovo;
    return head;
}

/* Stampa semplice per verifica (Adattamento di stampaLista) */
void stampaListaLineare(ListaGerarchica head) {
    if (head == NULL) {
        printf("Lista vuota!\n");
    } else {
        ListaGerarchica curr = head;
        while (curr != NULL) {
            printf("%d -> ", curr->dato);
            curr = curr->prox;
        }
        printf("NULL\n");
    }
}

// Fuznioni di stampa
void stampaGerarchica_rec(ListaGerarchica head, int livello) {
    ListaGerarchica curr = head;
    int i;

    while (curr != NULL) {
        /* 1. Stampa l'indentazione in base al livello corrente */
        for (i = 0; i < livello; i++) {
            printf("       "); /* 7 spazi per ogni livello di profondità */
        }

        /* 2. Stampa il simbolo grafico e il dato */
        if (livello > 0) {
            printf("|__> "); /* Simbolo per i figli */
        } else {
            printf("[L0] "); /* Simbolo per la radice (Livello 0) */
        }
        
        printf("[%d]\n", curr->dato);

        /* 3. Se il nodo ha un figlio, chiamata ricorsiva aumentando il livello */
        if (curr->figlio != NULL) {
            stampaGerarchica_rec(curr->figlio, livello + 1);
        }

        /* 4. Passa al prossimo nodo orizzontale (stesso livello) */
        curr = curr->prox;
    }
}

void stampaGerarchica(ListaGerarchica head) {
    printf("\n--- Visualizzazione Struttura Gerarchica ---\n");
    if (head == NULL) {
        printf("Lista vuota.\n");
    } else {
        stampaGerarchica_rec(head, 0);
    }
    printf("--------------------------------------------\n");
}


void aggiungiFiglio(ListaGerarchica padre, int val_figlio) {
    if (padre == NULL) return;

    if (padre->figlio == NULL) {
        // Se non ha figli, creo la testa della lista figli
        padre->figlio = creaNodo(val_figlio);
    } else {
        // Se ha già figli, uso la funzione append sulla lista 'figlio'
        padre->figlio = append(padre->figlio, val_figlio);
    }
}

void flatten(ListaGerarchica head) {
    ListaGerarchica curr = head;

    while (curr != NULL) {
        // Se il nodo corrente ha una lista figlio
        if (curr->figlio != NULL) {
            
            // 1. Salviamo il riferimento al "vecchio" prossimo nodo
            ListaGerarchica temp_prox = curr->prox;
            
            // 2. Troviamo la CODA della lista del figlio
            // (Logica simile a inserisciCoda per trovare l'ultimo elemento)
            ListaGerarchica coda_figlio = curr->figlio;
            while (coda_figlio->prox != NULL) {
                coda_figlio = coda_figlio->prox;
            }

            // 3. Ricolleghiamo i puntatori
            
            // Il 'prox' del padre diventa l'inizio del figlio
            curr->prox = curr->figlio;
            
            // La fine del figlio si collega al vecchio 'prox' del padre
            coda_figlio->prox = temp_prox;

            // 4. Annulliamo il puntatore figlio poiché ora è integrato nella lista principale
            curr->figlio = NULL;
        }

        // Avanziamo al prossimo nodo.
        // NOTA: Se abbiamo appena fatto il flatten, curr->prox è ora il primo
        // nodo della ex-lista figlio. Questo permette di processare ricorsivamente
        // anche i nipoti senza bisogno di chiamate a funzione ricorsive.
        curr = curr->prox;
    }
}

int main() {
    /* Costruiamo l'esempio:
       [1] -> [2] -> [5] -> NULL
               |
              [3] -> [4] -> NULL
                      |
                     [10] -> NULL
    */

    // Livello 1 (Lista principale)
    ListaGerarchica lista = NULL;
    lista = append(lista, 1);
    lista = append(lista, 2);
    lista = append(lista, 5);

    // Livello 2 (Aggiungo figli al nodo [2])
    // lista->prox è il nodo [2]
    ListaGerarchica nodoDue = lista->prox; 
    aggiungiFiglio(nodoDue, 3);
    aggiungiFiglio(nodoDue, 4);

    // Livello 3 (Aggiungo figlio al nodo [4])
    // nodoDue->figlio è [3], nodoDue->figlio->prox è [4]
    ListaGerarchica nodoQuattro = nodoDue->figlio->prox;
    aggiungiFiglio(nodoQuattro, 10);

    printf("Prima del Flatten\n");
    printf("Nota: stampa solo il livello principale, i figli sono nascosti.\n");
    stampaListaLineare(lista);
    stampaGerarchica(lista);

    printf("\nEsecuzione Flatten\n");
    flatten(lista);

    printf("\nDopo il Flatten\n");
    stampaListaLineare(lista);

    eliminaLista(lista);
    return 0;
}