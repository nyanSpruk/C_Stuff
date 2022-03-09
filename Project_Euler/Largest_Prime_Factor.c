#include <stdio.h>

// What is the largest prime factor of the number 600851475143 ?

int main(int argc, char const *argv[])
{
    long largest = 0;
    long number = 600851475143;
    while (number % 2 == 0)
    {
        number /= 2;
        largest = 2;
    }
    while (number % 3 == 0)
    {
        largest = 3;
        number /= 3;
    }
    long multip = 6;
    while (multip - 1 <= number)
    {
        if (number % (multip - 1) == 0)
        {
            largest = multip - 1;
            while (number % largest == 0)
            {
                number /= largest;
            }
        }
        if (number % (multip + 1) == 0)
        {
            largest = multip + 1;
            while (number % largest == 0)
            {
                number /= largest;
            }
        }
        multip += 6;
    }
    printf("%ld\n", largest);
    return 0;
}
