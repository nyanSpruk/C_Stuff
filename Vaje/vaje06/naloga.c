
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char *niz, char znak)
{
    int counter = 0;
    for (char *p = niz; *p != '\0'; p++)
        if (*p == znak)
            counter++;
    return counter;
}

int dolzinaDoZnaka(char *niz, char znak)
{
    int counter = 0;
    for (char *p = niz; *p != znak && *p != '\0'; p++)
        counter++;
    return counter;
}

char *kopirajDoZnaka(char *niz, char znak)
{
    int velikostArr = dolzinaDoZnaka(niz, znak);
    char *newArr = calloc(velikostArr + 1, sizeof(char));
    char *p = niz;
    for (int i = 0; i < velikostArr; i++, p++)
    {
        *(newArr + i) = *p;
    }
    newArr[velikostArr] = '\0';
    return newArr;
}

char **razcleni(char *niz, char locilo, int *stOdsekov)
{
    *stOdsekov = steviloZnakov(niz, locilo) + 1;
    char **tabela = calloc(*stOdsekov, sizeof(char *));
    int counterZnakov = 0;
    for (char *p = niz; *p != '\0'; p++)
    {
        if (*p == locilo)
        {
            int dolzinaOdseka = dolzinaDoZnaka(niz, locilo) + 1;
            char *temp = kopirajDoZnaka(niz, locilo);
            *(tabela + counterZnakov) = temp;
            niz += dolzinaOdseka;
            counterZnakov++;
        }
    }
    *(tabela + counterZnakov) = kopirajDoZnaka(niz, locilo);
    // for (int i = 0; i < *stOdsekov; i++)
    // {
    //     *(tabela + i) = kopirajDoZnaka(niz, locilo);
    // }

    return tabela;
}

// void pozeni(char *niz, char znak)
// {
//     char *kopija = kopirajDoZnaka(niz, znak);
//     printf("<%s>\n", kopija);
//     free(kopija);
// }

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    // char *niz = "";

    // pozeni(niz, ' ');
    // pozeni(niz, '_');
    return 0;
}
