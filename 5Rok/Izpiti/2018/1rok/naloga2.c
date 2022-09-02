#include <stdio.h>
#include <stdlib.h>

unsigned char *preberi(char *imeDat, int *sirina, int *visina, int *stBajtov)
{
    FILE *vhod = fopen(imeDat, "rb");
    char *temp = malloc(10 * sizeof(char));
    fgets(temp, sizeof(char) * 10, vhod);
    fscanf(vhod, "%d %d ", sirina, visina);
    fgets(temp, sizeof(char) * 10, vhod);
    *stBajtov = 3 * (*visina) * (*sirina);
    unsigned char *tabela = malloc(*stBajtov * sizeof(unsigned char));
    fread(tabela, sizeof(unsigned char), *stBajtov, vhod);
    return tabela;
}

int sivina(unsigned char *pike, int sirina, int visina, int vrstica, int stolpec)
{
    int index = (sirina * vrstica + stolpec) * 3;
    int R = pike[index];
    int G = pike[index + 1];
    int B = pike[index + 2];
    int result = (R + G + B) / 3;
    return result;
}

int main(int argc, char const *argv[])
{
    int visina, sirina, stBajtov;
    visina = 0;
    sirina = 0;
    stBajtov = 0;
    char *imeDatoteke = "slika01.ppm";
    unsigned char *tabela = preberi(imeDatoteke, &sirina, &visina, &stBajtov);
    printf("h: %d; w: %d; stB: %d\n", sirina, visina, stBajtov);

    int result = sivina(tabela, sirina, visina, 1, 0);
    printf("res: %d\n", result);
    return 0;
}
