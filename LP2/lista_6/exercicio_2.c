#include <stdio.h>
#include <stdlib.h>

// Professora, não inicializei as variáveis como "notas" e "faltas" porque não foi solicitado na lista e daria muito trabalho.

struct aluno {
    char nomealuno[40], curso[40];
    int idade, cr, matricula;
};

struct alunomat {
    int nota, faltas;
    struct aluno aluno1;
};

struct disciplina {
    int codigo;
    char nome[40];
    struct alunomat turma[40];
};

void main () {
    int k, k_case2, k_case3, k_case5;
    float cr_case5;
    struct disciplina disciplina1;
    k = k_case2 = k_case3 = k_case5 = cr_case5 = 0;

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
        scanf("%d", &k);

        switch (k) {
            case 1:
                disciplina1.codigo = 40028922;
                printf("\nDigite o nome da disciplina: ");
                scanf("%s", &disciplina1.nome);
                for (int i = 0; i <= 40; i++) {
                    disciplina1.turma[i].aluno1.matricula = 0;
                }
                
                break;
            case 2:
                for (int i = 0; i <= 40; i++) {
                    if (disciplina1.turma[i].aluno1.matricula == 0 && k_case2 == 0) {
                        printf("\nDigite a matricula do aluno: ");
                        scanf("%d", &disciplina1.turma[i].aluno1.matricula);

                        k_case2++;
                    }
                }

                if (k_case2 == 0) {
                    printf("Nao existem vagas nessa disciplina.\n");
                }
                k_case2 = 0;

                break;
            case 3:
                printf("Digite o numero da matricula a qual sera excluida: ");
                scanf("%d", &k_case3);
                for (int i = 0; i <= 40; i++) {
                    if (disciplina1.turma[i].aluno1.matricula == k_case3) {
                        disciplina1.turma[i].aluno1.matricula = 0;
                    }    
                }

                break;
            case 4:
                for (int i = 0; i <= 40; i++) {
                    if (disciplina1.turma[i].aluno1.matricula != 0) {
                        printf("\n-- DADOS DO ALUNO --\n");
                        printf("Nome: %s\n", disciplina1.turma[i].aluno1.nomealuno);
                        printf("Matricula: %d\n", disciplina1.turma[i].aluno1.matricula);
                        printf("Idade: %d\n", disciplina1.turma[i].aluno1.idade);
                        printf("CR: %d\n", disciplina1.turma[i].aluno1.cr);
                        printf("Nota: %d\n", disciplina1.turma[i].nota);
                        printf("Faltas: %d\n", disciplina1.turma[i].faltas);
                    }
                }

                break;
            case 5:
                for (int i = 0; i <= 40; i++) {
                    if (disciplina1.turma[i].aluno1.matricula != 0)
                    {
                        cr_case5 += disciplina1.turma[i].nota;
                        k_case5++;
                    }
                }
                cr_case5 = cr_case5/k_case5;
                printf("\nO cr medio da disciplina e: %d", cr_case5);
                
                break;
            case 6:
                for (int i = 0; i <= 40; i++) {
                    if (disciplina1.turma[i].aluno1.matricula != 0) {
                        printf("\n-- BOLETIM DO ALUNO --\n");
                        printf("Nome: %s\n", disciplina1.turma[i].aluno1.nomealuno);
                        printf("Matricula: %d\n", disciplina1.turma[i].aluno1.matricula);
                        printf("Nota: %d\n", disciplina1.turma[i].nota);
                        printf("Faltas: %d\n", disciplina1.turma[i].faltas);
                    }
                }

                break;
            case 7:
                disciplina1.codigo = 0;
                for (int i = 0; i <= 40; i++) {
                    disciplina1.nome[i] = '0';
                }
                printf("\nDisciplina fechada");

                break;
            case 8:
                printf("\nObrigado por usar nossa calculadora!");
                break;
            default:
                printf("\nVoce nao digitou um numero valido\n\n");
                break;
        }
    } while (k != 8);
}

// Refazer utilizando funções e passagem de estruturas por ponteiros.