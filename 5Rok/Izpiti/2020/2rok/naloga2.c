#include <stdlib.h>
#include <stdio.h>

typedef struct _vozlisce
{
    struct _vozlisce *next;
    int value;
} Vozlisce;

Vozlisce *izloci(Vozlisce *zac, Vozlisce *v)
{
    if (zac == v)
    {
        return zac->next;
    }
    Vozlisce *prev = zac;
    Vozlisce *curr = zac->next;
    while (curr != v)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    return zac;
}

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

int main(int argc, char const *argv[])
{
    int t[3] = {5, 4, 0};
    Vozlisce *start = prepisi(t);
    Vozlisce *v = start;
    while (v != NULL)
    {
        printf("%d->", v->value);
        v = v->next;
    }
    printf("\n");
    Vozlisce *izlociNode = start->next;
    Vozlisce *start2 = izloci(start, izlociNode);
    Vozlisce *u = start2;
    while (u != NULL)
    {
        printf("%d->", u->value);
        u = u->next;
    }
    printf("\n");
    return 0;
}
