
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long x, long a, long b)
{
    while (a <= b)
    {
        long mid = (a + b) / 2;
        long st = f(mid);
        if (st == x)
        {
            return mid;
        }
        if (st < x)
        {
            a = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }

    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
