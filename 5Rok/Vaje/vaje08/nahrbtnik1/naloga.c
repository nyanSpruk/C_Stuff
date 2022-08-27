#include <stdio.h>
#include <stdlib.h>

int MEMO[1001][1001];

int backpack(int prostornina, int stPredmetov, int volumenPredmetov[], int cenePredmetov[], int indeks)
{
    if (indeks == stPredmetov)
        return 0;

    if (MEMO[indeks][prostornina] > 0)
        return MEMO[indeks][prostornina];
    int cena = backpack(prostornina, stPredmetov, volumenPredmetov, cenePredmetov, indeks + 1);

    if (prostornina >= volumenPredmetov[indeks])
    {
        int cena2 = cenePredmetov[indeks] + backpack(prostornina - volumenPredmetov[indeks], stPredmetov, volumenPredmetov, cenePredmetov, indeks + 1);
        if (cena2 > cena)
        {
            cena = cena2;
        }
    }
    MEMO[indeks][prostornina] = cena;
    return cena;
}

int main(int argc, char const *argv[])
{
    int prostornina, stPredmetov;
    int *volumenPredmetov, *cenePredmetov;
    scanf("%d %d", &prostornina, &stPredmetov);

    volumenPredmetov = malloc(stPredmetov * sizeof(int));
    cenePredmetov = malloc(stPredmetov * sizeof(int));

    for (int i = 0; i < stPredmetov; i++)
    {
        scanf("%d", &volumenPredmetov[i]);
    }
    for (int i = 0; i < stPredmetov; i++)
    {
        scanf("%d", &cenePredmetov[i]);
    }
    int result = backpack(prostornina, stPredmetov, volumenPredmetov, cenePredmetov, 0);
    printf("%d\n", result);
    return 0;
}
