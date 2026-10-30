#include <stdio.h>

#define DIM_LIBR 20
#define DIM_NOME 256
#define DIM_DATA 10
#define DIM_CODI 6

typedef struct{
    char nome_corso[DIM_NOME+1];
    int voto;
    char data[DIM_DATA+1];
    char codice[DIM_CODI+1];
} Esame;

int main(){

    //dichiarazioni
    char menu;
    int n_esami = 0;
    int i,j;
    char codice[DIM_CODI];
    int is_equal;
    char cestino;
    //dichiarazione con tipo user-defined
    Esame libretto[DIM_LIBR];

    do {
        system("cls"); //WINDOWS
        //system("clear"); //UNIX
        printf("Scegliere una delle seguenti opzioni:\n");
        printf("[i] inserimento nuovo esame\n");
        printf("[s] stampa del libretto\n");
        printf("[r] ricerca per codice\n");
        printf("[x] uscita\n");
        scanf("%c", &menu);
        scanf("%c", &cestino);

        switch (menu) {
            case 'i':
                //Istruzioni
                printf("Inserisci nome esame: ");
                scanf("%s",libretto[n_esami].nome_corso);
                printf("Inserisci voto: ");
                scanf("%d",&libretto[n_esami].voto);
                printf("Inserisci data: ");
                scanf("%s",libretto[n_esami].data);
                printf("Inserisci codice: ");
                scanf("%s",libretto[n_esami].codice);
                n_esami++;

                break;
            case 's':
                //Istruzioni
                for (i = 0; i < n_esami; i++)
                   // printf() ....

                break;
            case 'r':
                //Istruzioni
                printf("Inserisci il codice da controllare: ");
                scanf("%s",codice);
                for (i = 0; i < n_esami; i++) {
                    //libretto[i].codice == codice;
                    is_equal = 1;
                    for (j = 0; j < DIM_CODI; j++)
                        if (libretto[i].codice[j] != codice[j])
                            is_equal = 0;

                    if (is_equal){
                        //Stampare esame
                    }
                }

                break;

            default:

                break;
        }
    } while (menu != 'x');

}
