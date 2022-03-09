// c = getchar();
// Reads next char from a text stream and return its value
// putchar(c);
//  puts a char (value of char is in int) on the screen

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    printf("VALUE OF EOF %d\n", c);
    return 0;
}
