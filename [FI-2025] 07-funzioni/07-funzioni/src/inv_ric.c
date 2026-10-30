// Librerie
#include <stdio.h>
#include <string.h>

#define LEN 100

// Prototipi
void invertiStringa(char [], char [], int*);

int main(){
    char src[LEN] = "ciao mamma!", dest[LEN]; 
    int len = 0;

    invertiStringa(src, dest+strlen(src)-1, &len);

    printf("Stringa originale: %s\n", src);
    printf("Stringa invertita: %s\n", dest);

    return 0;
}

// Funzioni
void invertiStringa(char src[], char dest[], int * og_len){
    if(src[0] != '\0'){
        // stringa sorgente non è finita
        // copio nelle attuali celle di memoria
        dest[0] = src[0];
        // incremento il counter di lettere copiate
        (*og_len) = (*og_len) + 1;
        // chiamo ricorsivamente cambiando i contatori
        invertiStringa(src+1, dest-1, og_len);
    }
    else{
        // dest sarà una cella prima dell'inizio e devo puntare alla fine
        dest[*og_len+1] = src[0];
    }
}
