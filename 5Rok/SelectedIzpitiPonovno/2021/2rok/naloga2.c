#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("datoteka.bin", "rb");
    int stevilo;
    int temp;
    bool nadaljuj;
    while ((temp = fgetc(vhod)) != EOF)
    {
        if (nadaljuj)
            stevilo = (stevilo << 7) | (temp >> 1);
        else
            stevilo = temp >> 1;

        nadaljuj = ((temp & 1) == 0) ? false : true;
        if (!nadaljuj)
            printf("%d\n", stevilo);
    }
    fclose(vhod);
    return 0;
}
