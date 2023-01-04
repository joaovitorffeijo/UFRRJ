#include <stdio.h>
#include <stdlib.h>

int main () {
    int *v, quant_el;

    printf("Qual o tamanho do vetor? ");
    scanf("%d", &quant_el);

    v = (int *)(malloc(quant_el*sizeof(int)));

    for (int i = 0; i < quant_el; i++) {
        printf("Digite o valor da variavel de indice %d: ", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < quant_el; i++) {
        printf("O valor do elemento de posicao %d é: %d\n", i, v[i]);
    }

    free(v);    
}