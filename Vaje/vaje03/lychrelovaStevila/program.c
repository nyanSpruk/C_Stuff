#include <stdio.h>
#include <stdbool.h>

long reverseNum(long n)
{
    long num = 0;
    while (n > 0)
    {
        num *= 10;
        num += n % 10;
        n /= 10;
    }
    return num;
}

bool isPalindrom(long n)
{
    long original = n, remainder, reversed = 0;
    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    int j = original == reversed;
    return original == reversed;
}

bool isLyrchee(long stIteracij, long n)
{
    for (long i = 0; i < stIteracij; i++)
    {
        n += reverseNum(n);
        if (isPalindrom(n))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    long numIteracij, a, b, counter = 0;
    scanf("%ld %ld %ld", &numIteracij, &a, &b);
    for (long i = a; i <= b; i++)
        if (!isLyrchee(numIteracij, i))
        {
            // printf("%ld\n", i);

            counter++;
        }

    printf("%ld\n", counter);
    return 0;
}
