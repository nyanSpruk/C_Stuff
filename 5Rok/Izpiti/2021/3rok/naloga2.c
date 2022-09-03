#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 100;

char **pretvori(char tabela[][N], int m)
{
    char **rezultat = malloc(m * sizeof(char *));
    for (int i = 0; i < m; i++)
    {
        char *endVrstice = strchr(tabela[i], '\0');
        int dolzina = endVrstice - &(tabela[i][0]);
        char *vrstica = malloc(dolzina * sizeof(char));
        strcpy(vrstica, &(tabela[i][0]));
        rezultat[i] = vrstica;
    }
    return rezultat;
}

int main(int argc, char const *argv[])
{
    char t[2][100] = {
        "String 1",
        "String 2 electric boogalo"};
    char **rez = pretvori(t, 2);
    for (int i = 0; i < 2; i++)
    {
        printf("%s\n", rez[i]);
    }

    return 0;
}
