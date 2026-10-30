#include <stdio.h>

int main(){
    int numero;

    printf("Inserire un numero da 0 a 10: ");
    scanf("%d",&numero);

    if (numero >= 0 && numero <= 3)
        printf("basso\n");
    else {
        if (numero >= 4 && numero <= 8)
           printf("MediO\n");
        else {
            if (numero >= 9 && numero <= 10)
                printf("ALTO!\n");
            else
                printf("Numero non valido\n");
        }
    }

}
