
#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

int __main__() {
    int a = 10;
    int b = 20;
    int* pa = &a;
    int* pb = &b;

    zamenjaj(&pa, &pb);

    printf("*pa = %d, *pb = %d\n", *pa, *pb);
    printf("a = %d, b = %d\n", a, b);

    exit(0);
    return 0;
}
