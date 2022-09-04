#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char znak;
    char prev = ' ';
    int totalSum = 0;
    int counter = 0;
    bool vSt = false;
    while ((znak = getchar()) != '\n')
    {
        if (prev == ' ' && !vSt && (znak >= '0' && znak <= '9'))
        {
            counter += znak - '0';
            vSt = true;
        }
        else if (vSt && (znak >= '0' && znak <= '9'))
            counter = counter * 10 + (znak - '0');
        else if (vSt && znak == ' ')
        {
            totalSum += counter;
            counter = 0;
            vSt = false;
        }
        else if (vSt)
        {
            counter = 0;
            vSt = false;
        }
        prev = znak;
    }
    if (vSt)
        totalSum += counter;
    printf("%d\n", totalSum);
    return 0;
}
