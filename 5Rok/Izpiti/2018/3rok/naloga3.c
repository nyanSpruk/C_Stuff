#include <stdio.h>
#include <stdlib.h>

int MEMO[100];

int fun(int n, int a, int b)
{
    if (MEMO[n] > 0)
        return MEMO[n];
    if (n == 0)
        return 1;
    MEMO[n / a] = fun(n / a, a, b);
    MEMO[n / b] = fun(n / b, a, b);

    return MEMO[n / a] + MEMO[n / b];
}

int main(int argc, char const *argv[])
{
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    int counter = 1;
    fun(n, a, b);
    for (int i = 0; i < 100; i++)
    {
        if (MEMO[i] > 0)
            counter++;
    }
    printf("%d\n", counter);
    return 0;
}
