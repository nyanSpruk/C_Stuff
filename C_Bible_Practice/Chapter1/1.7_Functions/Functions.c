// C doesnt have a function for ** by writing a function ourselves

#include <stdio.h>

// Just decleration.. a function prototype
// Functions can only access other functions ABOVE IT
int power(int m, int n);

int main(int argc, char const *argv[])
{
    int val = power(2, 3);
    printf("2^3 = %d\n", val);
    return 0;
}

int power(int base, int eksp)
{
    int p = 1;
    for (int i = 1; i <= eksp; i++)
        p *= base;

    return p;
}