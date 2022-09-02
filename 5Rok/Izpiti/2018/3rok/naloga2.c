#include <stdio.h>
#include <stdlib.h>

typedef struct _vozlisce
{
    struct _vozlisce *next;
    int value;
} Vozlisce;

Vozlisce *prepisi(int *t)
{
    Vozlisce *start = malloc(1 * sizeof(Vozlisce *));
    start->value = t[0];
    Vozlisce *v = start;
    int counter = 1;
    while (t[counter] != 0)
    {
        Vozlisce *novo = malloc(1 * sizeof(Vozlisce *));
        novo->value = t[counter];
        novo->next = NULL;
        v->next = novo;
        counter++;
        v = v->next;
    }
    return start;
}

Vozlisce *odstrani(Vozlisce *osnova, Vozlisce *indeksi)
{
    Vozlisce *rezultati = malloc(sizeof(Vozlisce));
    Vozlisce *v = rezultati;

    int ix = 0;
    while (indeksi != NULL)
    {
        if (indeksi->value != ix)
        {
            v->value = osnova->value;
            v->next = malloc(sizeof(Vozlisce));
            v = v->next;
        }
        else
        {
            indeksi = indeksi->next;
        }
        ix++;
        osnova = osnova->next;
    }
    return rezultati;
}

int main(int argc, char const *argv[])
{
    int t[6] = {70, 30, 60, 40, 50, 0};
    int indeksiT[4] = {1, 2, 4, 0};

    Vozlisce *osnova = prepisi(t);
    Vozlisce *indeksi = prepisi(indeksiT);
    printf("Osnova: ");
    Vozlisce *osnovaTemp = osnova;
    while (osnovaTemp != NULL)
    {
        printf("%d->", osnovaTemp->value);
        osnovaTemp = osnovaTemp->next;
    }
    printf("\n");

    printf("Indeksi: ");
    Vozlisce *indeskTemp = indeksi;
    while (indeskTemp != NULL)
    {
        printf("%d->", indeskTemp->value);
        indeskTemp = indeskTemp->next;
    }
    printf("\n");
    Vozlisce *rezultat = odstrani(osnova, indeksi);

    printf("Rezultat: ");
    while (rezultat != NULL)
    {
        printf("%d->", rezultat->value);
        rezultat = rezultat->next;
    }
    printf("\n");
    return 0;
}
