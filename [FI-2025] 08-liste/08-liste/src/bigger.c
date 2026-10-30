#include<stdio.h>
#include<stdlib.h>
#include "lista.c"

#define N 5

ListaDiElem last_bigger(ListaDiElem, int);
void ins_last_bigger(ListaDiElem, int);

int main(){
	ListaDiElem l=NULL;
	int i;

	for(i=N;i>0;i--)
		l=inserisciTesta(l,i);
	stampaLista(l);

	ins_last_bigger(l,3);
	ins_last_bigger(l,12);
	ins_last_bigger(l,4);
	stampaLista(l);


	return 0;
}

ListaDiElem last_bigger(ListaDiElem l, int n){
	ListaDiElem cur=NULL;
	while(l!=NULL){
		if((l->dato)>n)
			cur=l;
		l=l->prox;
	}
	return cur;
}


//NB: si può restituire void in questo caso perché la testa non può cambiare
void ins_last_bigger(ListaDiElem l, int n){
	ListaDiElem temp,new_el;

	temp=last_bigger(l, n);

	if(temp!=NULL){
		new_el=(ListaDiElem) malloc(sizeof(ElemLista));
		new_el->dato=n;
		new_el->prox=temp->prox;
		temp->prox=new_el;
	}
}