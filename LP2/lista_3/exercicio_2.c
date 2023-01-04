#include <stdio.h>
#include <math.h>

// Professora, gostaria de algumas dicas de identação ao utilizar funções, estou achaando o código bem feio.

float ypos (float a) {
    float y;
    int fator;

    fator = 1;
    y = 0;

    while (fator != 101) {
        y += (a+fator)/fator;

        fator++;
    }

    return y;
}

float yneg (float a) {
    float y;
    int fator, i;

    fator = y = i = 0;

    while (fator != 101) {
        y += (a*a+fator)*(pow(-1, i))/(101-fator);
        
        fator++;
        i++;
    }
    return y;
}

int main () {
    float x, y;

    printf("Digite o valor de x: ");
    scanf("%f", &x);

    if (x > 0) {
        y = ypos(x);
    } else {
        y = yneg(x);
    }
    
    printf("O valor de y e %.2f", y);
}