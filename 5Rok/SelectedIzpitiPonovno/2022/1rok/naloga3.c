#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidBeseda(char *izpis, int stCrk)
{
    bool malaCrka = false;
    bool velikaCrka = false;
    bool stevilo = false;
    for (int i = 0; i < stCrk; i++)
    {
        char c = izpis[i];
        if (!malaCrka && c >= 'a' && c <= 'z')
            malaCrka = true;
        if (!velikaCrka && c >= 'A' && c <= 'Z')
            velikaCrka = true;
        if (!stevilo && c >= '0' && c <= '9')
            stevilo = true;
        if (malaCrka && velikaCrka && stevilo)
            return true;
    }
    return false;
}

void funkcija(int dolzina, int maxDolzina, char *izpis, int stCrk, char *crke)
{
    if (dolzina == maxDolzina)
    {
        if (isValidBeseda(izpis, dolzina))
            printf("%s\n", izpis);
        return;
    }
    for (int i = 0; i < stCrk; i++)
    {
        izpis[dolzina] = crke[i];
        funkcija(dolzina + 1, maxDolzina, izpis, stCrk, crke);
        izpis[dolzina] = ' ';
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char *crke = malloc(n * sizeof(char));
    scanf("%s", crke);
    int dolzina;
    scanf("%d", &dolzina);
    char *izpis = malloc(dolzina * sizeof(char));
    funkcija(0, dolzina, izpis, n, crke);
    return 0;
}
