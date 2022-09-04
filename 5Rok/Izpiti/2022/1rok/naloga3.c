#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *niz)
{
    bool malaCrka = false;
    bool velikaCrka = false;
    bool stevilka = false;
    int len = strlen(niz);
    for (int i = 0; i < len; i++)
    {

        if (!malaCrka && niz[i] >= 'a' && niz[i] <= 'z')
            malaCrka = true;
        if (!velikaCrka && niz[i] >= 'A' && niz[i] <= 'Z')
            velikaCrka = true;
        if (!stevilka && niz[i] >= '0' && niz[i] <= '9')
            stevilka = true;
        if (malaCrka && velikaCrka && stevilka)
            break;
    }
    return malaCrka && velikaCrka && stevilka;
}

void fun(char *crke, int maxDolzina, int dolzina, char *izpis, int stCrk)
{
    if (dolzina == maxDolzina)
    {
        if (isValid(izpis))
            printf("%s\n", izpis);
        return;
    }
    for (int i = 0; i < stCrk; i++)
    {
        izpis[dolzina] = crke[i];
        fun(crke, maxDolzina, dolzina + 1, izpis, stCrk);
        izpis[dolzina] = ' ';
    }
}

int main(int argc, char const *argv[])
{
    int d, n;
    scanf("%d", &d);
    char *crke = malloc(d * sizeof(char));
    scanf("%s", crke);
    scanf("%d", &n);
    char *izpis = malloc(n * sizeof(char));
    fun(crke, n, 0, izpis, d);
    return 0;
}
