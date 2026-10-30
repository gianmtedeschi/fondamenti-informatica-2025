#include<stdio.h>
#include<stdlib.h>
#include "lista.c"


int ondulatorio(ListaDiElem l);

int main(){

	ListaDiElem l=NULL;

	l=inserisciTesta(l,2);
	l=inserisciTesta(l,1);
	l=inserisciTesta(l,2);
	l=inserisciTesta(l,3);
	l=inserisciTesta(l,4);

	printf("check 1, res: %d\n", ondulatorio(l));

	l=NULL;
	l=inserisciTesta(l,2);
	l=inserisciTesta(l,4);
	l=inserisciTesta(l,1);
	l=inserisciTesta(l,3);

	printf("check 2, res: %d\n", ondulatorio(l));

	return 0;
}

int ondulatorio(ListaDiElem l){
	ListaDiElem iter,p1,p2; //p1 e p2 punteranno agli elementi precedenti
	int c=0;

	while(iter!=NULL){
		c++;
		if(c==1){
			p1=iter;
		}else if (c==2){
			p2=iter;
		}
		else{
			if((p1->dato > p2->dato && p2->dato > iter->dato) ||
				(p1->dato < p2->dato && p2->dato < iter->dato)){
				return 0;
			}else{
				p1=p2;
				p2=iter;
			}
		}
		iter=iter->prox;
	}
	return 1;
}
