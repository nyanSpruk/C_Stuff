#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int a = 1; a < 1000; a++)
    {
        for (int b = a; b < 1000; b++)
        {
            for (int c = b; c < 1000; c++)
            {
                if (a + b + c == 1000)
                {
                    if (a * a + b * b == c * c)
                    {
                        printf("A:%d, B:%d,C:%d, %d\n", a, b, c, (a * b * c));
                    }
                }
            }
        }
    }

    return 0;
}