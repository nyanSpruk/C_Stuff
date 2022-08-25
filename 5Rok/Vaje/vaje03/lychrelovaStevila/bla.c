#include <stdio.h>
#include <math.h>

// Vrne obrat števila a
long long obrat(long long a)
{
    if (a == 181)
    {
        int c = 0;
    }
    long long d = 0;
    int size = (int)log10(a) + 1;
    char str[size];
    sprintf(str, "%lld", a);
    for (int i = size - 1; i >= 0; i--)
    {
        d += (str[i] - '0') * pow(10, (i));
    }
    return d;
}
// Boolean, ki preveri če je število palindrom ali ne
int preveriPalindrom(long long a)
{
    if (a == obrat(a))
        return 1;
    else
        return 0;
}

int lych(int k, int a, int b)
{
    int ct = 0;

    for (int i = a; i <= b; i++)
    {
        // printf("a JE %d\n", i);
        long d = i;
        int step = 0;
        int check = 0;
        while (!preveriPalindrom(d) && step < k)
        {
            d += obrat(d);
            step++;
            // printf("%lld :: %d\n", d, step);
            if (d >= pow(10, 17))
                check++;
            if (check == 2)
                break;
        }
        if (!preveriPalindrom(d))
        {
            printf("%d\n", i);
            ct++;
        }
    }

    return ct;
}

int main()
{
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    printf("%d\n", lych(k, a, b));
    return 0;
}