#include <stdio.h>
 
 int main () {
    int num, mult, fator;

    fator = 100;

    printf("Escreva um numero: ");
    scanf("%d", &num);

    if (num < 10) {
        while (fator >= 2) {
            mult = num*fator;

            if (mult <= 100) {
                printf("%d, ", mult);
            }
            fator--;
        }
        printf("%d", num);
        
    } else {
        printf("Voce nao digitou um numero valido =(");
    }
    
 }