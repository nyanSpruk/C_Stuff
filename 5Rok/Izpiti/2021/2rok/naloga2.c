#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    FILE *vhod = fopen("datoteka.bin", "rb");
    // FILE *create = fopen("datoteka.bin", "wb");
    // int val[5] = {
    //     2,
    //     15,
    //     137, 128, 128};
    // for (int i = 0; i < 5; i++)
    // {
    //     fwrite(&val[i], sizeof(int), 1, create);
    // }

    int znak;
    bool nadaljuj;
    int st;
    while (fread(&znak, 1, sizeof(unsigned char), vhod) != EOF)
    {
        if (nadaljuj)
            stevilo = (stevilo << 7) | (znak >> 1);
        else
            stevilo = znak >> 1;

        if (!nadaljuj)
        {
            printf("%d\n", stevilo);
            stevilo = 0;
        }
    }
    return 0;
}
