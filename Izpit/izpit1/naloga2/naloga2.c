
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test10: samodejno izdelani, zadnji element prvega seznama < prvi element drugega seznama
test11..test16: samodejno izdelani, splo"sni

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

Vozlisce *zlij(Vozlisce *a, Vozlisce *b)
{
    Vozlisce *zacetek;
    Vozlisce *v;
    if (a->podatek <= b->podatek)
    {
        zacetek = a;
        a = a->naslednje;
    }
    else
    {
        zacetek = b;
        b = b->naslednje;
    }
    v = zacetek;
    while (1)
    {
        if (a == NULL)
        {
            v->naslednje = b;
            break;
        }
        if (b == NULL)
        {
            v->naslednje = a;
            break;
        }

        if (a->podatek <= b->podatek)
        {
            v->naslednje = a;
            a = a->naslednje;
        }
        else
        {
            v->naslednje = b;
            b = b->naslednje;
        }
        v = v->naslednje;
    }

    return zacetek; // popravite
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main()
{
    return 0;
}

#endif
