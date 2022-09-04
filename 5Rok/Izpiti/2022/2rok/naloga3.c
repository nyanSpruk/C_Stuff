#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, v0, s0, h, w;

char trikotnik(int dim, int currIndexVisine, int currIndexSirine)
{
    if (dim == 1 || currIndexVisine == 0 || currIndexSirine == dim - 1)
        return '*';

    if (currIndexVisine > currIndexSirine)
        return '-';
    else
    {
        if (currIndexVisine >= dim / 2)
            currIndexVisine -= dim / 2;
        if (currIndexSirine >= dim / 2)
            currIndexSirine -= dim / 2;
    }
    return trikotnik(dim / 2, currIndexVisine, currIndexSirine);
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d %d", &n, &v0, &s0, &h, &w);
    long stCrnih = pow(3, n);
    int dimenzija = pow(2, n);
    // printf("Dimenzija je: %d\n", dimenzija);
    printf("%ld\n", stCrnih);
    for (int visina = 0; visina < h; visina++)
    {
        for (int sirina = 0; sirina < w; sirina++)
        {
            char c = trikotnik(dimenzija, visina + v0, sirina + s0);
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
