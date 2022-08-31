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

int main(int argc, char const *argv[])
{
    int t[6] = {5, 2, 5, 6, 4, 0};
    Vozlisce *result = prepisi(t);
    while (result != NULL)
    {
        printf("%d->", result->value);
        result = result->next;
    }
    return 0;
}
