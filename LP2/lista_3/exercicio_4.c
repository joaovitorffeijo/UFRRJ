#include <stdio.h>
#include <math.h>

// Professora, é um problema utilizar a mesma letra para as variáveis das funções e da main? 

float xless10 (float x) {
    float y;

    y = sqrt(x-10)/2;

    return y;
}

float xmore10less4 (float x) {
    float y;

    y = pow(x, 3)/(x*x-16);

    return y;
}

float xmore4 (float x) {
    float y;

    y = sqrt(x*x+1)/2;

    return y;
}

float func (float x) {
    float y;

    if (x >= 10) {
        y = xless10(x);
    } else if (x > 4 && x < 10) {
        y = xmore10less4(x);
    } else {
        y = xmore4(x);
    }

    return y;
}

int main () {
    float x, y;

    printf("Digite o valor de x: ");
    scanf("%f", &x);

    while (x>0) {
        y = func(x);
        printf("O resultado e: %.2f\n\n", y);

        printf("Digite um novo valor para x: ");
        scanf("%f", &x);
    }
}