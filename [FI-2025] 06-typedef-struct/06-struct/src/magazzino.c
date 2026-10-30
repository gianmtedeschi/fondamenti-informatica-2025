#include <stdio.h>
#include <string.h>

#define MAX_PRODOTTI 10
#define MAX_NOME 50

/* Definizione struttura prodotto */
typedef struct {
    int id;
    char nome[MAX_NOME + 1];
    float quantita;
    float prezzo;
} Prodotto;

int main() {
    Prodotto magazzino[MAX_PRODOTTI];
    int n_prodotti = 0;
    int scelta;
    int i, id, trovato;
    float qta;

    do {
        printf("\n--- MENU MAGAZZINO ---\n");
        printf("1. Inserisci nuovo prodotto\n");
        printf("2. Incrementa quantita di un prodotto\n");
        printf("3. Visualizza tutti i prodotti\n");
        printf("4. Vendi un prodotto\n");
        printf("5. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                if (n_prodotti >= MAX_PRODOTTI) {
                    printf("Magazzino pieno!\n");
                } else {
                    printf("Inserisci id: ");
                    scanf("%d", &id);

                    /* controllo ID duplicato */
                    trovato = 0;
                    for (i = 0; i < n_prodotti; i++) {
                        if (magazzino[i].id == id) {
                            trovato = 1;
                            break;
                        }
                    }

                    if (trovato) {
                        printf("Errore: esiste gia' un prodotto con questo ID.\n");
                    } else {
                        magazzino[n_prodotti].id = id;
                        printf("Inserisci nome: ");
                        scanf("%50s", magazzino[n_prodotti].nome);
                        printf("Inserisci quantita: ");
                        scanf("%f", &magazzino[n_prodotti].quantita);
                        printf("Inserisci prezzo: ");
                        scanf("%f", &magazzino[n_prodotti].prezzo);
                        n_prodotti++;
                        printf("Prodotto inserito correttamente.\n");
                    }
                }
                break;

            case 2:
                printf("Inserisci id del prodotto da incrementare: ");
                scanf("%d", &id);
                trovato = 0;
                for (i = 0; i < n_prodotti; i++) {
                    if (magazzino[i].id == id) {
                        printf("Inserisci quantita da aggiungere: ");
                        scanf("%f", &qta);
                        if (qta <= 0) {
                            printf("Quantita non valida.\n");
                        } else {
                            magazzino[i].quantita += qta;
                            printf("Quantita aggiornata: %.2f\n", magazzino[i].quantita);
                        }
                        trovato = 1;
                        break;
                    }
                }
                if (!trovato)
                    printf("Prodotto non trovato.\n");
                break;

            case 3:
                if (n_prodotti == 0) {
                    printf("Nessun prodotto nel magazzino.\n");
                } else {
                    printf("\n--- Elenco prodotti ---\n");
                    for (i = 0; i < n_prodotti; i++) {
                        printf("ID: %d | Nome: %s | Quantita: %.2f | Prezzo: %.2f\n",
                               magazzino[i].id,
                               magazzino[i].nome,
                               magazzino[i].quantita,
                               magazzino[i].prezzo);
                    }
                }
                break;

            case 4:
                printf("Inserisci id del prodotto da vendere: ");
                scanf("%d", &id);
                trovato = 0;
                for (i = 0; i < n_prodotti; i++) {
                    if (magazzino[i].id == id) {
                        printf("Inserisci quantita da vendere: ");
                        scanf("%f", &qta);
                        if (qta <= 0) {
                            printf("Quantita non valida.\n");
                        } else if (qta > magazzino[i].quantita) {
                            printf("Errore: quantita richiesta superiore alla disponibilita' (%.2f)\n",
                                   magazzino[i].quantita);
                        } else {
                            magazzino[i].quantita -= qta;
                            printf("Vendita effettuata. Nuova quantita: %.2f\n", magazzino[i].quantita);
                        }
                        trovato = 1;
                        break;
                    }
                }
                if (!trovato)
                    printf("Prodotto non trovato.\n");
                break;

            case 5:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Scelta non valida.\n");
                break;
        }

    } while (scelta != 5);

    return 0;
}
