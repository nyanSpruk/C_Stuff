#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int counter = 0;
    char c;
    bool novaBeseda = true;
    int st = 0;
    bool stevilo = false;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
        {
            if (stevilo)
            {
                counter += st;
                st = 0;
            }
            novaBeseda = true;
            stevilo = false;
        }
        else
        {
            if ((novaBeseda && c >= '0' && c <= '9') || (stevilo && (c >= '0' && c <= '9')))
            {
                stevilo = true;
                novaBeseda = false;
                st *= 10;
                st += c - '0';
            }
            else
            {
                stevilo = false;
                st = 0;
            }
            novaBeseda = false;
        }
    }
    if (c == '\n')
    {
        if (stevilo)
        {
            counter += st;
            st = 0;
        }
        novaBeseda = true;
        stevilo = false;
    }
    printf("%d\n", counter);
    return 0;
}
