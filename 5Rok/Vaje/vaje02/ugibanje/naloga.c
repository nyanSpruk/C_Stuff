#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    int input = 2;
    do
    {
        scanf("%d", &input);
        if (input == 1)
        {
            a = (a + b) / 2;
            a++;
        }
        else if (input == -1)
        {
            b = (a + b) / 2;
            b--;
        }
    } while (input != 0 && b >= a);

    if (a < b)
        printf("%d %d\n", a, b);
    else if (a == b)
        printf("%d\n", a);
    else
        printf("PROTISLOVJE\n");
    return 0;
}
