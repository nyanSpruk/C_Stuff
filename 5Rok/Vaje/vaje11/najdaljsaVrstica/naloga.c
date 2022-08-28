#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZGORNJA_MEJA_DOLZINE 1000001

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");

    int maxLen = 0;
    char *najdaljsa = malloc(ZGORNJA_MEJA_DOLZINE);
    char *input = malloc(ZGORNJA_MEJA_DOLZINE);

    while ((fgets(input, ZGORNJA_MEJA_DOLZINE, vhod)) != NULL)
    {
        int len = strlen(input);
        if (len > maxLen)
        {
            maxLen = len;
            strcpy(najdaljsa, input);
        }
    }

    fprintf(izhod, "%s", najdaljsa);
    fclose(vhod);
    fclose(izhod);
    free(najdaljsa);
    free(input);
    return 0;
}
