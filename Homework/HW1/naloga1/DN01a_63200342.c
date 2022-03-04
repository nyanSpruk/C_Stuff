#include <stdio.h>
#include <stdbool.h>

void izpisi(long st)
{
    if (st < 0)
    {
        putchar('-');
        st = -st;
    }
    if (st / 10 > 0)
        izpisi(st / 10);
    putchar(st % 10 + '0');
}

int main(int argc, char const *argv[])
{

    long c = getchar();
    long val = 0;
    long isNeg = 1;
    if (c == '-')
        isNeg = -1;
    else
    {
        val += c - '0';
        val *= 10;
    }
    while ((c = getchar()) != ' ')
    {
        if (c >= '0' && c <= '9')
        {
            val += (c - '0');
            val *= 10;
        }
    }
    val /= 10;
    val *= isNeg;

    isNeg = 1;
    long val2 = 0;
    c = getchar();
    if (c == '-')
        isNeg = -1;
    else
    {
        val2 += c - '0';
        val2 *= 10;
    }
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            val2 += (c - '0');
            val2 *= 10;
        }
    }
    val2 /= 10;
    val2 *= isNeg;
    val += val2;

    izpisi(val);
    putchar('\n');
    return 0;
}
