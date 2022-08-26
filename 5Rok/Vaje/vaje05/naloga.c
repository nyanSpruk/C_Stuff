#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int *zac, int *kon)
{
    int counter = 0;
    while (zac != kon)
    {
        counter += *zac;
        zac++;
    }
    return counter;
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

    int *frekvencaCrke = calloc(26, sizeof(int));
    while (*p != '\0')
    {
        char c = *p;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            int indeks = (c <= 'Z') ? c - 'A' : c - 'a';
            frekvencaCrke[indeks]++;
        }
        p++;
    }
    *frekvence = frekvencaCrke;
}

int main()
{

    int *frekvence;
    frekvenceCrk("baNanA", &frekvence);
    for (int c = 'A'; c <= 'Z'; c++)
    {
        if (frekvence[c - 'A'] > 0)
        {
            printf("%c -> %d\n", c, frekvence[c - 'A']);
        }
    }

    free(frekvence);

    exit(0);
    return 0;
}