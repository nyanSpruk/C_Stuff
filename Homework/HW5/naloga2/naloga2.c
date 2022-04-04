
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga2.c
./test01

*/

#include <stdio.h>
#include "naloga2.h"

void zamenjaj(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void uredi(int **a, int **b, int **c)
{
    if (*(*a) > *(*c))
        zamenjaj(a, c);
    if (*(*a) > *(*b))
        zamenjaj(a, b);
    if (*(*b) > *(*c))
        zamenjaj(b, c);
}

int main()
{
    // int a = 5;
    // int b = 3;
    // int c = 2;

    // int *pa = &a;
    // int *pb = &b;
    // int *pc = &c;

    // uredi(&pa, &pb, &pc);

    // printf("*pa = %d, *pb = %d, *pc = %d\n", *pa, *pb, *pc);
    // printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}
