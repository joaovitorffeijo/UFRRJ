#include <stdio.h>

int main () {
    int n, dado[6] = {0, 0, 0, 0, 0, 0};

    do 
    {
        printf("Qual o resultado do lancamento do dado? [0 para parar]\n");
        scanf("%d", &n);

        if (n == 1) { dado[0]++; }
        if (n == 2) { dado[1]++; }
        if (n == 3) { dado[2]++; }
        if (n == 4) { dado[3]++; }
        if (n == 5) { dado[4]++; }
        if (n == 6) { dado[5]++; }
    } while (n != 0);

    printf("A face 1 saiu %d vezes\n", dado[0]);
    printf("A face 2 saiu %d vezes\n", dado[1]);
    printf("A face 3 saiu %d vezes\n", dado[2]);
    printf("A face 4 saiu %d vezes\n", dado[3]);
    printf("A face 5 saiu %d vezes\n", dado[4]);
    printf("A face 6 saiu %d vezes\n", dado[5]);

    for (int i = 1; i != 6; i++) 
    {
        if (dado[0] < dado[i]) 
        {
            dado[0] = dado[i];
        }
    }

    if (dado[5] == dado[0]) { printf("A face que saiu o maior numero de vezes foi a 6\n"); }
    if (dado[4] == dado[0]) { printf("A face que saiu o maior numero de vezes foi a 5\n"); }
    if (dado[3] == dado[0]) { printf("A face que saiu o maior numero de vezes foi a 4\n"); }
    if (dado[2] == dado[0]) { printf("A face que saiu o maior numero de vezes foi a 3\n"); } 
    if (dado[1] == dado[0]) { printf("A face que saiu o maior numero de vezes foi a 2\n"); } 
    else { printf("A face que saiu o maior numero de vezes foi a 1\n"); }
}