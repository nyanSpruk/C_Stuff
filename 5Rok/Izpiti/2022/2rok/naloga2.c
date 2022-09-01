#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Vozlisce
{
    struct _Vozlisce *naslednje;
} Vozlisce;

int dolzinaCikla(Vozlisce *zacetek)
{
    int index = 0;
    bool cikel = false;
    Vozlisce **vozlisca = malloc(1000 * sizeof(Vozlisce));
    while (1)
    {
        for (int i = 0; i < index; i++)
        {
            if (vozlisca[i] == zacetek && cikel)
            {
                printf("%d\n", index - i);
                break;
            }
        }
        vozlisca[index] = zacetek;
        index++;
        zacetek = zacetek->naslednje;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    Vozlisce *zac = malloc(sizeof(Vozlisce));
    zac->naslednje = malloc(sizeof(Vozlisce));
    zac->naslednje->naslednje = malloc(sizeof(Vozlisce));
    zac->naslednje->naslednje->naslednje = malloc(sizeof(Vozlisce));

    zac->naslednje->naslednje->naslednje->naslednje = malloc(sizeof(Vozlisce));
    zac->naslednje->naslednje->naslednje->naslednje->naslednje = malloc(sizeof(Vozlisce));
    zac->naslednje->naslednje->naslednje->naslednje->naslednje->naslednje = malloc(sizeof(Vozlisce));
    zac->naslednje->naslednje->naslednje->naslednje->naslednje->naslednje->naslednje = malloc(sizeof(Vozlisce));
    zac->naslednje->naslednje->naslednje->naslednje->naslednje->naslednje->naslednje->naslednje = zac->naslednje->naslednje->naslednje;

    int counter = dolzinaCikla(zac);
    return 0;
}
