#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

#define N 5


int monotona(ListaDiElem l);
int monotona_ric(ListaDiElem l);


int main () {
	ListaDiElem l=NULL;

	l=inserisciTesta(l,5);
	l=inserisciTesta(l,4);
	l=inserisciTesta(l,3);

	stampaLista(l);
	printf("Res: %d\n",monotona_ric(l));

	l=inserisciTesta(l,3);
	stampaLista(l);

	printf("Res: %d\n",monotona_ric(l));
	
	
	return 0;	
}	

int monotona(ListaDiElem l){
	ListaDiElem c1=l, c2;

	if(c1!=NULL)
		c2=c1->prox;

	while(c2!=NULL){
		if(c2->dato>=c1->dato)
			return 0;
		c1=c2;
		c2=c2->prox;
	}
	return 1;
}

int monotona_ric(ListaDiElem l){
	if(l==NULL || l->prox==NULL){
		return 1;
	}
	if(l->dato >= l->prox->dato)
		return 0;
	else{
		return monotona_ric(l->prox);
	}
}
