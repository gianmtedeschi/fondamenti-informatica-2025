#include <stdio.h>

int main() {
    int anno;
    int bisestile;

    printf("\nInserisci il numero dell'anno: ");
    scanf("%d", &anno);

    if (anno % 4 == 0) {
        bisestile = 1;
        if (anno % 100 == 0 && anno % 400 != 0)
            bisestile = 0;
    }else{
        bisestile = 0;
    }

    printf("L'anno %d ", anno);
    if (!bisestile)
        printf("non ");
    printf("e' bisestile\n");

}
