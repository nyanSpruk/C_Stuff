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
    int st = 0;
    bool nicle = true;
    int input;
    int counter = 0;
    while ((input = getchar()) != '\n')
    {
        st *= 2;
        st += (input - '0') * 2;
        if (st != 0)
        {
            counter++;
            if (counter > 1 && input != '0')
                nicle = false;
        }
    }
    nicle ? izpisi(counter - 1) : izpisi(counter);
    putchar('\n');
    return 0;
}
