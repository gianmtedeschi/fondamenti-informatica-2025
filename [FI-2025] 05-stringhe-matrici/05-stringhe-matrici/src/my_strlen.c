#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(){

    char str1[MAX_LEN+1];;
    int len;
    int i;

    printf("Inserire la stringa: ");
    gets(str1);
    fflush(stdin);

    // strlen prima stringa
    len = 0;
    for (i = 0; str1[i] != '\0'; i++)
        len++;

    // stampa della stringa concatenata
    printf("%d\n", len);

    return 0;

}
