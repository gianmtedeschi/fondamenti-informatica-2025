#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(){

    char str1[MAX_LEN+1], str2[MAX_LEN+1];
    int lungh1, lungh2;
    int i = 0;

    printf("Inserire la prima stringa: ");
    gets(str1);
    fflush(stdin);

    while ((str2[i] = str1[i]) != '\0') {
        i++;
    }


    printf("Copia: \"%s\"\n", str2);

    return 0;

}

