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

Vozlisce *kreiraj(int val)
{
    Vozlisce *v = malloc(sizeof(Vozlisce));
    v->next = NULL;
    v->value = val;
    return v;
}

Vozlisce *odstrani(Vozlisce *osnova, Vozlisce *indeksi)
{
    Vozlisce *rezultatStart = NULL;
    Vozlisce *v = rezultatStart;
    int indexOsnove = 0;
    while (osnova != NULL)
    {
        if (indeksi != NULL && indexOsnove != indeksi->value)
        {
            if (rezultatStart == NULL)
            {
                Vozlisce *temp = malloc(sizeof(Vozlisce));
                rezultatStart = temp;
                rezultatStart->value = osnova->value;
                rezultatStart->next = NULL;
                v = rezultatStart;
            }
            else
            {
                v->next = kreiraj(osnova->value);
                v = v->next;
            }
        }
        else if (indeksi == NULL)
        {
            v->next = kreiraj(osnova->value);
            v = v->next;
        }
        else
        {
            indeksi = indeksi->next;
        }
        osnova = osnova->next;
        indexOsnove++;
    }
    return rezultatStart;
}

int main(int argc, char const *argv[])
{
    int t[7] = {70, 30, 60, 40, 50, 69, 0};
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