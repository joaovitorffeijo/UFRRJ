#include <stdio.h>
#include <math.h>

int fatorial (int m) {
    int fat;
    
    if (m > 1) {
        fat = m * fatorial (m - 1);
    } else {
        return(1);
    }

    return fat;
}

int divisores (int m) {
    int div, quantdiv;
    quantdiv = 0;

    for (div = 1; div <= m; div++) { 
        if (m%div == 0) {
            quantdiv++;
        }
    }

    return quantdiv;
}

int somaint (int m) {
    int soma;
    soma = 0;

    if (m > 0) {
        soma += m+somaint(m-1);
    } else {
        return 0;
    }

    return soma;
}

int main () {
    int m, resultado, resp;
    resultado = resp = 0;

    while (resp != 1) {
        printf("Se m for par sera imprimida a quantidade de divisores de m\n");
        printf("Se m for impar e menor que 10 sera imprimido o fatorial de m\n");
        printf("Se m for impar e maior ou igual a 10 sera imprimida a quantidade de divisores naturais de m\n");
        printf("Digite o valor de m: ");
        scanf("%d", &m);

        if (m%2 == 0) {
            resultado = divisores(m);
            printf("O numero de divisores de m e: %d\n\n", resultado);
        } else if (m%2 == 1 && m < 10) {
            resultado = fatorial(m);
            printf("O fatorial de m e: %d\n\n", resultado);
        } else {
            resultado = somaint(m);
            printf("A soma de todos os numeros naturais de 1 ate m e: %d\n\n", resultado);
        }

        printf("Deseja inserir outro valor de m? [0] Sim [1] Nao\n");
        scanf("%d", &resp);
    }
}