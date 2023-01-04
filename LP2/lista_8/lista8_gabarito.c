/* preenche(...): recebe o vetor espacoR3 como par�metro, l� todos os campos de todos os 10 elementos e, 
ao sair da fun��o, o vetor se mant�m preenchido. Todos os elementos do vetor dever�o ser salvos, 
na medida em que forem sendo preenchidos, no arquivo bin�rio desenho.dat.
� imprime(...): percorre o arquivo desenho.dat do in�cio ao fim, imprimindo todos os campos de cada 
elemento gravado, de forma formatada (exemplo: Ponto A: x = 3, y = 2, z = -1). N�o faz nenhuma altera��o
 no arquivo e n�o retorna nada.
� apaga(...):recebe o vetor espacoR3 e uma letra como par�metro. Percorre o vetor do in�cio ao fim, 
procurando por um elemento cujo campo rotulo seja igual a letra. Quando encontrar, altera o r�tulo do 
ponto para �#�, tanto no vetor, quanto no arquivo desenho.dat. Se o ponto n�o for encontrado, n�o faz nada. */

#include <stdio.h>

typedef struct {
	int x, y, z;
} tpPonto;

typedef struct {
	tpPonto ponto;
	char rotulo;
} tpFigura;

void preenche (tpFigura fig[3]) {
	int i;
	FILE * fp;
	
	fp = fopen("figura.dat", "wb");
	printf ("\nEntre com os valores pedidos:\n");	
	
	for (i=0; i<3; i++) {
		fig[i].rotulo = ' ';
		printf("letra: ");
		scanf("%c", &fig[i].rotulo);
		printf("x: ");
		scanf("%d",&fig[i].ponto.x);
		printf("y: ");
		scanf("%d",&fig[i].ponto.y);
		printf("z: ");
		scanf("%d",&fig[i].ponto.z);
		scanf("%c");  // precisei colocar essa linha pq sen�o o compilador joga o ENTER para a pr�xima letra a ser lida e vai bugar

		fwrite (&fig[i], sizeof(tpFigura), 1, fp);
 
	}
	fclose(fp);
}

void imprime () { 
	int i;
	FILE * fp;
	tpFigura fig[3];
	
	fp = fopen("figura.dat", "rb");
	
	for (i=0; i<3; i++) {
		fread(&fig[i], sizeof(tpFigura),1,fp);
		printf("\nPonto %c = x: %d, y: %d, z: %d ", fig[i].rotulo, fig[i].ponto.x, fig[i].ponto.y, fig[i].ponto.z);
	}
	fclose(fp);
}

void apaga (tpFigura fig[10], char letra) {
	int i;
	FILE * fp;
		
	for (i=0; i<3; i++) {
		if (fig[i].rotulo == letra) {
			printf ("\nO ponto %c sera apagado!", letra);
			fig[i].rotulo = '#';
			break;
		}		
	}	
	fp = fopen("figura.dat", "rb+");
	fseek (fp, i*sizeof(tpPonto), SEEK_SET);
	fwrite (&fig[i], sizeof(tpFigura), 1, fp);
	fclose(fp);
}

main() {
	tpFigura figura[3];
	FILE *f;

	preenche(figura);
	imprime(figura);
	apaga(figura, 'A');
	imprime(figura);
}