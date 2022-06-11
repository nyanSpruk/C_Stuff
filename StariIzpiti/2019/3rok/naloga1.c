#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *vhod = malloc(sizeof(char) * 21);
    int n;
    char *izhod = malloc(sizeof(char) * 21);
    scanf("%s", vhod);
    scanf("%d", &n);
    scanf("%s", izhod);
    FILE *vhod_file = fopen(vhod, "rb");
    FILE *izhod_file = fopen(izhod, "w");
    unsigned char znak;
    for (int i = 0; i < n; i++)
    {
        fread(&znak, 1, 1, vhod_file);
        fprintf(izhod_file, "%02X\n", znak);
    }
    fclose(vhod_file);
    fclose(izhod_file);
    free(vhod);
    free(izhod);
    return 0;
}
