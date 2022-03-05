#include <stdio.h>

int main(int argc, char const *argv[])
{
    int counter = 0, input;
    while ((input = getchar()) != EOF)
    {
        if (input == '\n')
            counter++;
    }
    printf("Number of lines is %d\n", counter);
    return 0;
}
