#include <stdio.h>

int leggiNumeroNaturale();
int sommaDivisori(int);
int numeroPerfetto(int);

int main(){
    // Variabili
    int num, flag;
    
    // Leggi il numero
    num = leggiNumeroNaturale();
    
    // Verifica se il numero è perfetto
    flag = numeroPerfetto(num);

    if(flag) printf("%d perfetto\n", num);
    else printf("%d non perfetto\n", num);
    
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

int numeroPerfetto(int numero){
    int somma;
    
    somma = sommaDivisori(numero);
    
    return somma - numero == numero;
}
