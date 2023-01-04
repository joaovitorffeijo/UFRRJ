#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

void maiusc (char *frase) {
    for (int i = 0; i < 30; i++)
    {
        if (*(frase+i) >= 97 && *(frase+i) <= 122 ) 
        {
            *(frase+i) -= 32;
        }
    }
}

void concatena (char *frase1, char *frase2, char *frases_concatenadas) {
    char frase_subs1[30], frase_subs2[30];
    int k1 = 0, k2 = 0;

    for (int i = 0; i < 30; i++) 
    {
        frase_subs1[i] = *(frase1+i);
        *(frase1+i) = 0;
        if (frase_subs1[i] != 32)
        {
            *(frase1+k1) = frase_subs1[i];
            k1++;
        } // Elimina todos os espaços da primeira frase.
    }

    k1 = 0;

    for (int i = 0; i < 30; i++) 
    {
        frase_subs2[i] = *(frase2+i);
        *(frase2+i) = 0;
        if (frase_subs2[i] != 32)
        {
            *(frase2+k1) = frase_subs2[i];
            k1++;
        } // Elimina todos os espaços da segunda frase. 
    }

    k1 = 0;

    while (*(frase1+k1) != '\0')
    {
        *(frases_concatenadas+k1) = *(frase1+k1);
        k1++;
    }
    while (*(frase2+k2) != '\0')
    {
        *(frases_concatenadas+k1) = *(frase2+k2);
        k2++;
        k1++;
    } // Os whiles servem pra fazer a atribuição dos caracteres na string relativa a concatenacao.

    for (int i = 0; i < 30; i++) 
    {
        *(frase1+i) = frase_subs1[i];
        *(frase2+i) = frase_subs2[i];
    } // Retornando os valores originais aos caracteres das frases.
}

void capitaliza (char *frase) {
    if (*frase >= 97 && *frase <= 122)
    {
        *frase -= 32;
    } // Capitalizacao da primeira letra.
    
    for (int i = 0; i < 30; i++)
    {
        if (*(frase+i-1) == 32 && *(frase+i) >= 97 && *(frase+i) <= 122) 
            {
                *(frase+i) -= 32;
            }
    } // Capitalizacao das demais letras.
}

int compara (char *frase1, char *frase2) {
    int k, cont1, cont2;
    cont1 = cont2 = 0;
    
    while (*(frase1+cont1) != '\0')
    {
        cont1++;
    } // Calcula o tamanho da frase 1.

    while (*(frase2+cont2) != '\0')
    {
        cont2++;
    } // Calcula o tamanho da frase 2.

    if (cont1 > cont2)
    {
        k = 1;
    } else if (cont1 < cont2)
    {
        k = -1;
    } else 
    {
        k = 0;
    }
    
    return k;
}

void main () {
    char FRASE1[30], FRASE2[30], FRASES_CONCATENADAS[60];

    printf("Digite a primeira frase: ");
    gets (FRASE1);
    printf("Digite a segunda frase: ");
    gets (FRASE2);

    maiusc(FRASE1);
    printf("\n\n1.a. = %s\n", FRASE1);

    concatena(FRASE1, FRASE2, FRASES_CONCATENADAS);
    printf("1.b. = %s\n", FRASES_CONCATENADAS);

    capitaliza(FRASE2);
    printf("1.c. = %s\n", FRASE2);

    printf("1.d. = %d", compara(FRASE1, FRASE2));
}