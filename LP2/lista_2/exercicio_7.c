#include <stdio.h>

int main () {
    int prato, beb, sobre, soma;

    soma = 0;

    // Prato Principal
    printf("----PRATO PRINCIPAL----\n");
    printf("1 - Vegetariano\n");
    printf("2 - Peixe\n");
    printf("3 - Frango\n");
    printf("4 - Carne\n");
    printf("-----------------------\n \n");
    printf("Escolha o numero referente ao prato principal desejado: ");
    scanf("%d", &prato);

    switch (prato) {

    case 1:
        soma += 180;
        break;
    case 2:
        soma += 230;
        break;
    case 3:
        soma += 250;
        break;
    case 4:
        soma += 350;
        break;
    default:
        printf("Vai ficar sem refeicao\n \n");
    }

    // Bebida
    printf("---------BEBIDA--------\n");
    printf("1 - Cha (lata)\n");
    printf("2 - Suco de laranja\n");
    printf("3 - Suco de melao\n");
    printf("4 - Refrigerante diet\n");
    printf("-----------------------\n \n");
    printf("Escolha o numero referente a bebida desejada: ");
    scanf("%d", &beb);

    switch (beb) {

    case 1:
        soma += 80;
        break;
    case 2:
        soma += 150;
        break;
    case 3:
        soma += 70;
        break;
    case 4:
        soma += 2;
        break;
    default:
        printf("Vai ficar sem bebida\n \n");
    }

    // SOBREMESA
    printf("----PRATO PRINCIPAL----\n");
    printf("1 - Abacaxi\n");
    printf("2 - Sorvete diet\n");
    printf("3 - Mousse diet\n");
    printf("4 - Mousse chocolate\n");
    printf("-----------------------\n \n");
    printf("Escolha o numero referente a sobremesa desejada: ");
    scanf("%d", &sobre);

    switch (sobre) {

    case 1:
        soma += 75;
        break;
    case 2:
        soma += 110;
        break;
    case 3:
        soma += 60;
        break;
    case 4:
        soma += 250;
        break;
    default:
        printf("Vai ficar sem sobremesa, bobao\n \n ");
    }

    printf("\nA quantidade de calorias da refeicao e: %d", soma);
}