#include <stdio.h>

int memo[1000001];
int counter;
void funkcija(int a, int b, int n)
{
    if (memo[n] == 1)
        return;
    memo[n] = 1;
    counter++;
    if (n > 0)
    {
        funkcija(a, b, n / a);
        funkcija(a, b, n / b);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    funkcija(a, b, n);

    printf("%d\n", counter);
    return 0;
}
