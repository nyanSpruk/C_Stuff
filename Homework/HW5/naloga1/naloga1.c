
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga1.c
./test01

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int *poisci(int *t, int *dolzina, int **konec)
{
    int *prvi = t;
    int *zadnji = t;
    int counter = 0;
    while (*zadnji != 0)
    {
        counter++;
        zadnji++;
    }
    while (*prvi != 0)
    {
        counter++;
        prvi--;
    }
    *dolzina = counter - 1;
    *konec = zadnji - 1;
    prvi = prvi + 1;
    return prvi;
}

int main()
{
    // int tabela[] = {0, 3, 5, 2, 7, 1, -6, -4, 7, 2, -6, 9, -9, 0};
    // int n = 0;
    // int *pk = NULL;
    // int *pz = poisci(tabela + 12, &n, &pk);
    // printf("n = %d, *pz = %d, *pk = %d\n", n, *pz, *pk);

    // koda za ro"cno testiranje (po "zelji)
    return 0;
}
