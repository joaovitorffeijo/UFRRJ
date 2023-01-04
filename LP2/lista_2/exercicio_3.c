#include <stdio.h>

int main () {
    int idade, num_media, den_media, cont;
    float media;

    cont = num_media = den_media = 0;

    do {
        printf("Digite a idade: ");
        scanf("%d", &idade);

        if (idade > 21) {
            cont++;
        }
        if (idade > 60) {
            num_media += idade;
            den_media++;
        }
    } while (idade >= 0);
    
    media = num_media/den_media;
    printf("O numero de pessoas com mais de 21 anos e: %d\n", cont);
    printf("A media de idade das pessoas com mais de 60 anos e: %.2f\n", media);
}