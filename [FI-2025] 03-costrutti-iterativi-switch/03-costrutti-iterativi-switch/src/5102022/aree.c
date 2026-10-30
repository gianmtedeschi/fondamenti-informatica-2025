#include <stdio.h>
#include <math.h>

void main(){

    float l; //lato del poligono
    int n; //numero di lati
    float area; //area del poligono regolare con n lati lunghi l

    printf("Inserire la lunghezza del lato ");
    scanf("%f",&l);
    printf("Inserire il numero di lati ");
    scanf("%d",&n);

    switch (n) {
        case 1:
        case 2:
            printf("Il poligono e' degenere");
            break;
        case 3:
            area = l * l * sqrt(3) / 4;
            break;
        case 4:
            area = l * l;
            break;
        case 5:
            area = l * l * 5 / 2 * sqrt(sqrt(5)/10 + 0.25);
            break;
        case 6:
            area = l * l * sqrt(3) * 3 / 2;
            break;
        default:
            printf("Poligono non supportato");
    }

    if (n > 2 && n < 7)
        printf("L'area del poligono regolare con %d lati e' %f", n, area);

}
