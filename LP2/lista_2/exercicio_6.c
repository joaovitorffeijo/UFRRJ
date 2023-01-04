#include <stdio.h>

int main () {
    float pais_A, pais_B;
    int t;

    pais_A = 5000000;
    pais_B = 7000000;
    t = 0;

    do {
        pais_A += 0.03*pais_A;
        pais_B += 0.02*pais_B;
        t += 1;

    } while (pais_A <= pais_B);

    printf("O tempo necessario e %d anos", t);
    
}