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
    int topo;
} pilha;

void criarPilha (pilha *f, int c) {
    f->topo = -1;
    f->capacidade = c;
    f->dados = (tcliente *) malloc(c*sizeof(tcliente));
}

void insereCliente (pilha *f) {
    if (f->topo == f->capacidade) 
        printf("pilha lotada\n");
    f->topo++;

    printf("Digite o CPF do cliente: ");
    scanf("%d", &f->dados[f->topo].cpf);
    printf("Insira o saldo do cliente: ");
    scanf("%f", &f->dados[f->topo].saldo);
}

void removeCliente (pilha *f) {
    if (f->topo == -1)
        printf("Esta pilha nao possui nenhum elemento\n");
    f->topo--;
}

int atualizarSaldo (pilha *f) {
    int cpftemp, botao;
    float valor;

    printf("\nDigite o CPF do cliente: ");
    scanf("%d", &cpftemp);

     for (int i = 0; i <= f->topo; i++) {
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

int verificarCadastro (pilha *f) {
    int cpftemp;

    printf("\nDigite o CPF do cliente: ");
    scanf("%d", &cpftemp);


    for (int i = 0; i <= f->topo; i++) {
        if (f->dados[i].cpf == cpftemp) {
            printf("\nEste CPF ja esta cadastrado.\n");
            return 0;
        } 
    }

    printf("\nEste CPF não está cadastrado.\n");
    
    return 0;
}

int main () {
    pilha *ppilha;
    int quant, botao = 0;

    printf("Quantos clientes o seu pode ter? ");
    scanf("%d", &quant);

    criarPilha(ppilha, quant);

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
                insereCliente(ppilha);
                break;
            case 2:
                removeCliente(ppilha);
                break;
            case 3:
                atualizarSaldo(ppilha);
                break;
            case 4:
                verificarCadastro(ppilha);
                break;
            default:
                printf("Voce nao digitou um numero valido\n");
                break;
        }
    }
}