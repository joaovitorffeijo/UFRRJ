//1) Reescreva o segundo exerc�cio da Lista 6, usando arquivos do tipo texto e alterando algumas
//  das fun��es pedidas anteriormente, conforme descrito a seguir:
// - CRIAR DISCIPLINA - adicionar a disciplina criada no arquivo disciplinas.txt 
// - INCLUIR ALUNO - adicionar os dados do aluno criado no arquivo alunos.txt 
// - LISTAR ALUNOS - imprimir os dados a partir da leitura do arquivo alunos.txt 
// - IMPRIMIR BOLETIM - al�m de imprimir na tela, a fun��o dever� escrever os mesmo dados
//  no arquivo boletins.txt

#include <stdio.h>

typedef struct {
	char nome[30];
	int idade;
	float cr;
	long int matricula;
} tpAluno;

typedef struct {
	tpAluno aluno;
	float notas[3]; 
	int faltas;
} tpAlunoMat;

typedef struct {
	int codigo;
	char nome[30];
	tpAlunoMat turma[40];
} tpDisc;

FILE * abrirArquivo (char * nome) { 
	FILE * s; 
	
	if( (s=fopen(nome,"a+")) == NULL ) { // se o arquivo existe, vou abrir para acr�scimo			
		printf("Arquivo %s n�o pode ser aberto\n", nome); 
	 	return NULL;  
 	}
	  	
 	return s;
}

void criarDisciplina (FILE * fD, tpDisc * disc, int * cod) { 
	int i;
	
	disc->codigo = *cod;
	(*cod)++;  
	printf("\nEntre com o nome dados da disciplina a ser criada:");
	scanf("%s", disc->nome); // Pq a atribuição não foi feita utilizando o &? 
	
	for (i=0; i<40; i++) {
		disc->turma[i].aluno.matricula = 0;	
		printf("\nDisciplina %s criada com sucesso!", disc->nome);
	} // Zera todas as matrículas da discilpina após criar a disciplina.
	
	fD = abrirArquivo("disciplinas.txt");
	fprintf(fD,"%s %d\n", disc->nome, disc->codigo);
	fclose(fD); // Abre o arquivo utilizando a função e escreve o nome da disciplina e seu código.
}

void incluirAluno (FILE * fA, tpDisc * disc) {
	int i;
	tpAluno aluno;
	
	fA = abrirArquivo("alunos.txt");
	
	printf("\n\nEntre com os dados do aluno:");
	printf("\nNome:");
	scanf("%s", &aluno.nome);
	printf("Idade:");
	scanf("%d", &aluno.idade);
	printf("CR:");
	scanf("%f", &aluno.cr);
	printf("Matricula:");
	scanf("%ld", &aluno.matricula);
	// Atribui os dados as variáveis.
	
	for (i=0; i<40; i++) {
		if (disc->turma[i].aluno.matricula == 0) {
			disc->turma[i].aluno = aluno;
			disc->turma[i].notas[0] = disc->turma[i].notas[1] = disc->turma[i].notas[2] = 0;
			disc->turma[i].faltas = 0;
			fprintf(fA,"%s %ld %d %.1f\n", aluno.nome, aluno.matricula, aluno.idade, aluno.cr);
			break;
		}
	}
	
	fclose(fA);
}

void listarAlunos (FILE * fA) {
	int i;
	FILE * s;
	tpAluno aluno;

	fA = abrirArquivo("alunos.txt");
	rewind(fA);
	
	printf("\n\nListagem de Alunos do Curso de Sistemas de Informa�ao" );
	printf("\n\nAluno\tMatricula\tIdade\tCR");

	while(!feof(fA))  {
		fscanf(fA,"%s %ld %d %f", aluno.nome, &aluno.matricula, &aluno.idade, &aluno.cr);
		printf("\n%s \t%ld \t%d \t%.1f", aluno.nome, aluno.matricula, aluno.idade, aluno.cr);
	}

	fclose(fA);
}

void calculaCrMedio (tpDisc disc) {
	int i;
	float soma=0, cont=0, media;
	
	for (i=0; i<40; i++) {
		if (disc.turma[i].aluno.matricula != 0) {
			soma += disc.turma[i].aluno.cr;
			cont++;
		}
	}
	media = soma/cont;
	printf("\n\nO CR medio dos alunos matriculados em %s eh de %.1f", disc.nome, media);
}

void imprimirBoletim (FILE * fB, tpDisc disc) {
	int i, vazia = 1;

	fB = abrirArquivo("boletins.txt");
	
	printf("\n\nAluno\t\tMatricula\tP1\tP2\tOPT\tFaltas\tCR");
	
	for (i=0; i<40; i++) {
		if (disc.turma[i].aluno.matricula != 0) {
			vazia = 0;   // a formatacao do relatorio ficou ruim, mas nao tive tempo para acertar
			printf("\n%s %10ld %10.1f %10.1f %10.1f %10d %10.1f", disc.turma[i].aluno.nome,
				disc.turma[i].aluno.matricula, disc.turma[i].notas[0], disc.turma[i].notas[1],
				disc.turma[i].notas[2], disc.turma[i].faltas, disc.turma[i].aluno.cr );
			fprintf(fB,"%s %ld %.1f %.1f %.1f %d %.1f\n", disc.turma[i].aluno.nome,
				disc.turma[i].aluno.matricula, disc.turma[i].notas[0], disc.turma[i].notas[1],
				disc.turma[i].notas[2], disc.turma[i].faltas, disc.turma[i].aluno.cr );
		}
	}
	if (vazia)
		printf("\nA turma %d esta vazia", disc.codigo);
		
	fclose(fB);
}

void fecharDisciplina (tpDisc * disc) { 
	int i;

	strcpy(disc->nome, " ");
	disc->codigo = 0;   // acabei usando um codigo num�rico...
	
	for (i=0; i<40; i++)
		disc->turma[i].aluno.matricula = 0;	
}

main () {
	tpDisc disc; 
	tpAluno aluno;
	char nomeDisc[30];
	int op = 1, cod = 1000;  
	FILE *fD, *fA, *fB;
	
	//OBS: O programa poderia ter ficado infinitamente melhor, mas aqui est� o que o 
	// enunciado pediu e eu	 nem tive tempo para fazer mais do que o pedido ;)
	
	while (op != 7) {
		printf("\n\nUFRRJ - Curso de Sistemas de Informacao - SIGAA");
		printf("\n-----------------------------------------------");
		printf("\nEscolha a opcao desejada:");
		printf("\n1 - Criar disciplina");
		printf("\n2 - Incluir aluno");
		printf("\n3 - Listar alunos");
		printf("\n4 - Imprimir boletins");
		printf("\n5 - Calcular CR medio");
		printf("\n6 - Fechar disciplina");
		printf("\n7 - Encerrar\nOpcao: ");
		scanf("%d", &op);
	
		switch (op) {
			case 1: criarDisciplina(fD, &disc, &cod);  
					break;
			case 2: incluirAluno (fA, &disc );
					break;
			case 3: listarAlunos(fA);	
					break;
			case 4: imprimirBoletim(fB, disc);
					break;
			case 5: calculaCrMedio(disc);
					break;
			case 6: fecharDisciplina(&disc);
					break;				
		}
	}
}

