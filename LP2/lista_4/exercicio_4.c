#include <stdio.h>

int main () {
    int n, maior = 0, cont = 0;
    
    do {
        printf("Qual o valor do elemento a ser adicionado na lista? [0 para parar]\n");
        scanf("%d", &n);

        if (n == maior) { cont++; }

        if (n > maior) 
        {
            cont = 0;
            maior = n;
            cont++;
        }
        
    } while (n != 0);

    printf("O maior valor digitado foi %d e ele foi digitado %d vezes!", maior, cont);
}