
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int __main__()
{
    int *t = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        *(t + i) = i + 1;
    }
    int result = vsota(t, t + 10);
    printf("%d\n", result);

    free(t);

    exit(0);
    return 0;
}
