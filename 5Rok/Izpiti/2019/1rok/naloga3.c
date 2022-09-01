#include <stdio.h>

long long MEMO[69][69][69];

long long fun(int visina, int counterGor, int counterDol)
{
    if (visina < 0)
        return 0;
    if (counterDol == 0 || counterGor == 0)
        return 1;
    if (MEMO[counterGor][counterDol][visina] > 0)
        return MEMO[counterGor][counterDol][visina];
    long long sum = 0;
    sum += fun(visina + 1, counterGor - 1, counterDol);
    sum += fun(visina - 1, counterGor, counterDol - 1);
    MEMO[counterGor][counterDol][visina] = sum;
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    long long counter = fun(0, n / 2, n / 2);
    printf("%lld\n", counter);
    return 0;
}
