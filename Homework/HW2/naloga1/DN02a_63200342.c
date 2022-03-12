#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        bool stevilo = true;
        if (c == '+' || c == '-')
        {
            c = getchar();
            if (c == ' ' || c == '\n' || c == EOF)
                stevilo = false;
        }
        bool nicla = (c == '0');
        if (nicla)
            c = getchar();

        while (c != ' ' && c != '\n')
        {
            if (nicla || c < '0' || c > '9')
                stevilo = false;
            c = getchar();
        }
        putchar(stevilo ? '1' : '0');
    }
    putchar('\n');
    return 0;
}
