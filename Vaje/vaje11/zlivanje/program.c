#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DOLZINA_IMENA 100

int main()
{
    int stDatotek;
    scanf("%d", &stDatotek);
    FILE **datoteke = malloc(sizeof(FILE *) * stDatotek);
    // preberemno vse vhodne datoteke
    char *imeDatoteke = malloc(sizeof(char) * (MAX_DOLZINA_IMENA + 1));
    for (int i = 0; i < stDatotek; i++)
    {
        scanf("%s", imeDatoteke);
        datoteke[i] = fopen(imeDatoteke, "r");
    }
    scanf("%s", imeDatoteke);
    FILE *izhod = fopen(imeDatoteke, "w");

    int stKoncanih = 0;
    int *blok = malloc(sizeof(int) * stDatotek);
    bool *bool_blok = malloc(sizeof(bool) * stDatotek);
    for (int i = 0; i < stDatotek; i++)
    {
        if (fscanf(datoteke[i], "%d", &blok[i]) < 1)
        {
            bool_blok[i] = true;
            stKoncanih++;
        }
    }

    while (stKoncanih < stDatotek)
    {
        int indeksMin = -1;
        for (int i = 0; i < stDatotek; i++)
        {
            if (!bool_blok[i])
            {
                if (indeksMin == -1 || blok[i] < blok[indeksMin])
                {
                    indeksMin = i;
                }
            }
        }
        fprintf(izhod, "%d\n", blok[indeksMin]);
        int novo;
        if (fscanf(datoteke[indeksMin], "%d", &novo) < 1)
        {
            bool_blok[indeksMin] = true;
            stKoncanih++;
        }
        else
            blok[indeksMin] = novo;
    }
    for (int i = 0; i < stDatotek; i++)
    {
        fclose(datoteke[i]);
    }
    free(imeDatoteke);
    free(datoteke);
    fclose(izhod);
    free(blok);
    free(bool_blok);
}