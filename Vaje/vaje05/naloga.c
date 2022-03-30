
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int *zac, int *kon)
{
    int vsota = 0;
    while (*zac != *kon)
    {
        vsota += *zac;
        zac++;
    }
    return vsota;
}

void indeksInKazalec(int *t, int *indeks, int **kazalec)
{
    if (*indeks == -1)
    {
        *indeks = *kazalec - t;
    }
    else
    {
        *kazalec = t + *indeks;
    }
}

void frekvenceCrk(char *niz, int **frekvence)
{
    char *p = niz;
    int *pogostosti = calloc(26, sizeof(int));
    while (*p != '\0')
    {
        char znak = *p;
        if ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'))
        {
            int indeks = (znak >= 'A') ? znak - 'A' : znak - 'a';
            // pogostosti[indeks]++;
            *(pogostosti + indeks) += 1;
        }
        p++;
    }
    *frekvence = pogostosti;
}

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    // int *t = malloc(10 * sizeof(int));
    // for (int i = 0; i < 10; i++)
    // {
    //     *(t + i) = i + 1;
    // }

    // vsota(t, t + 9);
    return 0;
}
