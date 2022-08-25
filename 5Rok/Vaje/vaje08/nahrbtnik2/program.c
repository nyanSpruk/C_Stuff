#include <stdio.h>
#include <stdbool.h>

int MEMO[1001][2][1001];

int backpack(int numOfEl, int volumes[], int prices[], int index, int volume, bool zeDodalLiho)
{
    if (index == numOfEl)
        return 0;

    // Ce smo vrednost backpack(..., index, volume) ze izracunali
    if (MEMO[index][zeDodalLiho][volume] > 0)
        return MEMO[index][zeDodalLiho][volume];

    int najCena = backpack(numOfEl, volumes, prices, index + 1, volume, zeDodalLiho);

    bool lihaProstornina = (volumes[index] % 2 == 1);

    if (volumes[index] <= volume && (!lihaProstornina || !zeDodalLiho))
    {
        int c = prices[index] + backpack(numOfEl, volumes, prices, index + 1, volume - volumes[index], (zeDodalLiho || lihaProstornina));
        if (c > najCena)
            najCena = c;
    }
    MEMO[index][zeDodalLiho][volume] = najCena;
    return najCena;
}

int optCena(int stPredmetov, int prostornine[], int cene[], int ix, bool zeDodalLiho, int vNah, int counterLihih)
{
    if (ix == stPredmetov)
        return 0;
    if (MEMO[ix][zeDodalLiho][vNah] > 0)
        return MEMO[ix][zeDodalLiho][vNah];

    int najCena = optCena(stPredmetov, prostornine, cene, ix + 1, zeDodalLiho, vNah, counterLihih);

    bool lihaProstornina = (prostornine[ix] % 2 == 1);

    if (prostornine[ix] <= vNah && ((!lihaProstornina && counterLihih < 1) || !zeDodalLiho))
    {
        int c = cene[ix] + optCena(stPredmetov, prostornine, cene, ix + 1, (zeDodalLiho || lihaProstornina), vNah - prostornine[ix], counterLihih - 1);
        if (c > najCena)
            najCena = c;
    }
    MEMO[ix][zeDodalLiho][vNah] = najCena;
    return najCena;
}

int main(int argc, char const *argv[])
{
    int volume, numOfObjects, stLihih;
    scanf("%d %d %d", &volume, &numOfObjects, &stLihih);
    int volumes[numOfObjects];
    int prices[numOfObjects];
    for (int i = 0; i < numOfObjects; i++)
        scanf("%d", &volumes[i]);
    for (int i = 0; i < numOfObjects; i++)
        scanf("%d", &prices[i]);
    // int result = backpack(numOfObjects, volumes, prices, 0, volume, false);
    int result = optCena(numOfObjects, volumes, prices, 0, false, volume, stLihih);
    printf("%d\n", result);
    return 0;
}
