#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

#define N 10

typedef struct EL {
    float dato;
    struct EL * prox;
} ElemLista;

int Picchi(ListaDiElem lis);
int Picchi_rc(ListaDiElem lis);

int main () {

	ListaDiElem lis = NULL;
	
	lis = inserisciTesta(lis, 5);
	lis = inserisciTesta(lis, 11);
	lis = inserisciTesta(lis, 4);
	lis = inserisciTesta(lis, 9);
	lis = inserisciTesta(lis, 3);
	lis = inserisciTesta(lis, 5);	
	
	stampaLista(lis);
	printf("\n");	
	
	printf("Numero Picchi: %d\n", Picchi(lis));	
	printf("Numero Picchi (Ricorsivo): %d\n", Picchi_rc(lis));	
	
}	

int Picchi(ListaDiElem lis) {
	int n = 0;
	while(lis != NULL && lis->prox != NULL && lis->prox->prox != NULL){

		if(((float)(lis->dato) < (float) (lis->prox->dato)/2)  &&
			((float)(lis->prox->prox->dato) < (float) (lis->prox->dato)/2))
			n++;

		lis = lis->prox;
	}
	return n;
}

int Picchi_rc(ListaDiElem lis) {
	if( !(lis != NULL && lis->prox != NULL && lis->prox->prox != NULL) )
    	return 0;
    if(((float)(lis->dato) < (float) (lis->prox->dato)/2)  &&
		((float)(lis->prox->prox->dato) < (float) (lis->prox->dato)/2))
		return 1 + Picchi_rc(lis->prox) ;
    else
    	return Picchi(lis->prox) ;
}
