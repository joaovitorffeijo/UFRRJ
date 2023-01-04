#include <stdio.h>

int main () {
    int num, fator;

    printf("De qual numero deseja calcular a tabuada? ");
    scanf("%d", &num);

    for (fator = 1; fator <= 10; fator++) {
        
        printf("%d x %d = %d\n", num, fator, num*fator);
    }    
}