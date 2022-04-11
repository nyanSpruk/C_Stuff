
#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

int* TABELA[] = {
    (int[]) {10, 15, 8, 5, 17, 6, 13, 14, 9, 2, 11, 1, 7, 12, 3, 0},
};

int __main__() {
    int izvornoStVrstic = sizeof(TABELA) / sizeof(TABELA[0]);
    int ciljnoStVrstic = 0;
    int(*rezultat)[N] = pp2ap(TABELA, izvornoStVrstic, &ciljnoStVrstic);

    for (int i = 0;  i < ciljnoStVrstic;  i++) {
        for (int j = 0;  j < N;  j++) {
            printf("%3d", rezultat[i][j]);
        }
        printf("\n");
    }
    free(rezultat);

    exit(0);
    return 0;
}
