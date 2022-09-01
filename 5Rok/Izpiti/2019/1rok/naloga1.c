#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // FILE *testVhod = fopen("test.in", "r");
    // char *vhodString = malloc(21 * sizeof(char));
    // char *izhodString = malloc(21 * sizeof(char));
    // char znak;
    // fgets(vhodString, 1000, testVhod);
    // fgets(izhodString, 1000, testVhod);
    // printf("%s", vhodString);
    // printf("%s", izhodString);
    // znak = fgetc(testVhod);
    // printf("%c\n", znak);
    char znak = 'C';

    // FILE *vhod = fopen(vhodString, "r");
    // FILE *izhod = fopen(izhodString, "w");
    FILE *vhod = fopen("vhod.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");

    char *vrstica = malloc(1000 * sizeof(char));
    char *winVrstica = malloc(1000 * sizeof(char));
    while ((fgets(vrstica, 1000, vhod)) != NULL)
    {
        if (strchr(vrstica, znak))
            strcpy(winVrstica, vrstica);
    }
    fprintf(izhod, "%s", winVrstica);
    // printf("%s", winVrstica);
    // printf("\n");
    return 0;
}
