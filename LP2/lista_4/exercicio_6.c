#include <stdio.h>

int main () {
    int A[3][5], soma_linha[3] = {0, 0, 0};

    for (int a = 0; a < 3; a++) 
    {
        for (int b = 0; b < 5; b++) 
        {
            A[a][b] = a+b;
        }
    }

    for (int a = 0; a < 3; a++) 
    {
        for (int b = 0; b < 5; b++) 
        {
            soma_linha[a] += A[a][b];
        }
    }

    for (int a = 0; a < 3; a++) 
    {
        printf(" %d\n", soma_linha[a]);
    }
}