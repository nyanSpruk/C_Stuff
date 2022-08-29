#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *vhod = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    char *rand = malloc(10 * sizeof(char));

    fgets(rand, 10, vhod);

    int sirina, visina;
    fscanf(vhod, "%d %d", &sirina, &visina);
    fgetc(vhod);

    fgets(rand, 10, vhod);

    free(rand);

    unsigned char *barve = malloc(sirina * visina * 3 * sizeof(unsigned char));
    fread(barve, sizeof(unsigned char), 3 * sirina * visina, vhod);
    int index = (sirina * vrstica + stolpec) * 3;
    printf("%d %d %d\n", barve[index], barve[index + 1], barve[index + 2]);

    free(barve);
    fclose(vhod);

    return 0;
}