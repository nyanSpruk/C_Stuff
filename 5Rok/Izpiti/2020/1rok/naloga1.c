#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void obrni(FILE *vhod, FILE *izhod)
{
    char **vrstice = malloc(1000 * sizeof(char *));
    char *vrstica = malloc(1000 * sizeof(char));
    int counter = 0;
    while ((fgets(vrstica, 1000, vhod)) != NULL)
    {
        // vrstice[counter] = vrstica;
        vrstice[counter] = malloc(1000 * sizeof(char));
        strcpy(vrstice[counter], vrstica);
        counter++;
    }

    for (int i = counter - 1; i >= 0; i--)
    {
        fprintf(izhod, "%s", vrstice[i]);
        free(vrstice[i]);
    }
    free(vrstica);
    free(vrstice);
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
