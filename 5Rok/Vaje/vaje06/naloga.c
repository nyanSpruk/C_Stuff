
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char *niz, char znak)
{
    int counter = 0;
    char *p = niz;
    while (*p != '\0')
    {
        if (*p == znak)
            counter++;
        p++;
    }
    return counter;
}

int doZnaka(char *niz, char znak)
{
    int counter = 0;
    char *p = niz;
    while (*p != znak)
    {
        counter++;
        p++;
    }
    return counter;
}

char *kopirajDoZnaka(char *niz, char znak)
{
    int dolzinaDoZnaka = doZnaka(niz, znak);
    char *novString = calloc(dolzinaDoZnaka + 1, sizeof(char));
    for (int i = 0; i < dolzinaDoZnaka; i++)
        novString[i] = niz[i];

    return novString;
}

int stZnakov(char *niz, char locilo)
{
    int counter = 0;
    char *p = niz;
    while (*p != '\0')
    {
        if (*p == locilo)
            counter++;
        p++;
    }
    return counter;
}
char **razcleni(char *niz, char locilo, int *stOdsekov)
{
    *stOdsekov = stZnakov(niz, locilo) + 1;
    char **odseki = malloc(*stOdsekov * sizeof(char *));
    for (int i = 0; i < *stOdsekov; i++)
    {
        int dolzinaDoZnaka = doZnaka(niz, locilo);
        char *odsek = kopirajDoZnaka(niz, locilo);
        for (int j = 0; j < dolzinaDoZnaka + 1; j++)
            niz++;
        odseki[i] = odsek;
    }
    return odseki;
}

// void pozeni(char *niz, char locilo)
// {
//     int stOdsekov = 0;
//     char **odseki = razcleni(niz, locilo, &stOdsekov);
//     for (int i = 0; i < stOdsekov; i++)
//     {
//         printf("%d: <%s>\n", i + 1, odseki[i]);
//         free(odseki[i]);
//     }
//     free(odseki);
// }

int main()
{
    // char *niz = "prijazen niz z enim samim presledkom med besedami";
    // pozeni(niz, ' ');
    return 0;
}
