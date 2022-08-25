#include <stdio.h>

int MEMO[1001][1001];

int backpack(int numOfEl, int volumes[], int prices[], int index, int volume)
{
    if (index == numOfEl)
        return 0;

    // Ce smo vrednost backpack(..., index, volume) ze izracunali
    if (MEMO[index][volume] > 0)
        return MEMO[index][volume];
    int najCena = backpack(numOfEl, volumes, prices, index + 1, volume);

    if (volumes[index] <= volume)
    {
        int c = prices[index] + backpack(numOfEl, volumes, prices, index + 1, volume - volumes[index]);
        if (c > najCena)
            najCena = c;
    }
    MEMO[index][volume] = najCena;
    return najCena;
}
int main(int argc, char const *argv[])
{
    // Input:
    /*
    12
    5
    3 4 7 2 3
    5 6 8 9 1
    */

    int volume, numOfObjects;
    scanf("%d %d", &volume, &numOfObjects);
    int volumes[numOfObjects];
    int prices[numOfObjects];
    for (int i = 0; i < numOfObjects; i++)
    {
        scanf("%d", &volumes[i]);
    }
    for (int i = 0; i < numOfObjects; i++)
    {
        scanf("%d", &prices[i]);
    }
    int result = backpack(numOfObjects, volumes, prices, 0, volume);
    printf("%d", result);
    return 0;
}
