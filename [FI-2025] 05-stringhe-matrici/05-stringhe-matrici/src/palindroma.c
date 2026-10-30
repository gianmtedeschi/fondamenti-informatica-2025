#include <stdio.h>
#include <string.h>

#define LEN 256

int main(){

    char frase[LEN+1];
    int palindromo;
    int n_caratteri;
    int i,j;

    printf("\nInserire la frase: ");
    gets(frase);
    fflush(stdin);

    n_caratteri = strlen(frase),

    // ciclo di controllo se palindromo,
    // scorro contemporaneamente la stringa nei due versi
    palindromo = 1;
    j = n_caratteri - 1;
    for (i = 0; (i < n_caratteri/2) && (palindromo == 1); i++) {
        // controllo che i due caratteri siano uguali
        if (frase[i] != frase[j])
            palindromo = 0;
        j--;
    }

    if (palindromo == 1)
        printf("E' palindromo\n\n");
    else
        printf("Non e' palindromo\n\n");

}
