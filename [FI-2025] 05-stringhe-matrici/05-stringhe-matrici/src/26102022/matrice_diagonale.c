#include <stdio.h>

#define MAX_DIM 20

typedef enum{falso, vero} Booleano;

void main(){

    //dichiarazioni
    int matrice[MAX_DIM][MAX_DIM];
    int dim_matr;
    int i,j;
    Booleano is_diagonale, is_simmetrica;

    //acquisizione dimensione
    do {
        printf("Inserire la dimensione della matrice quadrata: ");
        scanf("%d",&dim_matr);
    } while (dim_matr < 0 || dim_matr > MAX_DIM);

    //acquisizione elementi [i][j]
    for(i = 0; i < dim_matr; i++)
        for(j = 0; j < dim_matr; j++) {
            printf("Inserire l'elemento in posizione [%d][%d]: ",i+1,j+1);
            scanf("%d",&matrice[i][j]);
        }

    //controllo se diagonale
    is_diagonale = vero;
    // controllo elementi sulla diagonale
    for (i = 0; i < dim_matr; i++) {
        if (matrice[i][i] == 0)
            is_diagonale = falso;
        }
    //controllo elementi non sulla diagonale
    if (is_diagonale) {
        for(i = 0; i < dim_matr; i++)
            for(j = 0; j < dim_matr; j++) {
                if (i != j && matrice[i][j] != 0)
                    is_diagonale = falso;
            }
    }

    //controllo se simmetrica
    is_simmetrica = vero;
    for(i = 0; i < dim_matr; i++) {
        for(j = i+1; j < dim_matr; j++) {
            if (matrice[i][j] != matrice[j][i])
                is_simmetrica = falso;
        }
    }

    //stampa risultato del controllo
    if (is_diagonale)
        printf("La matrice e' diagonale e simetrica\n");
    else {
        if (is_simmetrica)
            printf("La matrice non e' diagonale, ma simmetrica\n");
        else
            printf("La matrice non e' diagonale, ne' simmetrica\n");
    }

}
