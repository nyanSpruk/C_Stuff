// Program from chapter 1.2

// This is a comment
/*
    This is a multiple line comment

    char - single byte
    short - short int
    int
    long - long int

    float
    double - double float

*/

#include <stdio.h>

int main()
{

    for (float fahr = 0; fahr <= 300; fahr += 20)
    {
        float result = (5 * (fahr - 32)) / 9;
        printf("%3.0f\t%6.1f\n", fahr, result);
    }

    int d = 16;
    printf("Number %d in hex is %04x\n", d, d);
    return 0;
}

/*
    USEFUL STUFF:
    %d - print as integer
    %6d - print as int; at least 6 chars wide
    %f - print as float
    %6f - print as float; at least 6 chars wide
    %.2f - print as float, 2 chars after decimal point
    %6.2f - print as float, at least 6 wide and 2 after decimal point


    AMONG OTHERS:
    %o - for octal numbers
    %x - for HEX
    %c - for char
    %s - for string
    %% - for itself
*/
