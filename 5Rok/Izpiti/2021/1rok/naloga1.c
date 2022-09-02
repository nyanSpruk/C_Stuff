#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("datoteka.bin", "rb");
    int counter = 0;
    char znak;
    while ((znak = fgetc(vhod)) != EOF)
        counter++;
    printf("%d\n", counter == sizeof(long) ? 1 : 0);
    fclose(vhod);
    return 0;
}
