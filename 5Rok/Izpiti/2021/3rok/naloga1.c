#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen("vhod.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");

    int v = 0;
    int index = 1;
    int counter = 1;
    while ((fscanf(vhod, "%d", &v)) != EOF)
    {
        if (index == counter)
        {
            fprintf(izhod, "%d\n", v);
            index += v;
        }
        counter++;
    }

    return 0;
}
