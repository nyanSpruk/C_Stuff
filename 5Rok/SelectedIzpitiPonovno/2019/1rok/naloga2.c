#include <stdio.h>
#include <stdlib.h>

typedef struct vozlisce
{
    int podatek;
    struct vozlisce *naslednje;
} Vozlisce;

Vozlisce *obrni(Vozlisce *zacetek)
{
    Vozlisce *prev = NULL;
    Vozlisce *v = zacetek;
    Vozlisce *next = NULL;
    while (v != NULL)
    {
        next = v->naslednje;
        v->naslednje = prev;
        prev = v;
        v = next;
    }
    return prev;
}

Vozlisce *prepisi(int *t)
{
    Vozlisce *start = malloc(1 * sizeof(Vozlisce *));
    start->podatek = t[0];
    Vozlisce *v = start;
    int counter = 1;
    while (t[counter] != 0)
    {
        Vozlisce *novo = malloc(1 * sizeof(Vozlisce *));
        novo->podatek = t[counter];
        novo->naslednje = NULL;
        v->naslednje = novo;
        counter++;
        v = v->naslednje;
    }
    return start;
}

int main(int argc, char const *argv[])
{
    int t[6] = {5, 2, 5, 6, 4, 0};
    Vozlisce *result = prepisi(t);
    Vozlisce *temp = result;
    while (temp != NULL)
    {
        printf("%d->", temp->podatek);
        temp = temp->naslednje;
    }
    printf("\n");
    Vozlisce *result2 = obrni(result);
    Vozlisce *temp2 = result2;
    while (temp2 != NULL)
    {
        printf("%d->", temp2->podatek);
        temp2 = temp2->naslednje;
    }
    return 0;
}
