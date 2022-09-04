#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("datoteka.bin", "rb");
    FILE *izhod = fopen("izhod.txt", "w");
    int n = 7;

    int R = 0, G = 0, B = 0;
    unsigned char *barve = malloc(3 * sizeof(unsigned char));
    for (int i = 0; i < n; i++)
    {
        fread(barve, sizeof(unsigned char), 3, vhod);
        if (barve[0] > 0 && barve[1] == 0 && barve[2] == 0)
            R++;
        if (barve[0] == 0 && barve[1] > 0 && barve[2] == 0)
            G++;
        if (barve[0] == 0 && barve[1] == 0 && barve[2] > 0)
            B++;
    }
    fprintf(izhod, "%d\n%d\n%d\n", R, G, B);
    return 0;
}
