#include <stdio.h>
#include <math.h>

int main(){

    int a,b,c;
    int sum_a, sum_b, sum_c;
    int diff_a, diff_b, diff_c;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    /* somma maggiore del terzo*/
    sum_a = b+c > a;
    sum_b = a+c > b;
    sum_c = a+b > c;

    /* differenza minore del terzo*/
    diff_a = abs(b-c) < a;
    diff_b = abs(a-c) < b;
    diff_c = abs(a-b) < c;

    printf("I tre numeri");
    if (!(sum_a && sum_b && sum_c && diff_a && diff_b && diff_c))
         printf(" non");
    printf(" sono i lati di un triangolo\n");

}
