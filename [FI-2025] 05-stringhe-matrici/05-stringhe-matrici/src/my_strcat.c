#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(){

    char str1[MAX_LEN+1], str2[MAX_LEN+1];
    char str12[2*MAX_LEN+1];
    int lungh1, lungh2;
    int i;

    printf("Inserire la prima stringa: ");
    gets(str1);
    fflush(stdin);

    printf("Inserire la seconda stringa: ");
    gets(str2);
    fflush(stdin);

    // strlen prima stringa
    lungh1 = 0;
    for (i = 0; str1[i] != '\0'; i++)
        lungh1++;

    // strlen seconda stringa
    lungh2 = 0;
    for (i = 0; str2[i] != '\0'; i++)
        lungh2++;

    // concatenazione delle due stringhe
    for (i = 0; i < lungh1; i++){
        str12[i] = str1[i];
    }
    for (i = 0; i < lungh2; i++){
        str12[i+lungh1] = str2[i];
    }
    str12[lungh1+lungh2] = '\0';

    // stampa della stringa concatenata
    printf("%s\n", str12);

    return 0;

}
