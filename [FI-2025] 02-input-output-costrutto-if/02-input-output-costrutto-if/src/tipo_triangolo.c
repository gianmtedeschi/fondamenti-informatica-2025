#include <stdio.h>
#include <math.h>

int main(){

    int a,b,c;
    int sum_a, sum_b, sum_c;
    int diff_a, diff_b, diff_c;
    int is_triangolo;
    int ipotenusa, somma;

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

    is_triangolo = sum_a && sum_b && sum_c && diff_a && diff_b && diff_c;
    printf("I tre numeri");
    if (!is_triangolo)
         printf(" non");
    printf(" sono i lati di un triangolo");

    if (is_triangolo) {
        if (a == b && b == c)
            printf(" equilatero");
        else {
            if (a != b && a!= c && c != b)
                printf(" scaleno");
            else
                printf(" isoscele");
            // controllo se � rettangolo
            if (a >= b && a >= c) {
                ipotenusa = a * a;
                somma = b*b + c*c;
            }
            if (b > a && b >= c) {
                ipotenusa = b * b;
                somma = a*a + c*c;
            }
            if (c >= a && c >= b) {
                ipotenusa = c * c;
                somma = a*a + b*b;
            }
            if (ipotenusa == somma)
                printf(" (rettangolo)");
        }
    }
    printf("\n");
}

