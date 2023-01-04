#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    char nomealuno[40], curso[40];
    int idade, cr, matricula;
} tpAluno;

typedef struct {
    int nota, faltas;
    tpAluno dados;
} tpAlunoMat;

typedef struct {
    int codigo;
    char nome[40];
    tpAlunoMat turma[40];
} disciplina;

FILE *openfile (char *nome) {
    FILE *arq;

    if ((arq = fopen(nome, "a+")) == NULL) {
        printf("\nO arquivo %s nao pode ser aberto!", nome);
        
        return NULL;
    }

    return arq;
} // O que significa esse "*" antes do nome da função?

void criardisciplina (FILE *arqdisciplina, disciplina *a) {
    
    printf("\nDigite o codigo da disciplina: ");
    scanf("%d", &a->codigo);
    printf("Digite o nome o nome da disciplina: ");
    scanf("%s", &a->nome);

    for (int i = 0; i < 40; i++) {
        a->turma[i].dados.matricula = 0;
    }
    
    arqdisciplina = openfile("disciplina.txt");
    fprintf(arqdisciplina, "Disciplina 1:\n Codigo: %d\n Nome: %s\n", a->codigo, a->nome);
    fclose(arqdisciplina);
} // *arqdisciplina já é um ponteiro, quando eu passo para a função ele funciona como referência ou parâmetro?

void incluiraluno (FILE *arqalunos, disciplina *a) {
    int cont = 0;

    arqalunos = openfile("alunos.txt");

    for (int i = 0; i < 40; i++) {
        if (a->turma[i].dados.matricula == 0 && cont == 0) {
            printf("\nDigite a matricula do aluno: ");
            scanf("%d", &a->turma[i].dados.matricula);

            fprintf(arqalunos, "Matricula: %d\n", a->turma[i].dados.matricula);

            cont++;
        }   
    }

    fclose(arqalunos);
}

main () {
    FILE *arqdisciplina, *arqaluno;
    int op = 0;
    disciplina a; // Como permitir a criação de mais de uma disciplina sem utilizar vetores?

    do
    {
        printf("\n------ MENU DE OPCOES ------\n");
        printf("Criar Disciplina         [1]\n");
        printf("Incluir Aluno            [2]\n");
        printf("Excluir Aluno            [3]\n");
        printf("Listar Alunos            [4]\n");
        printf("Calcular CR Medio        [5]\n");
        printf("Imprimir Boletim         [6]\n");
        printf("Fechar Disciplina        [7]\n");
        printf("Sair                     [8]\n");
        printf("------------------------- ");
        scanf("%d", &op);

        switch (op) {
        case 1: criardisciplina(arqdisciplina, &a);
            break;
        case 2: incluiraluno(arqaluno, &a);
            break;
        default:
            break;
        }
    } while (op != 8);
}