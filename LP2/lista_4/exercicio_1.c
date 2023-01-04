#include <stdio.h>

int main () {
    int nome[20], cont = 1, transicao;

    // atribuicao dos valores ao vetor
    for (int i = 0; i != 20; i++) 
    {
        nome[i] = cont;
        cont++;

        printf(" %d ", nome[i]);
    }

    printf("\n");  

    // troca entre as posicoes do vetor
    for (int i = 0; i != 10; i++) 
    {
        transicao = nome[i];
        nome[i] = nome [19-i];
        nome[19-i] = transicao;
    }

    // impressao dos valores dos vetores invertidos
    for (int i = 0; i != 20; i++) 
    {
        printf(" %d ", nome[i]);
    }
}

