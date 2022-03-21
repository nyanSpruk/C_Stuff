#include <stdio.h>

long preberiVhod()
{
    long stevilo = 0;
    long temp = 0;
    while (temp != -38)
    {
        temp = getchar() - '0';
        if (temp == -38)
            break;
        stevilo += temp;
        stevilo *= 10;
    }

    return stevilo / 10;
}

long binaryToDecimal()
{
    long a = preberiVhod();
    long decimal = 0;
    long mnozitelj = 1;

    while (a != 0)
    {
        if ((a % 10) == 1)
            decimal += mnozitelj;
        a /= 10;
        mnozitelj *= 2;
    }

    return decimal;
}

long logaritem()
{
    long a = binaryToDecimal();
    long logarithm = 0;

    // printf("%ld ", a);
    while (a != 1)
    {
        if (a % 2 == 1)
            a = (a / 2) + 1;
        else
            a /= 2;
        logarithm++;
    }
    return logarithm;
}

void pisanjeIzhoda()
{
    long a = logaritem();
    // printf("%ld ", a);
    int stMest = 1;
    while ((a / stMest) > 10)
    {
        stMest *= 10;
    }
    while (stMest != 0)
    {
        int izpis = a / stMest;
        putchar(izpis + '0');
        a -= (stMest * izpis);
        stMest /= 10;
    }
    putchar('\n');
}

int main()
{
    pisanjeIzhoda();
    return 0;
}