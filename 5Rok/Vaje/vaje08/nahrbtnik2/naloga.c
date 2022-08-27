#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MEMO[1001][2][1001];

int backpack(int prostornina, int stPredmetov, int volumenPredmetov[], int cenePredmetov[], int indeks, bool lihoDodano, int counterLihih)
{
    if (indeks == stPredmetov)
        return 0;

    if (MEMO[indeks][lihoDodano][prostornina] > 0)
        return MEMO[indeks][lihoDodano][prostornina];
    int cena = backpack(prostornina, stPredmetov, volumenPredmetov, cenePredmetov, indeks + 1, lihoDodano, counterLihih);

    bool aliProstorninaLiha = (volumenPredmetov[indeks] % 2 == 1);

    if (prostornina >= volumenPredmetov[indeks] && ((!aliProstorninaLiha && counterLihih < 1) || !lihoDodano))
    {
        int cena2 = cenePredmetov[indeks] + backpack(prostornina - volumenPredmetov[indeks], stPredmetov, volumenPredmetov, cenePredmetov, indeks + 1, (lihoDodano || aliProstorninaLiha), counterLihih - 1);
        if (cena2 > cena)
            cena = cena2;
    }
    MEMO[indeks][lihoDodano][prostornina] = cena;
    return cena;
}

int main(int argc, char const *argv[])
{
    int prostornina, stPredmetov, k;
    int *volumenPredmetov, *cenePredmetov;
    scanf("%d %d %d", &prostornina, &stPredmetov, &k);

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
    int result = backpack(prostornina, stPredmetov, volumenPredmetov, cenePredmetov, 0, false, k);
    printf("%d\n", result);
    return 0;
}
