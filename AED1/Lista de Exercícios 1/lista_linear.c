#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cpf ;
    char nome[50];
    char endereco[50];
    char tel[10];
    float saldo;
} tcliente;

typedef struct {
    int capacidade;
    tcliente *dados;
    int ultimo;
} lista;

void criarLista (lista *f, int c) {
    f->capacidade = c;
    f->dados = (tcliente*) malloc(f->capacidade*sizeof(tcliente));
    f->ultimo = 0;
}

int main () {
    lista *plista; 
    int quant;

    printf("Quantos clientes o seu banco tem? ");
    scanf("%d", &quant);

    criarLista(plista, quant);
}

// A estrutura do enunciado está diferente da estrutura da questão.