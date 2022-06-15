#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");
    long stevilo;
    long sum = 0;
    fscanf(vhod, "%ld", &stevilo);
    sum += stevilo;
    long counter = 1;
    fprintf(izhod, "%ld\n", stevilo);
    printf("%ld\n", stevilo);

    while (!feof(vhod))
    {
        counter++;
        fscanf(vhod, "%ld", &stevilo);
        if (counter - 1 == sum)
        {
            fprintf(izhod, "%ld\n", stevilo);

            printf("%ld\n", stevilo);
            sum += stevilo;
        }
    }
    if (counter - 1 == sum)
    {
        printf("%ld\n", stevilo);
    }

    return 0;
}
