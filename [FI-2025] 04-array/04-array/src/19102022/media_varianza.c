#include <stdio.h>
#include <math.h>

#define MAX_LEN 20

void main(){

    int n;
    int voti[MAX_LEN];
    int i;
    float sum;
    float media, media_troncata;
    int voto_minimo = 33;
    int voto_massimo = 10;
    float dev, varianza, deviazione_standard;

    //chiedo all'utente quanti esami vuole inserire
    do {
        printf("Inserire il numero degli esami: ");
        scanf("%d",&n);
    } while ( n < 3 || n > 20);

    // ciclo di acquisizione dei voti
    sum = 0;
    for (i = 0; i < n; i++) {
        //acquisisco un voto valido
        do {
            printf("Inserire il voto %d: ",i+1);
            scanf("%d",&voti[i]);
        } while ( voti[i] < 18 || voti[i] > 30);
        //aggiorno voto minimo e voto massimo
        if (voti[i] > voto_massimo)
            voto_massimo = voti[i];
        if (voti[i] < voto_minimo)
            voto_minimo = voti[i];
        //aggiorno la somma dei voti
        sum += voti[i];
    }

    //calcolo media e media troncata
    media = sum / n;
    media_troncata = (sum - voto_massimo - voto_minimo) / (n-2);

    //calcolo varianza e deviazione standard
    dev = 0;
    //ciclo per calcolo della sommatoria
    for (i = 0; i < n; i++)
        dev += (voti[i] - media) * (voti[i] - media);
    varianza = dev / (n - 1);
    deviazione_standard = sqrt(varianza);

    //stampa delle statistiche dei voti
    printf("\nSTATISTICHE VOTI\n");
    printf("Il numero degli esami: %d\n",n);
    printf("La media e': %f\n",media);
    printf("La media troncata e': %f\n",media_troncata);
    printf("La varianza e': %f\n",varianza);
    printf("La deviazione standard e': %f\n",deviazione_standard);

}
