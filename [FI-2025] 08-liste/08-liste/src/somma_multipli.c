#include "lista.c"

int Somma(ListaDiElem lista, int M) {
	int sum = 0;
	if (lista == NULL)
		return -1;
	else {
		while(lista != NULL) {
			if (lista->dato % M == 0)
				sum = sum + lista->dato;
			lista = lista->prox;
		}
		return sum;
	}
}

int Somma_rc(ListaDiElem lista, int M) {
	if (lista == NULL)
		return -1;
	if (lista->prox == NULL) {
		if(lista->dato % M == 0)
			return lista->dato;
		return 0;
	}
	else {
		if(lista->dato % M == 0)
			return lista->dato + Somma_rc(lista->prox, M);
		else
			return Somma_rc(lista->prox, M);
	}
}