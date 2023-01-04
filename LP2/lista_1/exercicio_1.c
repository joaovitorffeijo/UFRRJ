#include <stdio.h>

int main () {
    int numero, contador, soma, maiornum, menornum;
    float media;

    printf("Digite o numero: ");
    scanf("%d", &numero);
    maiornum = soma = menornum = numero;
    contador = 1;

    // while referente a leitura dos valores.
    while (numero != 999) {
        printf("Digite o numero: ");
        scanf("%d", &numero);
        contador++;
        soma += numero;

        // if's referentes a atribuição do maior e do menor valor.
        if (numero > maiornum) {
            maiornum = numero;
        }

        if (numero < menornum) {
            menornum = numero;
        }
    }

    media = soma/contador;
    printf("A quantidade de numeros lidos e: %d\n", contador);
    printf("A media entre eles e: %.2f\n", media);
    printf("O maior entre eles e: %d\nE o menor e: %d", maiornum, menornum);
}