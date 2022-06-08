#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int MIN = INT_MAX;

void funkcija(int *stevila, int numSt, int counter, int vsotaEna, int vsotaDva)
{
    if (counter == numSt)
    {
        if (abs(vsotaEna - vsotaDva) < MIN)
        {
            MIN = abs(vsotaEna - vsotaDva);
            return;
        }
    }
    funkcija(stevila, numSt, counter + 1, vsotaEna + stevila[counter], vsotaDva);
    funkcija(stevila, numSt, counter + 1, vsotaEna, vsotaDva + stevila[counter]);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int *vrednosti = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vrednosti[i]);
    }
    int h = 0;
    funkcija(vrednosti, n, 0, 0, 0);
    printf("%d\n", MIN);
    return 0;
}
