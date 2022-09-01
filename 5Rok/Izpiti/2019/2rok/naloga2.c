#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct oseba
{              // oseba s podanim imenom in starostjo
    char *ime; // zaporedje do 20 črk angleške abecede
    int starost;
} Oseba;

void uredi(Oseba **osebe, int n)
{
    for (int i = 0; i < n; i++)
    {
        Oseba *osebaToCompare = osebe[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (strcmp(osebe[j]->ime, osebaToCompare->ime) > 0)
            {
                osebe[j + 1] = osebe[j];
                osebe[j] = osebaToCompare;
                osebaToCompare = osebe[j];
            }
            else
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
    char imena[6][10] = {"Bojan", "Ana", "Bojan", "Cene", "Bojan", "Ana"};
    int starost[10] = {30, 25, 40, 15, 20, 20};
    // char imena[10][10] = {"Bojan", "Ana", "Miro", "Luk", "Vog", "Grzi", "Xyz", "Bizi",
    //                       "Anabele", "Mare"};
    // int starost[10] = {24, 74, 32, 29, 10, 99, 1324, 432, 2, 123};

    Oseba **osebe = malloc(sizeof(Oseba) * 6);
    for (int i = 0; i < 6; i++)
    {
        Oseba *nova = malloc(sizeof(Oseba));
        nova->ime = imena[i];
        nova->starost = starost[i];
        osebe[i] = nova;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("{\"%s\", %d}\n", osebe[i]->ime, osebe[i]->starost);
    }
    uredi(osebe, 6);
    printf("\n_________UREJENO_________\n");
    for (int i = 0; i < 6; i++)
    {
        printf("{\"%s\", %d}\n", osebe[i]->ime, osebe[i]->starost);
    }
    return 0;
}
