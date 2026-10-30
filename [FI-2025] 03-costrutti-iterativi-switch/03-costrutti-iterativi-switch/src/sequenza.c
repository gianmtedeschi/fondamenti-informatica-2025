#include <stdio.h>

int main(){
    int cifra;
    int curVal = 0, oldVal = 0, somma = 0, sommaMax = 0;
    
    do
    {
        printf("Inserisci una cifra (0-9): ");
        scanf("%d", &cifra);
        curVal = cifra;
        if (curVal < oldVal)
        {
            if (somma > sommaMax){
                sommaMax = somma;
            }
            somma = curVal;
        }
        else{
            somma = somma + curVal;
        }
        
        oldVal = curVal;
    } while (curVal != 0);
    
    printf("Massima somma trovata: %d\n", sommaMax);

    return 0;
}


