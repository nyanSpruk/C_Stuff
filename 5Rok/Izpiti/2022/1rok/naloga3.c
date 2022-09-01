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

void fun(char *znaki, int maxDolzina, int counter, char *beseda, int stZnakov)
{
    if (counter == maxDolzina)
    {
        if (isValid(beseda))
            printf("%s\n", beseda);
        return;
    }
    for (int i = 0; i < stZnakov; i++)
    {
        beseda[counter] = znaki[i];
        fun(znaki, maxDolzina, counter + 1, beseda, stZnakov);
        beseda[counter] = ' ';
    }
}

int main(int argc, char const *argv[])
{
    int d, n;
    scanf("%d", &d);
    char *znaki = malloc(d * sizeof(char));
    scanf("%s", znaki);
    scanf("%d", &n);
    char *beseda = malloc(n * sizeof(char));
    fun(znaki, n, 0, beseda, d);
    return 0;
}
