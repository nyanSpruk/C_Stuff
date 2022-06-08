#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOLZINA_VRSTICE 1000

int main(int argc, char const *argv[])
{
    char *imeInputDatoteke = malloc(sizeof(char) * MAX_DOLZINA_VRSTICE);
    char *imeOutputDatoteke = malloc(sizeof(char) * MAX_DOLZINA_VRSTICE);
    char znak;
    scanf("%s", imeInputDatoteke);
    scanf("%s", imeOutputDatoteke);
    getchar();
    scanf("%c", &znak);
    FILE *input = fopen(imeInputDatoteke, "r");
    FILE *output = fopen(imeOutputDatoteke, "w");
    char *vrstica = malloc(sizeof(char) * MAX_DOLZINA_VRSTICE);
    char *winVrstica = malloc(sizeof(char) * MAX_DOLZINA_VRSTICE);
    while (fgets(vrstica, MAX_DOLZINA_VRSTICE, input) != NULL)
    {
        if (strchr(vrstica, znak) != NULL)
        {
            strcpy(winVrstica, vrstica);
        }
    }
    fprintf(output, "%s", winVrstica);

    fclose(input);
    fclose(output);
    free(imeInputDatoteke);
    free(imeOutputDatoteke);
    free(vrstica);
    free(winVrstica);
    return 0;
}
