#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZGORNJA_MEJA_DOLZINE 1000001

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");

    char *vrstica = malloc(ZGORNJA_MEJA_DOLZINE * sizeof(char));
    char *winningLine = malloc(ZGORNJA_MEJA_DOLZINE * sizeof(char));
    int maxLength = 0;
    while ((fgets(vrstica, ZGORNJA_MEJA_DOLZINE, vhod)) != NULL)
    {
        int dolzina = strlen(vrstica);
        if (dolzina > maxLength)
        {
            maxLength = dolzina;
            strcpy(winningLine, vrstica);
        }
    }
    fprintf(izhod, "%s", winningLine);
    free(vrstica);
    free(winningLine);
    fclose(vhod);
    fclose(izhod);
    return 0;
}
