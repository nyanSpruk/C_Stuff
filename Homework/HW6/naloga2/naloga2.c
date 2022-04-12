
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int **ap2pp(int (*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic)
{
    int stElVVrstici = sizeof(*kazalec) / sizeof(int);
    int stElementov = stElVVrstici * izvornoStVrstic;
    int stElPerVrstica = stElementov / ciljnoStVrstic;
    int **table = calloc(ciljnoStVrstic, sizeof(int *));

    for (int i = 0; i < ciljnoStVrstic; i++)
    {
        *(table + i) = calloc(stElPerVrstica + 1, sizeof(int));
        for (int j = 0; j < stElPerVrstica; j++)
        {
            int temp = *(*(kazalec) + j + stElPerVrstica * i);
            *(*(table + i) + j) = temp;
        }
    }
    return table;
}

int (*pp2ap(int **kazalec, int izvornoStVrstic, int *ciljnoStVrstic))[N]
{
    int stEl = 0;
    for (int i = 0; i < izvornoStVrstic; i++)
    {
        int *vrstica = *(kazalec + i);
        for (int j = 0; *(vrstica + j) != 0; j++)
            stEl++;
    }
    *(ciljnoStVrstic) = stEl / N + (stEl % N > 0 ? 1 : 0);
    int(*rez)[N] = calloc((N) * (*ciljnoStVrstic), sizeof(int));
    int indexI = 0;
    int indexJ = 0;
    for (int i = 0; i < (*ciljnoStVrstic); i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (indexI == izvornoStVrstic)
                return rez;

            if (kazalec[indexI][indexJ] == 0)
            {
                if (indexI == izvornoStVrstic - 1)
                    return rez;
                else
                {
                    indexI++;
                    indexJ = 0;
                }
            }
            if (kazalec[indexI][indexJ] != 0)
            {
                rez[i][j] = kazalec[indexI][indexJ];
                indexJ++;
            }
            else
            {
                indexI++;
                indexJ = 0;
                j--;
            }
        }
    }

    return rez;
}

int main()
{
    return 0;
}
