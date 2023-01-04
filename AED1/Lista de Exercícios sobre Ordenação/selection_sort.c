#include <stdio.h>
#include <stdlib.h>
#define TAM 100 // altera o tamanho do vetor

/* ALGORITMO ERRADO - by Lorena Vasconsellos */

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

  // algoritmo de ordenação por seleção
  for (i = 0; i < TAM - 1; i++) {
    min = i;
    for (j = i + 1; j < TAM; j++) {
      if (lista[j] < lista[min]) {
        min = j;
      }
    if (i != min) {
      aux = lista[i];
      lista[i] = lista[min];
      lista[min] = aux;
    }
    }
  }

  printf ("\nVetor ordenado:\n");
  for (int contador = 0; contador < TAM; contador++) {
    printf ("%d ", lista[contador]);
  }
  
}