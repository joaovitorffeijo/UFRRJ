#include <stdio.h>
#include <stdlib.h>

void inicializa (int *a, int *b, int *c) {
    printf("Digite o dia: ");
    scanf("%d", &(*a));

    printf("Digite o mes: ");
    scanf("%d", &(*b));

    printf("Digite o ano: ");
    scanf("%d", &(*c));
}

void valida (int a, int b, int c) {
    if (b >= 1 && b <= 12)
    {
        if (b == 2 && a >= 1 && a <= 28)
        {
            printf("\nA data e valida!");
        } else if (a >= 1 && a <= 31)
        {
            printf("\nA data e valida!");
        }
    } else 
    {
        printf("\nA data nao e valida!");
    }
}

void imprime (int a, int b, int c) {
    printf("\nO dia mencionado foi o %d do mes %d do ano %d", a, b, c);
}

void main () {
    struct data {
        int dia, mes, ano;
    } data1;
    
    inicializa (&data1.dia, &data1.mes, &data1.ano);
    valida (data1.dia, data1.mes, data1.ano);
    imprime (data1.dia, data1.mes, data1.ano);
}

// Só vi que era pra declarar a struct globalmente quando já havia terminado. xD.