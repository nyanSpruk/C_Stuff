#include <stdio.h>
long counter = 0;

void funkcija(long n, long gor, long dol)
{
    if (gor == dol && n == (gor + dol))
    {
        counter++;
        return;
    }
    if (gor < n / 2)
        funkcija(n, gor + 1, dol);
    if (dol < gor)
        funkcija(n, gor, dol + 1);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    funkcija(n, 0, 0);
    printf("%ld\n", counter);
    return 0;
}
