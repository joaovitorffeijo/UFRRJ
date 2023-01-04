#include <stdio.h>
#include <math.h>

// Obs.: O valor do ângulo inserido deve estar em radianos.

int main () {
    float x, senx, fat, i;
    int contador_1, contador_2, contador_3, expoente;

    contador_1 = 0;
    contador_2 = 7;
    expoente = 1;
    i = 2; // i recebe inicialmente o valor 2 porque o primeiro termo da equação é positivo.

    printf("Digite o numero que deseja calcular o seno: ");
    scanf("%f", &x);

    // while referente ao loop geral, fazendo o programa gerar 10 equações.
    while (contador_1 < 10) {

        // while referente a formação das equações.
        while (contador_2 >= expoente) {

            contador_3 = expoente;
            // for referente ao cálculo do fatorial.
            for(fat = 1; contador_3 > 1; contador_3 = contador_3-1) {

                fat *= contador_3;
            }
            senx += (pow(x, expoente)/fat)*pow((-1), i);
            i++;
            expoente += 2;
        }
        contador_2 += 2;
        contador_1 += 1;
        printf("%.16f\n", senx);
    }
}