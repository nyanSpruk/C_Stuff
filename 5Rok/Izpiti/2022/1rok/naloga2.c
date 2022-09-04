#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// typedef struct _Vozlisce
// {
//     int *vTabelo;                // kazalec na nek element tabele t
//     struct _Vozlisce *naslednje; // kazalec na naslednje vozlišče seznama
// } Vozlisce;

#include "naloga2.h"

Vozlisce **tabelaSeznamov(int *t, int d, int n)
{
    Vozlisce **result = (Vozlisce **)malloc(n * sizeof(Vozlisce *));
    for (int i = 0; i < n; i++)
    {
        int stVozlisc = d / pow(2, i);
        Vozlisce *inner = (Vozlisce *)malloc(stVozlisc * sizeof(Vozlisce));

        Vozlisce *new = malloc(sizeof(Vozlisce));
        new->vTabelo = &(t[(int)pow(2, i) - 1]);
        new->naslednje = NULL;
        inner = new;
        Vozlisce *temp = inner;

        for (int j = pow(2, i); j < d; j++)
        {
            if ((j + 1) % (int)pow(2, i) == 0)
            {
                Vozlisce *new = malloc(sizeof(Vozlisce));
                new->vTabelo = &(t[j]);
                new->naslednje = NULL;
                temp->naslednje = new;
                temp = temp->naslednje;
                // printf("%d ", j);
            }
        }
        result[i] = inner;
        // printf("\n");
    }

    return result;
}

// void izpisi(Vozlisce *p)
// {
//     printf("[");
//     bool prvic = true;
//     while (p != NULL)
//     {
//         if (!prvic)
//         {
//             printf(", ");
//         }
//         prvic = false;
//         printf("%d", *(p->vTabelo));
//         p = p->naslednje;
//     }
//     printf("]\n");
// }

// void pocisti(Vozlisce *p)
// {
//     while (p != NULL)
//     {
//         Vozlisce *q = p->naslednje;
//         free(p);
//         p = q;
//     }
// }

int main()
{
    // FILE *f = fopen("test24.dat", "r");

    // int d = 0;
    // fscanf(f, "%d", &d);

    // int *t = malloc(d * sizeof(int));
    // for (int i = 0; i < d; i++)
    // {
    //     fscanf(f, "%d", &t[i]);
    // }

    // int n = 0;
    // fscanf(f, "%d", &n);

    // fclose(f);

    // Vozlisce **tabSez = tabelaSeznamov(t, d, n);

    // for (int i = 0; i < n; i++)
    // {
    //     izpisi(tabSez[i]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     pocisti(tabSez[i]);
    // }

    // free(tabSez);
    // free(t);

    return 0;
}