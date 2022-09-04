#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void razlike(FILE *prva, FILE *druga, FILE *izhod)
{
    char *vrstica1 = malloc(1000 * sizeof(char));
    char *vrstica2 = malloc(1000 * sizeof(char));
    int index = 1;
    while ((fgets(vrstica1, 1000, prva)) != NULL)
    {
        fgets(vrstica2, 1000, druga);
        if (strcmp(vrstica1, vrstica2) != 0)
            fprintf(izhod, "%d\n", index);
        index++;
    }
}

int main(int argc, char const *argv[])
{
    FILE *prva = fopen("prva.txt", "r");
    FILE *druga = fopen("druga.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");
    razlike(prva, druga, izhod);
    return 0;
}
