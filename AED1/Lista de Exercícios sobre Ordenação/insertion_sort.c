#include <stdio.h>
#include <stdlib.h>
#define TAM 10 // altera o tamanho do vetor

int main () {

    int lista[TAM];
    int i, j, min, aux;

    for (int cont = 0; cont < TAM; cont++) {
    lista[cont] = rand() % 100; // cria valores aleatórios para o vetor
    }

    printf ("Vetor inicial:\n");
    for (i = 0; i < TAM; i++) {
    printf ("%d ", lista[i]);
    }

    // algoritmo de ordenação por inserção
    for ( int i = 1; i < TAM; i++){
        aux = lista[i];
        j = i - 1;
    while ((j>=0) && (aux < lista[j])) {
        lista[j+1] = lista[j];
        j--; 
    }
    lista[j+1] = aux;
    }

    printf ("\nVetor ordenado:\n");
    for (int contador = 0; contador < TAM; contador++) {
    printf ("%d ", lista[contador]);
    }
}