#include <stdio.h>

int main () {
    int num, div, resto;

    do {
        printf ("\nDigite um numero: ");
        scanf("%d", &num);
        
        for (div = 1; div <= num; div++) {
            resto = num%div;
            
            if (resto == 0) {
                printf("%d ", div);
            }
        }
    } while (num >= 0);
}