#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("test01.bin", "rb");
    char c;
    long long counter = 0;
    c = fgetc(vhod);
    while (!feof(vhod))
    {
        for (int i = 0; i < 8; i++)
        {
            if (c & 1)
            {
                counter++;
                c = c << 1;
            }
        }
        c = fgetc(vhod);
    }
    printf("%lld\n", counter);
    return 0;
}