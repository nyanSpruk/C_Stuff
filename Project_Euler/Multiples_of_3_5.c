#include <stdio.h>

// Find the sum of all the multiples of 3 or 5 below 1000.

int main(int argc, char const *argv[])
{
    int vsota = 0;
    for (int i = 1; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            vsota += i;
    }
    printf("%d\n", vsota);
    return 0;
}
