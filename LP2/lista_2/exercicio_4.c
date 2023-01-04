#include <stdio.h>

int main () {
    int divisor, dividendo, quociente, resto;
    
    printf("Digite o quociente da divisao: ");
    scanf("%d", &dividendo);
    printf("Digite o divisor: ");
    scanf("%d", &divisor);

    quociente = 0;
    resto = dividendo;

    do {
        resto -= divisor;
        quociente++;
    } while (resto >= divisor);
    
    printf("O resto da divisao e %d e o quociente e %d", resto, quociente);
}