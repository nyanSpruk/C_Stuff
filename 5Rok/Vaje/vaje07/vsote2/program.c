#include <stdio.h>
#include <stdlib.h>

void izpisiVsoto(int *cleni, int stClenov)
{
    for (int i = 0; i < stClenov; i++)
    {
        if (i > 0)
            printf(" + ");
        printf("%d", cleni[i]);
    }
    printf("\n");
}

long fun(int n, int k, int *cleni, int stClenov)
{
    if (k > n)
        k = n;
    if (k == 0)
    {
        if (n == 0)
        {
            izpisiVsoto(cleni, stClenov);
            return 1;
        }
        return 0;
    }

    cleni[stClenov] = k;
    int a = fun(n - k, k, cleni, stClenov + 1);
    int b = fun(n, k - 1, cleni, stClenov);
    return a + b;
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    long vsota = 0;
    int *cleni = malloc(n * sizeof(int));
    int stClenov = 0;
    vsota = fun(n, k, cleni, stClenov);
    // printf("%ld\n", vsota);
    return 0;
}
