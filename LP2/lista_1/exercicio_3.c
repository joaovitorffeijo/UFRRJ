#include <stdio.h>

int main () {
    int num_ast, contador1, contador2, a, b;

    printf("Escreva o numero de fileiras de asteriscos: ");
    scanf("%d", &num_ast);
    contador1 = 0;
    contador2 = 1;

    // while referente ao número de fileiras que serão formadas.
    while (contador1 < num_ast) {
        a = 0;
        b = num_ast;

        // while referente a identação das fileiras.
        while (b > contador2/2) {
            printf(" ");
            b--;
        }

        // while referente a impressão dos asteriscos.
        while (a < contador2) {
            printf("*");
            a++;
        }

        printf("\n");
        contador2 += 2;
        contador1++;        
    }
}