#include <stdio.h>
#define DIM 50

int main(){
	char str1[DIM + 1];
	char str2[DIM + 1];
	int result = 0;
	int trovato = 0;
	int i=0, j=0, temp;

	gets(str1);
	gets(str2);


	while (str2[j] != '\0') {
		if (str2[j] == str1[i]) {
			trovato = 1;
			temp = j;
			while (str1[i] != '\0' && trovato) {
				if (str1[i] == str2[j]) {
					i++;
					j++;
				}
				else {
					trovato = 0;
				}
			}
		if (trovato)
			result++;
		j = temp;
		i=0;
		}
        j++;
	}
    printf("Numero di occorrenze: %d\n", result);
}
