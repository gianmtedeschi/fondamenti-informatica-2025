#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

#define N 10

ListaDiElem Reverse1(ListaDiElem lista, int keep);
ListaDiElem Reverse2(ListaDiElem lista);

int main () {

	ListaDiElem lis = NULL;
	ElemLista * max;
	int i;
	
	for (i = N; i > 0; i--) 
		lis = InsInTesta(lis, i);
	
	stampaLista(lis);
	printf("\n");	
	
	lis = Reverse1(lis, 0);
	
	stampaLista(lis);
	printf("\n");	
	
	lis = Reverse2(lis);
	
	stampaLista(lis);
	printf("\n");
	
}	

ListaDiElem Reverse1(ListaDiElem lista, int keep) {
   ListaDiElem temp = NULL, curr = lista;
   while(curr != NULL) {
      temp = inserisciTesta(temp, curr->dato); 
      curr = curr->prox;
   }
   if(!keep)
      eliminaLista(lista);
   return temp;
}

ListaDiElem Reverse2(ListaDiElem lista) {
    ListaDiElem temp, prec = NULL;
    if(lista != NULL)  {  
	  while(lista->prox != NULL) {
	     temp = prec;
	     prec = lista;
	     lista = lista->prox;
	     prec->prox = temp;
	  }
	  lista->prox = prec;
    }
    return lista;
}

ListaDiElem Reverse2_rc(ListaDiElem lista) {
     ListaDiElem p, ris;
     if (lista == NULL || lista->prox == NULL)
          return lista;
     else {
          p = lista->prox;
          ris = Reverse2_rc(p);
          p->prox = lista;
          lista->prox = NULL;
          return ris;
     }
}

