// Librerie
#include <stdio.h>

// Costanti
#define R 3
#define C 4

// Prototipi
void leggiArray(int [], int);
void leggiMatrice(int [][C], int, int);
void stampaArray(int [], int);
void stampaMatrice(int [][C], int, int);
void copiaArray(int [], int [], int);
void shiftMatrice(int [][C], int [][C], int, int);

// Main
int main(){
    int src[R][C], dest[R][C];

    leggiMatrice(src, R, C);
    shiftMatrice(dest, src, R, C);

    printf("\nMatrice originale\n");
    stampaMatrice(src, R, C);

    printf("\nMatrice con shift\n");
    stampaMatrice(dest, R, C);

    return 0;
}

// Funzioni
void leggiArray(int v[], int n_colonne){
    int i;
    for(i = 0; i < n_colonne; i++){
        printf("Inserisci elemento in posizione %d: ", i);
        scanf("%d", &v[i]);
    }
    return;
}

void leggiMatrice(int m[][C], int n_righe, int n_colonne){
    int i;
    for(i = 0; i < n_righe; i++){
        printf("Inserisci riga %d\n", i);
        leggiArray(m[i], n_colonne);
        printf("\n");
    }
    return;
}

void stampaArray(int v[], int n_colonne){
    int i;

    printf("[");
    for(i = 0; i < n_colonne; i++){
        printf("%d", v[i]);
        if (i < n_colonne - 1) printf(", ");
    }
    printf("]\n");

    return;
}

void stampaMatrice(int m[][C], int n_righe, int n_colonne){
    int i;
    for(i = 0; i < n_righe; i++){
        stampaArray(m[i], n_colonne);
    }
    return;
}

void copiaArray(int dest[], int src[], int n_colonne){
    int i;
    for(i = 0; i < n_colonne; i++){
        dest[i] = src[i];
    }
    return;
}

void shiftMatrice(int dest[][C], int src[][C], int n_righe, int n_colonne){
    int i;

    for(i = 1; i < n_righe; i++){
        copiaArray(dest[i], src[i-1], n_colonne);
    }

    copiaArray(dest[0], src[n_righe-1], n_colonne);
    return;
}

