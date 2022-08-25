#include <stdio.h>

long fun(n, k)
{
    if (k == 0)
        return 0;
    if (n == 0)
        return 1;
    if (k > n)
        k = n;

    return fun(n - k, k) + fun(n, k - 1);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    long vsota = 0;
    vsota = fun(n, k);
    printf("%ld\n", vsota);
    return 0;
}
