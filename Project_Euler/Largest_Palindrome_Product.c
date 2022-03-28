#include <stdio.h>
#include <stdbool.h>

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

int main(int argc, char const *argv[])
{
    int max = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            int temp = i * j;
            if (isPalindrom(temp))
            {
                if (temp > max)
                    max = temp;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
