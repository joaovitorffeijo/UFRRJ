#include <stdio.h>

int main () {
    char frase[100];
    int cont = 0, i = 0;

    printf("Insira uma frase: ");
    gets(frase);

    while (frase[i] != '\0')
    {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') 
        {
            for (int j = 0; j < cont; j++) 
            {
                printf("%c", frase[i]);
            }
            cont++;
        }
        printf("%c", frase[i]);

        i++;
    }
    
}