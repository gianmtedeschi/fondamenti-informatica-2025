
typedef struct {
  char nome[24];
  char cognome[24];
  char email[64];
} Utente;

typedef struct {
  char contenuto[256];
  Utente mittente;
  int numDestinatari;
  Utente destinatari[256];
} Messaggio;

Utente utenti_facebook[10];
Messaggio messaggi_inviati[10];

void main () {
  int i, j;
  Utente utenti_facebook[10];
  Messaggio messaggi_inviati[10];		

  for (i = 0; i < 10; i++) {
    j = 0;

    //ricerca destinatario.email != mittente.email con strcmp()
    while (j < messaggi_inviati[i].numDestinatari &&
              strcmp(messaggi_inviati[i].mittente.email,
                     messaggi_inviati[i].destinatari[j].email) != 0) {
      j++;
    }

    if (j == messaggi_inviati[i].numDestinatari) //non trovato
      printf("%s", Messaggi[i].mittente.email);
}
