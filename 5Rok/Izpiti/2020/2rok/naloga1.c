#include <stdio.h>
#include <stdlib.h>

void odstraniDuplikate(FILE *vhod, FILE *izhod)
{
    char c;
    char prev = ' ';
    while ((c = getc(vhod)) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c != prev)
                fputc(c, izhod);
        }
        else
            fputc(c, izhod);
        prev = c;
    }
    fputc('\n', izhod);
}

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("vhod.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");

    odstraniDuplikate(vhod, izhod);
    fclose(vhod);
    fclose(izhod);
    return 0;
}
