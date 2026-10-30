#include <stdio.h>
#define N 100

int main(){
	// Variabili
	int real_N = N, v1[N] = {0}, v2[N] = {0}, i = 0;
	
	// Acquisizione array
	do {
		printf("Quanti numeri vuoi inserire? ");
		scanf("%d", &real_N);
	}
	while(real_N < 0 || real_N > N);
	
	for(i=0; i<real_N; i++){
		printf("Inserire l'elemento in psozione %d: ", i);
		scanf("%d", &v1[i]);
	}
	
	// Copio l'array al contrario E lo stampo
	for(i=real_N-1; i>=0; i--){
		v2[real_N - i - 1] = v1[i];
	}
	
	// Stampo l'array copiato al contrario
	printf("[");
	for(i=0; i< real_N; i++){
		printf(" %d", v2[i]);
	}
	printf("]");
	
	return 0;
}
