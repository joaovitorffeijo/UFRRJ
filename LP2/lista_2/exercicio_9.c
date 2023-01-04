#include <stdio.h>

int main () {
    int age, maior_age, menor_age, grau, grau10, opniao, num_pessoas, soma_otimo, num_otimo, resposta;
    float percentual;

    maior_age = soma_otimo = grau10 = num_otimo = num_pessoas = 0;
    menor_age = 100;

    while (resposta != 1) {
        
        printf("Ola, qual a sua idade? ");
        scanf("%d", &age);
        if (age < menor_age) { menor_age = age; }
        if (age > maior_age) { maior_age = age; }

        printf("Qual o seu grau de instrucao (em anos)? ");
        scanf("%d", &grau);
        
        printf("Qual a sua opniao sobre o filme? \n");
        printf(" [1] Otimo\n [2] Regular\n [3] Pessimo\n");
        scanf("%d", &opniao);

        if ((grau > 10) && (opniao == 3)) { grau10++; }
        /* Professora, o if acima não funcionava quando eu colocava a seguinte condição: (grau > 10 && opniao == 3)
        Por quê?*/

        if (opniao == 1) {
            soma_otimo += age;
            num_otimo++;
        }
        
        num_pessoas++;

        printf("Deseja cadastrar um novo espectador? [0] Sim [1] Nao\n");
        scanf("%d", &resposta);
    }

    percentual = 100*grau10/num_pessoas;

    printf("A media das idades das pessoas que responderam otimo e: %d\n", soma_otimo/num_otimo);
    printf("A idade do espectador mais novo e %d e a do mais velho e %d\n", menor_age, maior_age);
    printf("O percentual de pessoas com mais de 10 anos de instrucao que responderam pessimo e %.2f%%\n", percentual);
}