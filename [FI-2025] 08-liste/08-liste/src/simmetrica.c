#include<stdio.h>
#include<stdlib.h>
#include "lista.c"


ListaDiElem ds(ListaDiElem, ListaDiElem, ListaDiElem);
ListaDiElem ds_testa(ListaDiElem ,ListaDiElem);

int main(){
	ListaDiElem l1=NULL, l2=NULL, res=NULL;

	l1=inserisciCoda(l1,1);
	l1=inserisciCoda(l1,2);
	l1=inserisciCoda(l1,10);
	l1=inserisciCoda(l1,20);
	print_ListaDiElem(l1);

	l2=inserisciCoda(l2,2);
	l2=inserisciCoda(l2,3);
	l2=inserisciCoda(l2,4);
	l2=inserisciCoda(l2,10);
	print_ListaDiElem(l2);

	//res=ds(l1,l2,res);
	res=ds_testa(l1,l2);
	stampaLista(res);

	return 0;
}

ListaDiElem ds(ListaDiElem l1,ListaDiElem l2,ListaDiElem res){
	if(l1==NULL && l2==NULL)
		return res;
	if(l1==NULL || (l2!=NULL && l1->dato > l2->dato)){
		res = inserisciCoda(res,l2->dato);
		return ds(l1,l2->prox,res);
	}
	if(l2==NULL || (l1!=NULL && l2->dato > l1->dato)){
		res = inserisciCoda(res, l1->dato);
		return ds(l1->prox,l2,res);
	}
	return ds(l1->prox,l2->prox,res);
}

// variante con inserimento in testa
ListaDiElem ds_testa(ListaDiElem l1, ListaDiElem l2){
	ListaDiElem tmp;
	// entrambi finiti
	if(l1==NULL && l2==NULL)
		return NULL;
	// elementi uguali, scorro entrambe le liste
	if(l1!=NULL && l2!= NULL && l1->dato==l2->dato)
		return ds_testa(l1->prox, l2->prox);

	//se sono qui devo allocare un nuovo elemento
	tmp=(ListaDiElem)malloc(sizeof(ElemLista));

	if(l2==NULL || (l1!=NULL && l1->dato < l2->dato)){
		tmp->dato=l1->dato;
		l1=l1->prox;
	}else{
		tmp->dato=l2->dato;
		l2=l2->prox;
	}
	tmp->prox=ds_testa(l1,l2);
	return tmp;
}
