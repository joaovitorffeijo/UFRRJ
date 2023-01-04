#include <stdio.h>
#include <stdlib.h>
#define TAM 10 // altera o tamanho do vetor

int main () {

  int lista[TAM];
  int i, j, aux;

  for (int cont = 0; cont < TAM; cont++) {
    lista[cont] = rand() % 100; // cria valores aleatórios para o vetor
  }

  printf ("Vetor inicial:\n");
  for (i = 0; i < TAM; i++) {
    printf ("%d ", lista[i]);
  }

  // algoritmo de ordenação BubbleSort
  for (i = 1; i < TAM; i++) {
    for (j = 0; j < TAM - 1; j++) {
      if (lista[j] > lista[j + 1]) {
        aux = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = aux;
      }
    }
  }

  printf ("\nVetor ordenado:\n");
  for (int contador = 0; contador < TAM; contador++) {
    printf ("%d ", lista[contador]);
  }

}