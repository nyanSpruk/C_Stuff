#include <stdio.h>
#include <stdlib.h>

void izpisi(int *cleni, int stClenov)
{
    for (int i = 0; i < stClenov; i++)
    {
        if (i > 0)
            printf(" + ");
        printf("%d", cleni[i]);
    }
    printf("\n");
}

void funkcija(int n, int k, int *cleni, int counterClenov)
{
    if (k > n)
        k = n;
    if (k == 0)
    {
        if (n == 0)
        {
            izpisi(cleni, counterClenov);
            return;
        }
        return;
    }

    cleni[counterClenov] = k;
    funkcija(n - k, k, cleni, counterClenov + 1);
    funkcija(n, k - 1, cleni, counterClenov);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *cleni = malloc(n * sizeof(int));
    int stClenov = 0;
    funkcija(n, k, cleni, stClenov);
    return 0;
}
