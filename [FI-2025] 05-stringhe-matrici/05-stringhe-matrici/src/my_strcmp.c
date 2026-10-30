#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(){

    char str1[MAX_LEN+1], str2[MAX_LEN+1];
    char str12[2*MAX_LEN+1];
    int lungh1, lungh2;
    int i, res = 0;

    printf("Inserire la prima stringa: ");
    gets(str1);
    fflush(stdin);

    printf("Inserire la seconda stringa: ");
    gets(str2);
    fflush(stdin);

    // Resettiamo l'indice 'i' a 0 per iniziare il confronto dall'inizio
    i = 0;

    // Il ciclo confronta i caratteri finché sono uguali e non si arriva alla fine
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }

    // 3. Calcoliamo il risultato SULLA BASE del primo carattere diverso trovato
    //    o del terminatore nullo. Questo funziona anche se le lunghezze sono diverse.
    res = str1[i] - str2[i];


    // Stampa del risultato
    if (res == 0) {
        printf("Le stringhe sono uguali.\n");
    } else if (res < 0) {
        printf("\"%s\" viene prima di \"%s\".\n", str1, str2);
    } else {
        printf("\"%s\" viene dopo di \"%s\".\n", str1, str2);
    }

    return 0;

}
