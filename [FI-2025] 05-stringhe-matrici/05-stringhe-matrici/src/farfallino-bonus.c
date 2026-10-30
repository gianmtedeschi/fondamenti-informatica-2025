#include <stdio.h>
#include <string.h>

#define LEN 256

int main(){

    int i, k, len;
    char str[LEN];

    // acquisizione
    do {
        printf("Inserire una frase da tradurre: ");
        gets(str);
        len = strlen(str);
    } while (len > LEN);

    // lettura da sx a dx
    for (i = 0; i <= len; i++) {

        // controllo se la lettera  vocale
        if (str[i] == 'a'||
            str[i] == 'e'||
            str[i] == 'i'||
            str[i] == 'o'||
            str[i] == 'u') {

            // shift a dx di 2 posizioni
            for(k = len; k > i ; k--)
                str[k + 2] = str[k];

            // aggiungo la f e la vocale
            str[i+1] = 'f';
            str[i+2] = str[i];

            i = i + 2;
            len = len + 2;
        }
    }

    printf("%s\n", str);
}
