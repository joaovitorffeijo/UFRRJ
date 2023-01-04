#include <stdio.h>

int main () {
    int M[4][5], dobro[4][5], soma[4][5];

    for (int a = 0; a < 4; a++) 
    {
        for (int b = 0; b < 5; b++) 
        {
            M[a][b] = a+b;
        }
    }

    for (int a = 0; a < 4; a++) 
    {
        for (int b = 0; b < 5; b++) 
        {
            dobro[a][b] = 2*M[a][b];
        }
    }
    
    for (int a = 0; a < 4; a++) 
    {
        for (int b = 0; b < 5; b++) 
        {
            soma[a][b] = M[a][b]+dobro[a][b];
            printf(" %d ", soma[a][b]);
        }
        printf("\n");
    }   
}