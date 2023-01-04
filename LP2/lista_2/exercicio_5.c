#include <stdio.h>

int main () {
    int cont, num, cont_par, soma, maior, menor;
    float percent, media;

    printf("Digite um numero: ");
    scanf("%d", &num);

    maior = cont = soma = cont_par = 0;
    menor = num;

    while (num > 0) {
        
        cont++;
        if (num%2 == 0) { cont_par++; } else  { soma += num; }
        if (num > maior) { maior = num; }
        if (num < menor) { menor = num; }
        
        printf("Digite um numero: ");
        scanf("%d", &num);
    }

    printf("A quantidade de numeros validos digitada foi: %d\n", cont);

    percent = (cont_par*100)/cont;
    printf("O percentual de numeros pares digitado foi: %.2f\n", percent);

    media = soma/(cont-cont_par);
    printf("A media dos numeros impares e: %.2f\n", media);

    printf("O maior numero digitado foi %d e o menor foi %d", maior, menor);
}