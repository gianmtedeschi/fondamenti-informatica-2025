#include <stdio.h>

int leggiNumeroNaturale();
int sommaDivisori(int);
int numeriAmici(int, int);

int main(){
    // Variabili
    int num1, num2, flag;
    
    // Leggi il numero
    num1 = leggiNumeroNaturale();
    num2 = leggiNumeroNaturale();
    
    // Verifica se il numero è perfetto
    flag = numeriAmici(num1, num2);

    if(flag) printf("%d e %d amici\n", num1, num2);
    else printf("%d e %d non amici\n", num1, num2);
    
    return 0;
}

int leggiNumeroNaturale(){
    int numero;
    
    do {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
    } while(numero < 0);
    
    return numero;
}

int sommaDivisori(int n){
    int i, somma=0;

    for(i=1; i<=n; i++){
        if(n % i == 0) somma += i;
    }

    return somma;
}

int numeriAmici(int n1, int n2){
    int somma1, somma2;
    
    somma1 = sommaDivisori(n1) - n1;
    somma2 = sommaDivisori(n2) - n2;
    
    return somma1 == n2 && somma2 == n1;
}
