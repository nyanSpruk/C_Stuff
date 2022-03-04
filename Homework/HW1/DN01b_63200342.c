#include <stdio.h>
#include <stdbool.h>

void izpisi(int st)
{
    if (st / 10 > 0)
        izpisi(st / 10);
    putchar(st % 10 + '0');
}

int main(int argc, char const *argv[])
{
    bool enica = false;
    int counter = 0;
    int st;
    while ((st = getchar()) != EOF)
    {
        if (st == '1' && !enica)
        {
            enica = true;
            counter++;
        }
        else if (enica && (st == '1' || st == '0'))
        {
            counter++;
        }
    }
    izpisi(counter);
    putchar('\n');
    return 0;
}
