#include <stdio.h>

// Write a program to count how many times a specific number appears, a whitespace and other characters

int main(int argc, char const *argv[])
{
    int c, i, whiteCount, otherCount;
    int digitCount[10];
    whiteCount = otherCount = 0;
    for (i = 0; i < 10; i++)
        digitCount[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            digitCount[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '\n')
            whiteCount++;
        else
            otherCount++;
    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", digitCount[i]);
    printf(", white space = %d, other = %d\n", whiteCount, otherCount);

    return 0;
}
