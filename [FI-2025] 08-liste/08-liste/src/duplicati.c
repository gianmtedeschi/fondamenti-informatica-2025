#include "lista.c"

ListaDiElem eliminaDuplicatiIterativo(ListaDiElem head) {
    // Lista vuota o con un solo elemento
    if (head == NULL || head->prox == NULL) return head;

    ListaDiElem curr = head;

    // Scorro la lista esterna
    while (curr != NULL) {
        ListaDiElem runner = curr; // Runner per scorrere il resto della lista
        while (runner->prox != NULL) {
            if (runner->prox->dato == curr->dato) {
                // Nodo duplicato trovato
                ListaDiElem tmp = runner->prox;
                runner->prox = runner->prox->prox; // Salta il duplicato
                free(tmp); // Libera il nodo duplicato
            } else {
                runner = runner->prox; // Avanza
            }
        }
        curr = curr->prox; // Avanza nella lista esterna
    }

    return head;
}

ListaDiElem eliminaElementiUguali(ListaDiElem head, int value) {
    // Caso base: lista vuota
    if (head == NULL) return NULL;

    // Caso: il nodo corrente contiene `value`
    if (head->dato == value) {
        ListaDiElem tmp = head;          // Salvo il nodo corrente
        head = eliminaElementiUguali(head->prox, value); // Elimino il resto dei nodi con `value`
        free(tmp);                 // Libero il nodo corrente
        return head;
    }

    // Caso: il nodo corrente non contiene `value`
    head->prox = eliminaElementiUguali(head->prox, value);
    return head;
}

ListaDiElem eliminaDuplicatiRicorsivo(ListaDiElem head) {
    // Caso base: lista vuota o con un solo elemento
    if (head == NULL || head->prox == NULL) return head;

    // Elimino ricorsivamente i duplicati del resto della lista
    head->prox = eliminaDuplicatiRicorsivo(head->prox);

    // Elimino ricorsivamente tutti i nodi uguali al dato di head
    head->prox = eliminaElementiUguali(head->prox, head->dato);

    return head;
}
