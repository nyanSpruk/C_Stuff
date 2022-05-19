
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga2.h"

int __main__() {
    A* a1 = malloc(sizeof(A));
    a1->p = 4;
    a1->b = NULL;

    char* cilj = malloc(10010 * sizeof(char));
    int stZnakov = izpisiA(a1, cilj);
    printf("%s\n", cilj);
    printf("%d\n", stZnakov);
    free(cilj);

    free(a1);

    exit(0);
    return 0;
}
