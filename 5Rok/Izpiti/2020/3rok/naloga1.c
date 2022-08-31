#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void razlike(FILE *prva, FILE *druga, FILE *izhod)
{
    char *vrstica1 = malloc(1000 * sizeof(char));
    char *vrstica2 = malloc(1000 * sizeof(char));
    int counter = 1;
    while ((fgets(vrstica1, 1000, prva)) != NULL)
    {
        fgets(vrstica2, 1000, druga);
        if (strcmp(vrstica1, vrstica2) != 0)
            fprintf(izhod, "%d\n", counter);

        counter++;
    }
    free(vrstica1);
    free(vrstica2);
}

int main(int argc, char const *argv[])
{
    FILE *vhod1 = fopen("vhod1.txt", "r");
    FILE *vhod2 = fopen("vhod2.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");

    razlike(vhod1, vhod2, izhod);

    fclose(vhod1);
    fclose(vhod2);
    fclose(izhod);
    return 0;
}
