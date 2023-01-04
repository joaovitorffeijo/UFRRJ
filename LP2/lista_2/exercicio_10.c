#include <stdio.h>

// Não compreendi com clareza o enunciado dessa questão.

int main () {
    float saldo, trans, valor_trans;
    int entraousai, resposta, cont_trans;

    resposta = saldo = entraousai = cont_trans = 0;

    while (resposta != 1) {
        
        printf("Informe o saldo da conta no inicio do dia: ");
        scanf("%f", &saldo);

        while (resposta != 1) {
            
            printf("Deseja realizar um deposito ou fazer uma retirada?\n ");
            printf("[1] Deposito [2] Retirada\n");
            scanf("%d", &entraousai);
            if (entraousai == 1) {
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &trans);
                saldo += trans;
            } 
            if (entraousai == 2) {
                printf("Digite o valor a ser debitado: ");
                scanf("%f", &trans);
                saldo -= trans;
            }

            printf("Deseja realizar outra transacao? \n");
            printf("[0] Sim [1] Não\n");      
            scanf("%d", &resposta);      

            cont_trans++;
        }
        printf("O numero de transacoes realizadas e: %d\n", cont_trans);

        if (saldo < 30) { saldo -= 3; }
        if (saldo < 0) {
            printf("Nao ha fundos\n");
        } else {
            printf("O saldo da sua conta e: %.2f\n", saldo);
        }
        
        printf("Deseja operar em uma nova conta? \n");
        printf("[0] Sim [1] Não\n");
        scanf("%d", &resposta);  
    }
}