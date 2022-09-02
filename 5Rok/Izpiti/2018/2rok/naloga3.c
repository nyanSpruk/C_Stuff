#include <stdio.h>

int fun(int stKovancev, int stEnic)
{
    if (stEnic < 0)
        return 0;
    if (stEnic >= 0 && stKovancev == 0)
        return 1;

    return fun(stKovancev - 1, stEnic + 1) + fun(stKovancev - 1, stEnic - 1);
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    int result = fun(n, k);
    printf("%d\n", result);
    return 0;
}
