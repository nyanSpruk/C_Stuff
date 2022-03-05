#include <stdio.h>

int main(int argc, char const *argv[])
{
    int curr, prev;
    while ((curr = getchar()) != EOF)
    {
        if (!(curr == ' ' && prev == ' '))
            putchar(curr);
        prev = curr;
    }
    return 0;
}
