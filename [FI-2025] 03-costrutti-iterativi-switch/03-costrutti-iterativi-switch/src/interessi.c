#include <stdio.h>
#include <stdlib.h>

int main() {
    float c_in;
    float c_finale;
    float tasso, tasso_perc, tasso_tot, tasso_anni;
    int anni;
    int i, j;
    
    printf("Inserisci capitale iniziale: ");
    scanf("%f", &c_in);
    printf("Inserisci tasso d'interesse: ");
    scanf("%f", &tasso);
    printf("Inserisci numero di anni: ");
    scanf("%d", &anni);
    
    printf("Capitale iniziale: %6.2f\n", c_in);
    for (i=1; i<=anni; i++)
    {
        tasso_anni = 1;
        tasso_perc = tasso/100;
        tasso_tot = 1 + tasso_perc;
        
        for (j=1; j<=i; j++){
            tasso_anni=tasso_anni*tasso_tot;
        }    
        
        c_finale = c_in * tasso_anni;
        printf("Capitale dopo %d anni: %6.2f\n", i, c_finale);
    }
    return 0;
}