#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("datoteka.bin", "rb");
    FILE *izhod = fopen("izhod.txt", "w");
    int n = 7;
    int counterR = 0;
    int counterG = 0;
    int counterB = 0;

    unsigned char *barve = malloc(3 * sizeof(unsigned char));
    for (int i = 0; i < n; i++)
    {
        fread(barve, 3, sizeof(unsigned char), vhod);
        if (barve[0] > 0 && barve[1] == 0 && barve[2] == 0)
            counterR++;
        if (barve[0] == 0 && barve[1] > 0 && barve[2] == 0)
            counterG++;
        if (barve[0] == 0 && barve[1] == 0 && barve[2] > 0)
            counterB++;
    }

    fprintf(izhod, "%d\n%d\n%d\n", counterR, counterG, counterB);
    fclose(vhod);
    fclose(izhod);
    free(barve);
    return 0;
}
