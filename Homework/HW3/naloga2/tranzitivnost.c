
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b)
{
    bool tranz = true;
    bool antiTranz = true;
    bool neTranz = false;

    for (int x = a; x <= b; x++)
    {
        for (int y = a; y <= b; y++)
        {
            for (int z = a; z <= b; z++)
            {
                if (tranz && f(x, y) == 1 && f(y, z) == 1 && f(x, z) != 1)
                    tranz = false;

                if (antiTranz && f(x, y) == 1 && f(y, z) == 1 && f(x, z) != 0)
                    antiTranz = false;

                if (!neTranz && f(x, y) == 1 && f(y, z) == 1 && f(x, z) == 0)
                    neTranz = true;
            }
        }
    }
    if (tranz && antiTranz)
        return 1;
    else if (tranz)
        return 2;
    else if (antiTranz)
        return 3;
    else if (neTranz)
        return 4;

    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
