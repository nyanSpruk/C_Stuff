#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("vhod.bin", "rb");
    FILE *izhod = fopen("izhod.txt", "wb");
    int n = 6;
    int znak;
    while ((znak = fgetc(vhod)) != EOF)
    {
        printf("%02X\n", znak);
    }
    return 0;
}
