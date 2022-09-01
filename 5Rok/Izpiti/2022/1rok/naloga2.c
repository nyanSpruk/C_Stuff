#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Vozlisce
{
    int *vTabelo;                // kazalec na nek element tabele t
    struct _Vozlisce *naslednje; // kazalec na naslednje vozlišče seznama
} Vozlisce;

Vozlisce **tabelaSeznamov(int *t, int d, int n)
{
    Vozlisce **result = (Vozlisce **)malloc(n * sizeof(Vozlisce *));
    for (int i = 0; i < n; i++)
    {
        int stVozlisc = d / pow(2, i);
        Vozlisce *inner = (Vozlisce *)malloc(stVozlisc * sizeof(Vozlisce));
        Vozlisce *temp = inner;
        for (int j = 0; j < d; j++)
        {
            if ((j + 1) % (int)pow(2, i) == 0)
            {
                temp->naslednje = malloc(sizeof(Vozlisce));
                temp->vTabelo = &(t[j]);
                temp = temp->naslednje;
                printf("%d ", j);
            }
        }
        result[i] = inner;
        printf("\n");
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int d = 10;
    int n = 4;
    int *t;
    t = malloc(d * sizeof(int));
    for (int i = 0; i < d; i++)
    {
        t[i] = i;
    }

    Vozlisce **result = tabelaSeznamov(t, d, n);
    for (int i = 0; i < n; i++)
    {
        Vozlisce *v = result[i];
        while (v->naslednje != NULL)
        {
            int val = *(v->vTabelo);
            if (v->naslednje->naslednje == NULL)
                printf("%d", val);
            else
                printf("%d->", val);
            v = v->naslednje;
        }
        printf("\n");
    }

    return 0;
}
