
#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

int __main__() {
    int a = -6;
    int b = -4;
    int c = -4;

    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    uredi(&pa, &pb, &pc);

    printf("*pa = %d, *pb = %d, *pc = %d\n", *pa, *pb, *pc);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    exit(0);
    return 0;
}
