#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

bool rekurzija(int n, int k, bool poteza)
{
    if (n <= k)
        return poteza;

    bool zmagaBeli;
    if (poteza)
    {
        zmagaBeli = false;
        for (int i = 1; i <= k; i++)
        {
            zmagaBeli = zmagaBeli | rekurzija(n - i, k, false);
        }
    }
    else
    {
        zmagaBeli = true;
        for (int i = 1; i <= k; i++)
        {
            zmagaBeli = zmagaBeli & rekurzija(n - i, k, true);
        }
    }
    return zmagaBeli;
}

void izrisi(int ostanek, int k, int x, int *poteze, int indexPoteze)
{
    if (ostanek == 0)
    {
        printf("%d", poteze[0]);
        for (int i = 1; i < indexPoteze; i += 2)
        {
            printf(" -> [%d] -> %d", poteze[i], poteze[i + 1]);
        }
        printf("\n");
    }
    else if (x == 0)
    {
        for (int i = 1; i <= k; i++)
        {
            poteze[indexPoteze] = i;
            izrisi(ostanek - i, k, k - i + 1, poteze, indexPoteze + 1);
        }
    }
    else
    {
        poteze[indexPoteze] = x;
        izrisi(ostanek - x, k, 0, poteze, indexPoteze + 1);
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    // n = 10;
    // k = 3;

    bool crniZmaga = true;
    int *poteze = malloc(sizeof(int) * n);
    if (k > n)
    {
        printf("%d\n", n);
        crniZmaga = false;
    }
    else
    {
        for (int i = 1; i <= min(k, n); i++)
        {
            if (rekurzija(n - i, k, false))
            {
                poteze[0] = i;
                izrisi(n - i, k, 0, poteze, 1);
                crniZmaga = false;
            }
        }
    }
    free(poteze);
    if (crniZmaga)
        printf("CRNI\n");
    return 0;
}
