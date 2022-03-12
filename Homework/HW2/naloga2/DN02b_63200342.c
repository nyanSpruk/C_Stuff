#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        bool jeHex = false;
        bool jeBin = false;
        bool jeNum = false;
        bool jeNic = false;
        bool jeSt = true;
        if (c < '0' || c > '9')
            jeSt = false;
        else if (c == '0')
        {
            jeNic = true;
            c = getchar();
            if (c == 'b')
            {
                jeBin = true;
                jeNic = false;
            }
            else if (c == 'x')
            {
                jeHex = true;
                jeNic = false;
            }
            else if ((c < '0' || c > '7') && (c != ' ' && c != '\n'))
            {
                jeSt = false;
                jeNic = true;
            }
        }
        else if (c > '0' || c <= '9')
            jeNum = true;

        if (c == 'b' || c == 'x')
        {
            c = getchar();
            if (c == ' ' || c == '\n')
                jeSt = false;
        }

        while (c != ' ' && c != '\n')
        {
            if (jeBin && (c < '0' || c > '1'))
                jeSt = false;
            else if (jeHex && (c < '0' || (c > '9' && c < 'A') || c > 'F'))
                jeSt = false;
            else if (jeNic && (c < '0' || c > '7'))
                jeSt = false;
            else if (jeNum && (c < '0' || c > '9'))
                jeSt = false;

            c = getchar();
        }
        putchar(jeSt ? '1' : '0');
    }
    putchar('\n');

    return 0;
}
