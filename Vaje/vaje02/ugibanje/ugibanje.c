#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, inp;
    scanf("%d %d", &a, &b);
    while (scanf("%d", &inp) != 0)
    {
        if (inp == 0)
            break;
        if (inp == 1) // Stevilo je vecje
            a = (a + b) / 2 + 1;
        // printf("Meji [%d,%d]\n", a, b);
        else if (inp == -1)
            b = (a + b) / 2 - 1;
        // printf("Meji [%d,%d]\n", a, b);
    }
    if (a == b)
        printf("%d\n", a);
    else if (a < b)
        printf("%d %d\n", a, b);
    else
        printf("PROTISLOVJE\n");
    return 0;
}
