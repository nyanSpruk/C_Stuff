
#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

int __main__() {
    int a = 10;
    int b = -10;
    int c = 20;

    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    uredi(&pa, &pb, &pc);

    printf("*pa = %d, *pb = %d, *pc = %d\n", *pa, *pb, *pc);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    exit(0);
    return 0;
}
