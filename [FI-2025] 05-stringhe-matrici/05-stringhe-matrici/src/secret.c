#include <stdio.h>
#include <string.h>
#define DIM 50

int main(void) {
    
    char msg[DIM + 1], secret[DIM + 1];
    int i, j, len_msg, len_secret;
    int found = 0; /* indica se la sequenza è contenuta */

    printf("Inserisci msg: ");
    gets(msg);

    printf("Inserisci secret: ");
    gets(secret);

    len_msg = strlen(msg);
    len_secret = strlen(secret);

    j = 0; /* indice per secret */

    for (i = 0; i < len_msg && j < len_secret; i++) {
        if (msg[i] == secret[j]) {
            if(msg[i] >= 'a' && msg[i] <= 'z'){
                msg[i] = msg[i] - ('a' - 'A'); /* rendi maiuscola la lettera trovata */
            }
            j++; /* passa al prossimo carattere di secret */
        }
    }

    if (j == len_secret) {
        printf("ACCESSO CONSENTITO\n");
        printf("%s\n", msg);
    } else {
        printf("ACCESSO NEGATO\n");
    }

    return 0;
}
