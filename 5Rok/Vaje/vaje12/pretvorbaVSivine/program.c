#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *vhod = fopen(argv[1], "rb");

    char *rand = malloc(10 * sizeof(char));

    fgets(rand, 10, vhod);

    int sirina, visina;
    fscanf(vhod, "%d %d", &sirina, &visina);
    fgetc(vhod);

    fgets(rand, 10, vhod);

    free(rand);

    // Setupt datoteke
    FILE *izhod = fopen(argv[2], "wb");
    fprintf(izhod, "P5\n");
    fprintf(izhod, "%d %d\n", sirina, visina);
    fprintf(izhod, "255\n");

    unsigned char *barve = malloc(sirina * visina * 3 * sizeof(unsigned char));
    fread(barve, sizeof(unsigned char), 3 * sirina * visina, vhod);
    unsigned char *sivine = malloc(sirina * visina * sizeof(unsigned char));
    int b = 0;
    int s = 0;
    for (int i = 0; i < visina; i++)
    {
        for (int j = 0; j < sirina; j++)
        {
            sivine[s] = (30 * barve[b] + 59 * barve[b + 1] + 11 * barve[b + 2]) / 100;
            b += 3;
            s++;
        }
    }
    fwrite(sivine, sizeof(unsigned char), sirina * visina, izhod);
    free(barve);
    fclose(vhod);

    return 0;
}