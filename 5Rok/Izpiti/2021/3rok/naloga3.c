#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Oseba
{
    int indeks;               // indeks osebe
    struct _Oseba *prviOtrok; // kazalec na otroka z manjšim indeksom oz. NULL,
    // če oseba nima otrok
    struct _Oseba *drugiOtrok; // kazalec na otroka z večjim indeksom oz. NULL,
} Oseba;

int pozicijaIndeksa(int iskanoSt, bool prvi, int *st, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!prvi && iskanoSt == st[i])
        {
            prvi = true;
            continue;
        }
        if (prvi && iskanoSt == st[i])
            return i;
    }

    return -2;
}

Oseba *zgradiIndex(int n, int *starsi, int index)
{
    Oseba *parent = malloc(sizeof(Oseba));
    parent->indeks = index;
    int pozicija = pozicijaIndeksa(index, true, starsi, n);
    if (pozicija != -2)
        parent->prviOtrok = zgradiIndex(n, starsi, pozicija);
    pozicija = pozicijaIndeksa(index, false, starsi, n);
    if (pozicija != -2)
        parent->drugiOtrok = zgradiIndex(n, starsi, pozicija);
    return parent;
}

Oseba *zgradi(int n, int *starsi)
{
    int pozicjaStarsa = pozicijaIndeksa(-1, true, starsi, n);
    Oseba *parent = zgradiIndex(n, starsi, pozicjaStarsa);
    return parent;
}

int main(int argc, char const *argv[])
{
    int n = 9;
    int t[9] = {4, 5, 8, 1, 1, -1, 4, 8, 5};
    int indexStara = pozicijaIndeksa(-1, true, t, n);
    printf("%d\n", indexStara);
    Oseba *parent = zgradi(n, t);
    return 0;
}