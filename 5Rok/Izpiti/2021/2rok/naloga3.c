#include <stdio.h>
#include <stdlib.h>

typedef struct _Vozlisce
{
    struct _Vozlisce *n; // kazalec na naslednje vozlišče v verigi oz. NULL, če ga ni
    struct _Vozlisce *r; // kazalec na poljubno vozlišče v verigi ali NULL
} Vozlisce;

int najkrajsaPot(Vozlisce *izvor, Vozlisce *cilj)
{
    if (izvor == cilj)
        return 0;
    int najKrajsaPotN = najkrajsaPot(izvor->n, cilj);
    int najKrajsaPotR;
    if (izvor->r != NULL || izvor->r != izvor)
        najKrajsaPotR = najkrajsaPot(izvor->r, cilj);
    return najKrajsaPotN < najKrajsaPotR ? 1 + najKrajsaPotN : 1 + najKrajsaPotR;
}