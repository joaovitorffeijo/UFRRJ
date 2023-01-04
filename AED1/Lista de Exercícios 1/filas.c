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
    int primeiro;
    int ultimo;
    int nItens;
} fila;

void criarFila (fila *f, int c ) {
	f->capacidade = c;
	f->dados = (tcliente*) malloc(f->capacidade*sizeof(tcliente));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
}

void insereCliente (fila *f) {
    if(f->ultimo == f->capacidade-1) 
        f->ultimo = -1; // Volta com o apontador para o começo;
    f->ultimo++;
    f->nItens++;

    printf("Digite o CPF do cliente: ");
    scanf("%d", &f->dados[f->ultimo].cpf);
    printf("Insira o saldo do cliente: ");
    scanf("%f", &f->dados[f->ultimo].saldo);
}

void removeCliente (fila *f) {
    f->primeiro++;
    if (f->primeiro == f->capacidade)
        f->primeiro = 0;
    f->nItens--;
    
    printf("\nRemovido com sucesso.\n");
}

int verificarCadastro(fila *f) {
    int cpftemp;

    printf("\nDigite o CPF do cliente: ");
    scanf("%d", &cpftemp);

    if (f->primeiro < f->ultimo) {
        for (int i = f->primeiro; i <= f->ultimo; i++) {
            if (f->dados[i].cpf == cpftemp) {
                printf("\nEste CPF ja esta cadastrado.\n");
                return 0;
            } 
        }
    } else {
        for (int i = 0; i < f->ultimo; i++) {
            if (f->dados[i].cpf == cpftemp) {
                printf("\nEste CPF ja esta cadastrado.\n");
                return 0;
            } 
        }
        for (int i = f->primeiro; i < f->capacidade; i++) {
            if (f->dados[i].cpf == cpftemp) {
                printf("\nEste CPF ja esta cadastrado.\n");
                return 0;
            } 
        }
    }
    
    printf("\nEste CPF não está cadastrado.\n");
    
    return 0;
}

int atualizarSaldo(fila *f) {
    int cpftemp, botao;
    float valor;

    printf("\nDigite o CPF do cliente: ");
    scanf("%d", &cpftemp);

    for (int i = 0; i < f->capacidade; i++) {
        if (f->dados[i].cpf == cpftemp) {
            printf("Depósito [1]\n");
            printf("Saque    [2]\n");
            printf("O que deseja fazer? ");
            scanf("%d", &botao);

            switch (botao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);

                f->dados[i].saldo += valor;
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);

                f->dados[i].saldo -= valor;
                break;
            default:
                printf("Voce nao digitou um numero valido - OPERACAO CANCELADA");
                break;
            }
            
            printf("Saldo atual: %.2f\n", f->dados[i].saldo);

            return 0;
        } 
    }
    
    printf("CPF Incorreto\n");
}

int main () {
    fila *pfila;
    int quant, botao = 0;

    printf("Quantos clientes o seu pode ter? ");
    scanf("%d", &quant);

    criarFila(pfila, quant);

    while (botao != 5) {
        printf("------------BANCO PICA DAS GALÁXIAS------------\n");
        printf("Inserir novo cliente                        [1]\n");
        printf("Remover cliente ja cadastrado               [2]\n");
        printf("Atualizar saldo de cliente                  [3]\n");
        printf("Verificar se cliente está cadastrado        [4]\n");
        printf("Sair                                        [5]\n");
        printf("\nQual opcao deseja? ");
        scanf("%d", &botao);

        switch (botao) {
            case 1:
                insereCliente(pfila);
                break;
            case 2:
                removeCliente(pfila);
                break;
            case 3:
                atualizarSaldo(pfila);
                break;
            case 4:
                verificarCadastro(pfila);
                break;
            default:
                printf("Voce nao digitou um numero valido\n");
                break;
        }
    }
    
}