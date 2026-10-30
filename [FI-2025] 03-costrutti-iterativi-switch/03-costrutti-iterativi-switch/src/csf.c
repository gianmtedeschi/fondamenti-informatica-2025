#include <stdio.h>

int main() {
    char g1, g2;

    /*
      variabile che indica il vincitore:
         - se vince == 1 allora vince g1
         - se vince == 2 allora vince g2
         - se vince == 0 allora parita'
     */
    int vince = 1;

    int ok1, ok2;

    do {
        printf("Giocata giocatore 1 (C/F/S?): ");
        scanf(" %c", &g1);

        // fflush(stdin);

        printf("\nGiocata giocatore 2 (C/F/S?): ");
        scanf(" %c", &g2);

        // fflush(stdin);

        // variabile ausiliaria, vale 1 se la giocata del giocatore 1 è buona
        ok1 = (g1 == 'C' || g1 == 'F' || g1 == 'S');

        // variabile ausiliaria, vale 1 se la giocata del giocatore 2 è buona
        ok2 = (g2 == 'C' || g2 == 'F' || g2 == 'S');

        /*
          la condizione di permanenza nel ciclo è: "quello inserito da
          g1 non va bene o quello inserito da g2 non va bene"
        */
    } while(!ok1 || !ok2);

    /*
      per ridurre il numero di casi dell'if posso assumere che vinca
      sempre g1 e poi valuto le condizioni che farebbero vincere g2
     */

    // i caratteri nel codice vanno tra apici singoli ' '
    if(g1 == 'C' && g2 == 'F')
        vince = 2;

    if(g1 == 'F' && g2 == 'S')
        vince = 2;

    if(g1 == 'S' && g2 == 'C')
        vince = 2;

    // e quelle che farebbero pareggiare
    if(g1 == g2)
        vince = 0;

    // stampo il risultato
    if (vince > 0)
        printf("vince il giocatore %d\n" , vince);
    else
        printf("pari\n");

    return 0;
}
