#include <stdio.h>
#include <stdlib.h>

typedef struct klub
{
    char imeKluba[21];
    int stClanov;
    char **imenaClanov;
} Klub;

Klub *izdelaj()
{
    Klub *klub = malloc(sizeof(Klub));
    scanf("%s", klub->imeKluba);
    scanf("%d", &(klub->stClanov));
    klub->imenaClanov = malloc(klub->stClanov * sizeof(char *));
    for (size_t i = 0; i < klub->stClanov; i++)
    {
        klub->imenaClanov[i] = malloc(21 * sizeof(char));
        scanf("%s", klub->imenaClanov[i]);
    }
    return klub;
}

int main(int argc, char const *argv[])
{
    Klub *k = izdelaj();
    printf("Ime kluba je %s\n", k->imeKluba);
    printf("St Clanov je %d\n", k->stClanov);
    for (int i = 0; i < k->stClanov; i++)
    {
        printf("Ime clana %d je %s\n", i, k->imenaClanov[i]);
    }

    return 0;
}
