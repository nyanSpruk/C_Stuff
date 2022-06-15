#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void razlike(FILE *prva, FILE *druga, FILE *izhod)
{
    char *vrsticaEna = malloc(1001 * sizeof(char));
    char *vrsticaDva = malloc(1001 * sizeof(char));
    int counter = 1;
    while ((fgets(vrsticaEna, 1001, prva)) != NULL)
    {
        fgets(vrsticaDva, 1001, druga);
        if (strcmp(vrsticaEna, vrsticaDva) != 0)
        {
            fprintf(izhod, "%d\n", counter);
        }
        counter++;
    }
    free(vrsticaEna);
    free(vrsticaDva);
    return;
}

int main(int argc, char const *argv[])
{
    FILE *prva = fopen("prva.txt", "r");
    FILE *druga = fopen("druga.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");

    razlike(prva, druga, izhod);
    fclose(prva);
    fclose(druga);
    fclose(izhod);
    return 0;
}
