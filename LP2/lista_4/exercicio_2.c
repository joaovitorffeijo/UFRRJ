#include <stdio.h>

int main () {
    int vet0a9[10], vet10a19[10], vettotal[20], k = 0;

    for (int i = 0; i < 10; i++) 
    {
        vet0a9[i] = i;
        vet10a19[i] = i+10;
    }

    for (int i = 0; i < 10; i++) 
    {
        vettotal[k] = vet0a9[i];
        vettotal[k+1] = vet10a19[i];

        k = k+2;
    }

    for (int i = 0; i < 20; i++) 
    {
        printf(" %d ", vettotal[20-i]);
    }
}