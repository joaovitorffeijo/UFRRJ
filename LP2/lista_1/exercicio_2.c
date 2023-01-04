#include <stdio.h>
#include <math.h>

// não adicionei comentários porque a estrutura do programa é bem simples.

int main () {
    float num1, num2;
    int validacao, selecionador;

    do {
        printf("-------------------------\n");
        printf("---CALCULADORA HUMILDE---\n");
        printf("-------------------------\n");
        printf("        Soma [1]         \n");
        printf("      Subtracao [2]      \n");
        printf("    Multiplicacao [3]    \n");
        printf("       Divisao [4]       \n");
        printf("    Exponenciacao [5]    \n");
        printf("      Logaritmo [6]      \n");
        printf("    Raiz Quadrada [7]    \n");
        printf("-------------------------\n");
        printf("Digite o numero referente a operacao desejada: ");
        scanf("%d", &selecionador);
        
        switch (selecionador)
        {
        case 1:
            printf("Informe os numeros a serem somados:\n");
            scanf("%f %f", &num1, &num2);
            printf("A soma entre eles e: %.2f\n", num1+num2);
            break;
        case 2:
            printf("Informe os numeros a serem subtraidos: ");
            scanf("%f %f", &num1, &num2);
            printf("A diferenca entre eles e: %.2f", num1-num2);
            break;
        case 3:
            printf("Informe os numeros a serem multiplicados: ");
            scanf("%f %f", &num1, &num2);
            printf("O produto entre eles e: %.2f", num1*num2);
            break;
        case 4:
            printf("Informe os numeros a serem divididos: ");
            scanf("%f %f", &num1, &num2);
            printf("A razao entre eles e: %.2f", num1/num2);
            break;
        case 5:
            printf("Informe o numero e seu expoente: ");
            scanf("%f %f", &num1, &num2);
            printf("O resultado dessa potencia e: %.2f", pow(num1,num2));
            break;
        case 6:
            printf("Informe o logaritmando: ");
            scanf("%f", &num1);
            printf("O logaritmo na base 10 desse numero e: %.2f", log10(num1));
            break;
        case 7:
            printf("Informe o numero a ser racionalizado: ");
            scanf("%f", &num1);
            printf("A raiz quadrada desse numero e: %.2f", sqrt(num1));
            break;
        default:
            printf("Voce nao digitou um numero valido");
            break;
        }

        printf("\nDeseja realizar outra operacao? sim [1] ou nao [0]\n");
        scanf("%d", &validacao);
    } while (validacao != 0 && validacao == 1);
}

/* Professora, não consegui usar os limpatela, por isso a execução está um pouco poluída. */