#include <stdio.h>
int counter = 0;

void funkcija(int stKovancev, int stEnic)
{
    if (stEnic < 0)
        return;
    if (stKovancev == 0 && stEnic >= 0)
    {
        counter++;
        return;
    }

    funkcija(stKovancev - 1, stEnic - 1);
    funkcija(stKovancev - 1, stEnic + 1);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    funkcija(n, k);
    printf("%d\n", counter);
    return 0;
}
