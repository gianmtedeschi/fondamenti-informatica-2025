#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 32

typedef struct {
    char name[DIM];
    int points;
} User;

int readPoints (char usersFile[], User results[], int maxDim, int minPoints){
    FILE * f; int logicDim = 0;
    
    f = fopen(usersFile, "rb");
    if (f == NULL) 
        return -1;
    
    while(logicDim<maxDim && fread( &results[logicDim], sizeof(User), 1, f) > 0) {
        if (results[logicDim].points >= minPoints)
            logicDim++;
    }

    fclose(f);
    return logicDim;
}


int main() {
    User * V; int i, maxUtenti; int logicDim, minPoints;
    
    printf("Inserire numero massimo di utenti da leggere: ");
    scanf("%d", &maxUtenti);
    
    V = (User *) malloc(sizeof(User) * maxUtenti);
    if (V == NULL) 
        return -1;

    printf("Inserire punteggio minimo: ");
    scanf("%d", &minPoints);
    logicDim = readPoints("punti.dat", V, maxUtenti, minPoints);
    if (logicDim < 0) 
        return -1;
    
    for (i=0; i<logicDim; i++){
        if ((V[i].name[0] == 'M') && (V[i].name[1] == 'e')) {
            printf("L'utente %s ha %d punti.\n", V[i].name, V[i].points);
        }
    }
    
    free(V);
    return 0;
}