#include <stdlib.h>
#include <stdio.h>

char MEMO[1000];

void fun(int n, int k1, int k2, int s, int pozicija)
{
    if (s < 0 || pozicija > n || pozicija < 0)
        return;
    if (MEMO[pozicija] == 0)
        MEMO[pozicija] = 1;
    fun(n, k1, k2, s - 1, pozicija - k1);
    fun(n, k1, k2, s - 1, pozicija - k2);
    fun(n, k1, k2, s - 1, pozicija + k1);
    fun(n, k1, k2, s - 1, pozicija + k2);
    return;
}

int main(int argc, char const *argv[])
{
    int n, k1, k2, s;
    // scanf("%d %d %d %d", &n, &k1, &k2, &s);
    n = 12;
    k1 = 4;
    k2 = 6;
    s = 2;
    fun(n, k1, k2, s, n);
    int counter = 0;
    for (int i = 0; i < n; i++)
        counter += MEMO[i];

    printf("%d\n", counter);
    return 0;
}
