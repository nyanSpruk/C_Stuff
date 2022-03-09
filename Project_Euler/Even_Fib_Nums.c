#include <stdio.h>

// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

int main(int argc, char const *argv[])
{
    long vsota = 2;
    long a = 1, b = 2;
    long temp = 0;
    while (b < 4000000)
    {
        temp = b;
        b += a;
        a = temp;
        if (b % 2 == 0)
            vsota += b;
    }
    printf("%ld\n", vsota);
    return 0;
}
