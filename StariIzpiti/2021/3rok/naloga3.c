#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Oseba
{
    int indeks;
    struct _Oseba *prviOtrok;
    struct _Oseba *drugiOtrok;
} Oseba;

Oseba *neki(int iskanaVred, int *starsi, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (starsi[i] == iskanaVred)
        {
            Oseba *otrok = malloc(sizeof(Oseba));
            otrok->indeks = i;
            starsi[i] = -2;
            otrok->prviOtrok = neki(i, starsi, n);
            if (otrok->prviOtrok == NULL)
            {
                otrok->drugiOtrok = NULL;
                return otrok;
            }
            otrok->drugiOtrok = neki(i, starsi, n);
            return otrok;
        }
    }
    return NULL;
}

Oseba *zgradi(int n, int *starsi)
{
    Oseba *zacetnik = malloc(sizeof(Oseba));
    for (int i = 0; i < n; i++)
    {
        if (starsi[i] == -1)
        {
            zacetnik->indeks = i;
            zacetnik->prviOtrok = neki(i, starsi, n);
            zacetnik->drugiOtrok = neki(i, starsi, n);
        }
    }
    return zacetnik;
}

int main(int argc, char const *argv[])
{
    int starsi[] = {4, 5, 8, 1, 1, -1, 4, 8, 5};
    int n = 9;
    Oseba *main = zgradi(n, starsi);
    printf("Index zacetnika je %d\n", main->indeks);
    printf("Prvi otrok index je %d\n", main->prviOtrok->indeks);
    printf("Drugi otrok index je %d\n", main->drugiOtrok->indeks);
    return 0;
}
