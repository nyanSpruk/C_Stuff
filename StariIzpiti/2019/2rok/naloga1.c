#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *vhodIme = malloc(sizeof(char) * 21);
    int n;
    char *izhodIme = malloc(sizeof(char) * 21);
    scanf("%s %d %s", vhodIme, &n, izhodIme);
    FILE *vhod = fopen(vhodIme, "rb");
    FILE *izhod = fopen(izhodIme, "w");
    int counterR, counterG, counterB;
    counterR = counterG = counterB = 0;
    unsigned char *pike = malloc(3 * sizeof(unsigned char));
    for (int i = 0; i < n; i++)
    {
        fread(pike, sizeof(unsigned char), 3, vhod);
        if (pike[0] > 0 && pike[1] == 0 && pike[2] == 0)
            counterR++;
        else if (pike[0] == 0 && pike[1] > 0 && pike[2] == 0)
            counterG++;
        else if (pike[0] == 0 && pike[1] == 0 && pike[2] > 0)
            counterB++;
    }
    fprintf(izhod, "%d\n", counterR);
    fprintf(izhod, "%d\n", counterG);
    fprintf(izhod, "%d\n", counterB);

    fclose(vhod);
    fclose(izhod);
    free(vhodIme);
    free(izhodIme);
    free(pike);
    return 0;
}
