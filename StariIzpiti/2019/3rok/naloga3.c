#include <stdio.h>

int max = 0;

char MEMO[1000];

void funkcija(int n, int k1, int k2, int stPotez, int indexSkokov, int polozaj)
{
    if (indexSkokov > stPotez || polozaj > n || polozaj < 0)
        return;
    if (MEMO[polozaj] == 0)
        MEMO[polozaj] = 1;
    funkcija(n, k1, k2, stPotez, indexSkokov + 1, polozaj + k1);
    funkcija(n, k1, k2, stPotez, indexSkokov + 1, polozaj + k2);
    funkcija(n, k1, k2, stPotez, indexSkokov + 1, polozaj - k1);
    funkcija(n, k1, k2, stPotez, indexSkokov + 1, polozaj - k2);
    return;
}

int main(int argc, char const *argv[])
{
    int n, k1, k2, s;
    scanf("%d %d %d %d", &n, &k1, &k2, &s);
    funkcija(n, k1, k2, s, 0, 0);
    int unikatni = 0;
    for (int i = 0; i < n; i++)
        unikatni += MEMO[i];
    printf("%d\n", unikatni);
    return 0;
}
