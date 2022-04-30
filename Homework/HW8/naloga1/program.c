#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stMoznosti;

bool jeNarascajoce(int *arr, int dolzina)
{
    for (int i = 0; i < dolzina - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

int *zamenjaj(int *arr, int dolzinaArr, int stZamenjav, int prviIndex, int drugiIndex)
{
    int *newArr = malloc(sizeof(int) * dolzinaArr);
    for (int i = 0; i < dolzinaArr; i++)
    {
        if (i >= prviIndex && i < prviIndex + stZamenjav)
            newArr[i] = arr[drugiIndex + i - prviIndex];
        else if (i >= drugiIndex && i < drugiIndex + stZamenjav)
            newArr[i] = arr[prviIndex + i - drugiIndex];
        else
            newArr[i] = arr[i];
    }
    return newArr;
}
void rekurzija(int *arr, int k, int n, int r, int st_korakov)
{
    if (jeNarascajoce(arr, n))
        stMoznosti++;
    if (st_korakov == k)
        return;
    for (int i = 0; i <= n - 2 * r; i++)
        for (int j = i + r; j <= n - r; j++)
            rekurzija(zamenjaj(arr, n, r, i, j), k, n, r, st_korakov + 1);
}

int main(int argc, char const *argv[])
{
    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    int *stevila = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &stevila[i]);

    rekurzija(stevila, k, n, r, 0);
    free(stevila);
    printf("%d\n", stMoznosti);
    return 0;
}
