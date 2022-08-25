#include <stdio.h>
#include <stdbool.h>

long reverseNum(long n)
{
    long num = 0;
    while (n > 0)
    {
        num = num * 10 + n % 10;
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
    return j;
}

bool isLyche(long num, int k)
{
    for (long i = 0; i < k; i++)
    {
        num += reverseNum(num);
        if (isPalindrom(num))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    long k, a, b;
    long counter = 0;
    scanf("%ld %ld %ld", &k, &a, &b);
    for (long i = a; i <= b; i++)
    {
        if (!isLyche(i, k))
            counter++;
    }
    printf("%ld\n", counter);
    return 0;
}
