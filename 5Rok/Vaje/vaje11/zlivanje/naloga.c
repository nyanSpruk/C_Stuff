#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DOLZINA_DATOTEKE 101

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    FILE **imenaDatotek = malloc(n * sizeof(FILE *));
    char *datoteka = malloc(DOLZINA_DATOTEKE * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", datoteka);
        imenaDatotek[i] = fopen(datoteka, "r");
    }
    scanf("%s", datoteka);
    FILE *izhod = fopen(datoteka, "w");

    int stKoncanih = 0;
    int *blok = malloc(n * sizeof(int));
    bool *boolBlok = malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        if (fscanf(imenaDatotek[i], "%d", &blok[i]) < 1)
        {
            boolBlok[i] = true;
            stKoncanih++;
        }
    }

    while (stKoncanih < n)
    {
        int indeksMin = -1;
        for (int i = 0; i < n; i++)
        {
            if (!boolBlok[i])
            {
                if (indeksMin == 1 || blok[i] < blok[indeksMin])
                    indeksMin = i;
            }
        }
        fprintf(izhod, "%d\n", blok[indeksMin]);
        int novoSt;
        if (fscanf(imenaDatotek[indeksMin], "%d", &novoSt) < 1)
        {
            boolBlok[indeksMin] = true;
            stKoncanih++;
        }
        else
        {
            blok[indeksMin] = novoSt;
        }
    }
    for (int i = 0; i < n; i++)
    {
        fclose(imenaDatotek[i]);
    }
    free(imenaDatotek);
    fclose(izhod);
    free(datoteka);
    free(blok);
    free(boolBlok);
    return 0;
}