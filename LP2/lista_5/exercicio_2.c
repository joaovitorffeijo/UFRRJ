#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int zeraPares (int *x) {

    for (int i = 0; i < 30; i++)
    {
        *(x+i) = i;

        if (*(x+i)%2 == 0)
        { 
            *(x+i) = 0;
        }

        printf("%d ", *(x+i));
    }
}

int dobra (int *x) {

    for (int i = 0; i < 30; i++)
    {
        *(x+i) = i;
        *(x+i) = 2*(*(x+i));

        printf("%d ", *(x+i));
    }
}

int soma (int *x, int *y) {

    for (int i = 0; i < 30; i++)
    {
        *(x+i) = *(y+i) = i;
        *(x+i) += *(y+i);

        printf("%d ", *(x+i));
    }   
}

int main () {
    int lista1[30], lista2[30], K;

    printf("\nItem a: ");
    zeraPares(lista1); // item a.

    printf("\nItem b: ");
    dobra (lista1); // item b.

    printf("\nItem c: ");
    soma (lista1, lista2); //item c.
}