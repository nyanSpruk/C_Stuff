#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *read = fopen("vhod.bin", "rb");
    int n;
    long temp;
    n = fread(&temp, sizeof(long), 1, read);
    printf("%d\n", n);

    fclose(read);

    return 0;
}