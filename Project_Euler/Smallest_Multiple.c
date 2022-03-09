#include <stdio.h>
#include <stdbool.h>
bool isDivisible(int num)
{
    for (int i = 1; i <= 20; i++)
        if (num % i != 0)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    int i = 1;
    while (!(isDivisible(i)))
    {
        i++;
    }
    printf("%d\n", i);
    return 0;
}
