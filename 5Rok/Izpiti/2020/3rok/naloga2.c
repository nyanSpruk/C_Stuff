#include <stdio.h>
#include <stdlib.h>

typedef struct klub
{
    char *imeKluba;
    int stClanov;
    char **clani;
} Klub;

Klub *izdelaj()
{
    Klub *k = malloc(sizeof(Klub));
    k->imeKluba = malloc(20 * sizeof(char));
    scanf("%s", k->imeKluba);
    scanf("%d", &k->stClanov);
    k->clani = malloc(k->stClanov * sizeof(char *));
    for (int i = 0; i < k->stClanov; i++)
    {
        k->clani[i] = malloc(20 * sizeof(char));
        scanf("%s", k->clani[i]);
    }
    return k;
}

int main(int argc, char const *argv[])
{
    Klub *k = izdelaj();
    printf("Ime kluba: %s\n", k->imeKluba);
    printf("St clanov: %d\n", k->stClanov);
    for (int i = 0; i < k->stClanov; i++)
    {
        printf("Clan id: %d ime: %s\n", i + 1, k->clani[i]);
    }

    return 0;
}
