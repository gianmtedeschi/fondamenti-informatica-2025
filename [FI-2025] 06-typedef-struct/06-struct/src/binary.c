#include <stdio.h>
#include <math.h>

#define MAX_DIGIT 10

int main() {

int n_10, temp, i, nDigit, maxVal;
int n_2[MAX_DIGIT];

maxVal = pow(2 , MAX_DIGIT) - 1;
do
{
    printf("Inserire il nr base 10: ");
    scanf("%d" , &n_10);
}while(n_10 > maxVal || n_10 <0);

temp = n_10;
nDigit = 0;

while(temp > 0)
{
    n_2[nDigit] = temp % 2;
    temp = temp / 2;
    nDigit++;
}

printf("%d in base 2 diventa: " , n_10);
for(i = nDigit - 1 ; i >= 0 ; i--)
    printf("%d", n_2[i]);

}
