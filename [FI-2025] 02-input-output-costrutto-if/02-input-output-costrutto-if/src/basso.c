#include <stdio.h>

int main(){
    int numero;

    printf("Inserire un numero da 0 a 10: ");
    scanf("%d",&numero);

    if (numero >= 0 && numero <= 3)
        printf("basso\n");
    if (numero >= 4 && numero <= 8)
        printf("MediO\n");
    if (numero >= 9 && numero <= 10)
        printf("ALTO!\n");
    if  (numero < 0 || numero > 10)
        printf("Numero non valido\n");

}
