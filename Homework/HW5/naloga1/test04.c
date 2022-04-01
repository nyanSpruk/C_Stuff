
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int __main__() {
    int tabela[] = {0, 5, 10, 3, 7, 8, 0};
    int n = 0;
    int* pk = NULL;
    int* pz = poisci(tabela + 1, &n, &pk);
    printf("n = %d, *pz = %d, *pk = %d\n", n, *pz, *pk);

    exit(0);
    return 0;
}
