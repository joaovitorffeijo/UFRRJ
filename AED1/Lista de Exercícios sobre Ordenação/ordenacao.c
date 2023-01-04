#include <stdio.h>
#include <stdlib.h>
#define TAM 10 // altera o tamanho do vetor

void vetorAleatorio (int *lista[TAM]) {
    for (int cont = 0; cont < TAM; cont++) {
        lista[cont] = rand() % 100; // cria valores aleatórios para o vetor
    }
}

void imprimeVetor (int *lista[TAM]) {
    for (int contador = 0; contador < TAM; contador++) {
        printf ("%d ", lista[contador]);
    }
}

void bubbleSort (int *lista[TAM]) {
    int i, j, aux;

    for (i = 1; i < TAM; i++) {
        for (j = 0; j < TAM - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

void selectionSort (int *lista[TAM]) {
    int i, j, aux, min;

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
}

void insertionSort (int *lista[TAM]) {
    int i, j, aux;

    for ( int i = 1; i < TAM; i++){
        aux = lista[i];
        j = i - 1;
    while ((j>=0) && (aux < lista[j])) {
        lista[j+1] = lista[j];
        j--; 
    }
    lista[j+1] = aux;
    }
}


int main () {
    int lista[TAM];

    // Ordenação por bolha.
    vetorAleatorio(lista);
    printf("\nVetor nao-ordenado:\n");
    imprimeVetor(lista);
    bubbleSort(lista);
    printf("\nVetor ordenado por bolha:\n");
    imprimeVetor(lista);

    // Ordenação por seleção.
    vetorAleatorio(lista);
    printf("\nVetor nao-ordenado:\n");
    imprimeVetor(lista);
    selectionSort(lista);
    printf("\nVetor ordenado por selecao:\n");
    imprimeVetor(lista);

    // Ordenação por inserção.
    vetorAleatorio(lista);
    printf("\nVetor nao-ordenado:\n");
    imprimeVetor(lista);
    insertionSort(lista);
    printf("\nVetor ordenado por insercao:\n");
    imprimeVetor(lista);
}