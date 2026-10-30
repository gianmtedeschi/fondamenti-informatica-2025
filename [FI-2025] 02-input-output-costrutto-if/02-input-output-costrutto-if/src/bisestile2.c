#include <stdio.h>

int main() {
    int anno;
    int d4,d100,d400;

    scanf("%d",&anno);

    d4 = anno % 4 == 0;
    d100 = anno % 100 == 0;
    d400 = anno % 400 == 0;

    if ((d4 && !d100) || d400)
        printf("E' bisestile\n");
    else
        printf("Non e' bisestile\n");

}
