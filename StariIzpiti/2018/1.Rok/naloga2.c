#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

unsigned char *preberi(char *imeDat, int *sirina, int *visina, int *stBajtov)
{
    FILE *datoteka = fopen(imeDat, "rb");

    char *temp = malloc(sizeof(char) * 10);
    fgets(temp, 10, datoteka);

    fscanf(datoteka, "%d %d", sirina, visina);
    fgetc(datoteka);

    fscanf(datoteka, "%d", stBajtov);
    fgetc(datoteka);

    unsigned char *podatki = malloc(3 * (*sirina) * (*visina) * sizeof(unsigned char));
    fread(podatki, sizeof(unsigned char), 3 * (*sirina) * (*visina), datoteka);
    fclose(datoteka);
    free(temp);
    return podatki;
}

int sivina(unsigned char *pike, int sirina, int visina, int vrstica, int stolpec)
{
    int indeks = 3 * (vrstica * sirina + stolpec);
    int sivaVred = floor((pike[indeks] + pike[indeks + 1] + pike[indeks + 2]) / 3);
    return sivaVred;
}

int main(int argc, char const *argv[])
{
    int *sirina = malloc(sizeof(int));
    int *visina = malloc(sizeof(int));
    int *stBajtov = malloc(sizeof(int));

    unsigned char *pika = preberi("slika01.ppm", sirina, visina, stBajtov);

    // izluscimo barvne komponente pike na podanih koordinatah
    int indByta = (1 * (*sirina) + 0) * 3;
    printf("%d %d %d\n", pika[indByta], pika[indByta + 1], pika[indByta + 2]);

    int sivaV = sivina(pika, *sirina, *visina, 1, 0);
    printf("%d\n", sivaV);

    return 0;
}
