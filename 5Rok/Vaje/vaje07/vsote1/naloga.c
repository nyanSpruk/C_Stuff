#include <stdio.h>

int counter = 0;

long funkcija(int n, int k)
{
    if (k == 0)
        return 0;
    if (n == 0)
        return 1;
    if (k > n)
        k = n;

    return funkcija(n - k, k) + funkcija(n, k - 1);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    int result = funkcija(n, k);
    printf("%d\n", result);
    return 0;
}
