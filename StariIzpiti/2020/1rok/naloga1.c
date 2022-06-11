#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void obrni(FILE *vhod, FILE *izhod)
{
    char *vrstica = malloc(1000 * sizeof(char));
    if (fgets(vrstica, 1000, vhod) != NULL)
    {
        obrni(vhod, izhod);
        fprintf(izhod, "%s", vrstica);
    }
    free(vrstica);
    fclose(vhod);
    fclose(izhod);
}

void obrni2(FILE *vhod, FILE *izhod)
{
    char *vrstica = malloc(1000 * sizeof(char));
    char **vrstice = malloc(1000 * sizeof(char *));
    int i = 0;
    while (fgets(vrstica, 1000, vhod) != NULL)
    {
        vrstice[i] = malloc(1000 * sizeof(char));
        strcpy(vrstice[i], vrstica);
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        fprintf(izhod, "%s", vrstice[j]);
        free(vrstice[j]);
    }
    free(vrstica);
    fclose(vhod);
    fclose(izhod);
}

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("vhod.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");
    obrni(vhod, izhod);
    fclose(vhod);
    fclose(izhod);
    return 0;
}
