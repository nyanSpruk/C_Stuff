#include <stdio.h>

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

int main(int argc, char const *argv[])
{
    long sumSquares = 0;
    long squareSum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sumSquares += i * i;
        squareSum += i;
    }
    squareSum *= squareSum;
    long result = sumSquares - squareSum;
    result = result < 0 ? -result : result;
    printf("%ld\n", result);
    return 0;
}
