#include <stdio.h>
#include <string.h>
#define N 100

int main(int argc, char* argv[]) {
    // Variabili
    char s1[N], s2[N];
    int count[256] = {0}, i, len1, len2, flag = 0;
    
    // Acquisizione stringa 1
    printf("Inserisci la prima stringa: ");
    scanf("%s", s1); fflush(stdin);
    // Salvo la lunghezza della prima stringa
    len1 = (int)strlen(s1);
    
    // Acquisizione stringa 2
    printf("Inserisci la seconda stringa: ");
    scanf("%s", s2);
    // Salvo la lunghezza della seconda stringa
    len2 = (int)strlen(s2);
    
    // Verifico che le stirnghe abbiano la stessa lunghezza
    if(len1 != len2){
        printf("Le stringhe inserite NON sono anagrammi.\n");
        return 0;
    }
    
    // Conto la frequenza dei caratteri in s1 e in s2
    // Nota: si usa len1 in quanto se si è arrivati fino a qui le stringhe hanno la stessa lunghezza
    for(i = 0; i < len1; i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    // Controllo che tutte le frequenze siano uguali
    for(i = 0; i < 256 && !flag; i++){
        if(count[i] != 0){
            flag = 1;
        }
    }
    
    if(flag) printf("Le stringhe inserite NON sono anagrammi.\n");
    else printf("Le stringhe inserite sono anagrammi.\n");
    
    return 0;
}
