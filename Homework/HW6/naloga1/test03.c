
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

char* NIZI[] = {"", "123", "4567", "8901", "2", "34", "", "567890", NULL};

int __main__() {
    char* niz = zdruzi(NIZI, " | ");
    printf("<%s>\n", niz);

    exit(0);
    return 0;
}
