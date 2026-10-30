#include <stdio.h>

int main(){

    int n,m;
    int sum_n, sum_m;
    int i;
    printf("Primo numero: ");
    scanf("%d",&n);
    printf("Secondo numero: ");
    scanf("%d",&m);

    printf("Divisori di %d: ",n);
    sum_n = 0;
    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d,",i);
            sum_n += i;
        }
    }
    printf("\n");

    printf("Divisori di %d: ",m);
    sum_m = 0;
    for (i = 1; i <= m / 2; i++) {
        if (m % i == 0) {
            printf("%d,",i);
            sum_m += i;
        }
    }
    printf("\n");

    if (sum_n == m && sum_m == n)
        printf("I due numeri sono amicali\n");
    else
        printf("I due numeri non sono amicali\n");

}
