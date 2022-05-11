
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "naloga.h"

int vsotaI(Vozlisce *zacetek)
{
    Vozlisce *v = zacetek;
    int vsota = 0;
    while (v != NULL)
    {
        vsota += v->podatek;
        v = v->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce *zacetek)
{
    if (zacetek == NULL)
        return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce *vstaviUrejenoI(Vozlisce *zacetek, int element)
{
    Vozlisce *v = zacetek;
    Vozlisce *novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;
    if (v == NULL || element <= v->podatek)
    {
        novo->naslednje = zacetek;
        return novo;
    }

    v = v->naslednje;
    Vozlisce *prev = zacetek;
    while (v != NULL)
    {
        if (element <= v->podatek)
        {
            novo->naslednje = v;
            prev->naslednje = novo;
            return zacetek;
        }
        prev = v;
        v = v->naslednje;
    }

    novo->naslednje = NULL;
    prev->naslednje = novo;

    return zacetek;
}

Vozlisce *vstaviUrejenoR(Vozlisce *zacetek, int element)
{
    if (zacetek == NULL || element <= zacetek->podatek)
    {
        Vozlisce *novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;
}

// char NIZ[1000];

// Vozlisce *zgradi(int *t)
// {
//     Vozlisce *zacetek = NULL;
//     Vozlisce *prejsnje = NULL;
//     int *p = t;

//     while (*p != INT_MAX)
//     {
//         Vozlisce *novo = malloc(sizeof(Vozlisce));
//         novo->podatek = *p;
//         novo->naslednje = NULL;
//         if (p == t)
//         {
//             zacetek = novo;
//         }
//         else
//         {
//             prejsnje->naslednje = novo;
//         }
//         prejsnje = novo;
//         p++;
//     }
//     return zacetek;
// }

// void pocisti(Vozlisce *v)
// {
//     if (v != NULL)
//     {
//         pocisti(v->naslednje);
//         free(v);
//     }
// }

// char *vNiz(Vozlisce *zacetek)
// {
//     char *pNiz = NIZ;
//     *pNiz++ = '[';
//     Vozlisce *v = zacetek;
//     while (v != NULL)
//     {
//         if (v != zacetek)
//         {
//             pNiz += sprintf(pNiz, ", ");
//         }
//         pNiz += sprintf(pNiz, "%d", v->podatek);
//         v = v->naslednje;
//     }
//     sprintf(pNiz, "]");
//     return NIZ;
// }

// void testiraj(Vozlisce *v, int element)
// {
//     printf("%s", vNiz(v));
//     v = vstaviUrejenoI(v, element);
//     printf(" + %d -> %s\n", element, vNiz(v));
//     pocisti(v);
// }

int main()
{
    // testiraj(zgradi((int[]){6, 10, 15, INT_MAX}), 8);
    // testiraj(zgradi((int[]){6, 10, 15, INT_MAX}), 12);

    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 8);
    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 13);
    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 17);
    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 25);
    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 34);
    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 40);
    // testiraj(zgradi((int[]){5, 13, 20, 34, 48, 60, INT_MAX}), 50);

    // testiraj(zgradi((int[]){-30, -20, -10, INT_MAX}), -25);
    // testiraj(zgradi((int[]){-30, -20, -10, INT_MAX}), -15);
    // testiraj(zgradi((int[]){-30, -20, -10, INT_MAX}), -10);

    // testiraj(zgradi((int[]){-10, 10, INT_MAX}), 0);

    // exit(0);
    return 0;
}
