#include <stdio.h>
#include <stdlib.h>

struct tpPonto
{
    int x, y, z;
};

struct tpFigura
{
    struct tpPonto ponto;
    char rotulo;
};

void preenche (struct tpFigura *espacor3) {
    for (int i = 0; i < 10; i++) {
        printf("Informe o rótulo do ponto: ");
        scanf("%c", &(*(espacor3+i)).rotulo);

        printf("Digite o x, o y e o z: ");
        scanf("%d %d %d", &(*(espacor3+i)).ponto.x, &(*espacor3).ponto.y, &(*espacor3).ponto.z);
    }
}

void main () {
    struct tpFigura espacoR3[10];

    preenche(&espacoR3);
}