#include <stdio.h>

long MEMO[69][69][69];

long fun(int gor, int dol, int visina)
{
    if (visina < 0)
        return 0;
    if (gor == 0 || dol == 0)
        return 1;
    if (MEMO[gor][dol][visina] > 0)
        return MEMO[gor][dol][visina];
    long sum = 0;
    sum += fun(gor - 1, dol, visina + 1);
    sum += fun(gor, dol - 1, visina - 1);
    MEMO[gor][dol][visina] = sum;
    return sum;
}

int main()
{
    int st;
    scanf("%d", &st);
    long sum = fun(st / 2, st / 2, 0);
    printf("%ld\n", sum);

    return 0;
}