#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *vhod = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    char *temp = malloc(sizeof(char) * 10);
    fgets(temp, 10, vhod);

    int visina, sirina;
    fscanf(vhod, "%d %d", &sirina, &visina);
    fgetc(vhod);

    fgets(temp, 10, vhod);
    free(temp);

    unsigned char *pike = malloc(3 * sirina * visina * sizeof(unsigned char));
    fread(pike, sizeof(unsigned char), 3 * visina * sirina, vhod);
    fclose(vhod);

    // izluscimo barvne komponente pike na podanih koordinatah
    int indByta = (vrstica * sirina + stolpec) * 3;
    printf("%d %d %d\n", pike[indByta], pike[indByta + 1], pike[indByta + 2]);

    fclose(vhod);
    return 0;
}