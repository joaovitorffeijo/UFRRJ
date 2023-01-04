#include <stdio.h>

int fatorial (int x) {
    int fator = x;
    
    if (fator > 1) {
        fator = x*fatorial(x-1);
    } else 
    {
        return (1);
    }

    return fator;
}

float xelevy (float x, float y) {
    float total;

    if (y != 0) 
    {
        total = x*xelevy(x, y-1);
    } 
    else {
        return (1);
    }

    return total;
}

float xvezesy (float x, float y) {
    float mult;

    if (x == 0 || y == 0) {
        return 0;
    } else {
        mult = x + xvezesy(x, y - 1);
    }

    return mult;
}

float xmody (float x, float y) {
    float mod;

    if (x < y) {
        return x;
    } else {
        mod = xmody(x-y, y);
    }

    return mod;
}

int seqfibonacci (int x) {
    
    if (x == 1) {
        return (1);
    } else if (x == 2) {
        return (1);
    } 
    
    return (seqfibonacci(x - 1)+seqfibonacci(x - 2));
}

int main () {
    float x, y, res;
    int opcao = 1;

    while (opcao !=2 && opcao == 1) {

        printf("CALCULADORA ESPECIAL\n");
        printf("Fatorial de N [1]\n");
        printf("X elevado a Y [2]\n");
        printf("X*Y [3]\n");
        printf("X mod Y [4]\n");
        printf("Sequencia de N termos de Fibonacci [5]\n\n");
        printf("Digite o numero relativo a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o valor de N: ");
            scanf("%f", &x);

            y = fatorial(x);

            printf("O valor do fatorial de N e: %.2f", y);

            break;
        case 2:
            printf("Informe o valor de x: ");
            scanf("%f", &x);
            printf("Informe o valor de y: ");
            scanf("%f", &y);

            res = xelevy(x, y);

            printf("O resultado de x elevado a y e: %.2f\n", res);

            break;
        case 3:
            printf("Informe o valor de x: ");
            scanf("%f", &x);
            printf("Informe o valor de y: ");
            scanf("%f", &y);

            res = xvezesy(x, y);

            printf("O resultado de x multiplicado por y e: %.2f\n", res);

            break;
        case 4:
            printf("Informe o valor de x: ");
            scanf("%f", &x);
            printf("Informe o valor de y: ");
            scanf("%f", &y);

            res = xmody(x, y);

            printf("O resultado de mod y e: %.2f\n", res);

            break;
        case 5:
            printf("Digite o valor de N: ");
            scanf("%f", &x);

            for (int i = 1; i <= x; i++) {
                printf (" %d ", seqfibonacci(i));
            }
            break;
        default:
            printf("Voce nao digitou um numero valido ;-;\n");
            break;
        }

        printf("Deseja continuar? [1] Sim [2] Nao\n");
        scanf("%d", &opcao);
    }
}